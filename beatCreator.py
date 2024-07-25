import io
from pathlib import Path
import select
from shutil import rmtree
import subprocess as sp
import sys
from typing import Dict, Tuple, Optional, IO

model = "htdemucs_ft"
extension = ["mp3"]
two_stems = "vocals" # Separate vocal and beat

# Options for the output audio.
mp3 = True
mp3_rate = 320



def find_files(in_path):
    out = []
    for file in Path(in_path).iterdir():
        if file.suffix.lower().lstrip(".") in extension:
            out.append(file)
    return out

def copy_process_streams(process: sp.Popen):
    def raw(stream):
        assert stream is not None
        if isinstance(stream, io.BufferedIOBase):
            stream = stream.raw
        return stream

    p_stdout, p_stderr = raw(process.stdout), raw(process.stderr)
    stream_by_fd = {
        p_stdout.fileno(): (p_stdout, sys.stdout),
        p_stderr.fileno(): (p_stderr, sys.stderr),
    }
    fds = list(stream_by_fd.keys())

    while fds:
        # `select` syscall will wait until one of the file descriptors has content.
        ready, _, _ = select.select(fds, [], [])
        for fd in ready:
            p_stream, std = stream_by_fd[fd]
            raw_buf = p_stream.read(2 ** 16)
            if not raw_buf:
                fds.remove(fd)
                continue
            buf = raw_buf.decode()
            std.write(buf)
            std.flush()

def separate(inp=None, outp=None):
    inp = inp
    outp = outp
    cmd = ["python3.11", "-m", "demucs.separate", "-n", model]
    if mp3:
        cmd += ["--mp3", f"--mp3-bitrate={mp3_rate}"]
    if two_stems is not None:
        cmd += [f"--two-stems={two_stems}"]

    files = [str(f) for f in find_files(inp)]
    if not files:
        print(f"No valid audio files in {inp}")
        return
    print("Going to separate the files:")
    print('\n'.join(files))
    print("With command: ", " ".join(cmd))
    # print(cmd + files)
    p = sp.Popen(cmd + files, stdout=sp.PIPE, stderr=sp.PIPE)
    # copy_process_streams(p)
    p.wait()
    # if p.returncode != 0:
        # print("Command failed, something went wrong.")


separate("/Users/dk/Documents/Dev/Learning/Qt/KaraokeMaker/music/", "/Users/dk/Documents/Dev/Learning/Qt/KaraokeMaker/music_separated/")

# import demucs.separate
#
# demucs.separate.main(["--mp3", "--two-stems", "vocals", "-n", "htdemucs_ft", "/Users/dk/Documents/Dev/Learning/Qt/KaraokeMaker/music/0_ai_nghi.mp3"])
