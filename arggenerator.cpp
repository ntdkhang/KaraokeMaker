#include "arggenerator.h"

ArgGenerator::ArgGenerator(QString input) {
    inputFileName = input;
}

ArgGenerator::ArgGenerator() {
    inputFileName = "";
}

void ArgGenerator::setVideoInputFileName(QString input) {
    inputFileName = input;
}

QStringList ArgGenerator::CreateText(QString text) {
    QStringList args;
    QString textOverlay = QString("drawtext=fontfile=/Library/Fonts/SF-Compact-Display-Regular.otf:text='%1':fontcolor=white:fontsize=24:box=1:boxcolor=black@0.5:boxborderw=5:x=(w-text_w)/2:y=(h-text_h)/2").arg(text);
    QString output = "/Users/dk/Downloads/testOutput.mp4";

    args    << "-y"
            << "-i"
            << inputFileName
            << "-vf"
            << textOverlay
            << "-codec:a"
            << "copy"
            << output;

    return args;
}


QStringList ArgGenerator::AddNewAudio(QString videoFileName, QString audioFileName, QString outputFileName) {
    QStringList args;
    // ffmpeg -i v.mp4 -i a.wav -c:v copy -map 0:v:0 -map 1:a:0 new.mp4
    args    << "-y"
            << "-i"
            << videoFileName
            << "-i"
            << audioFileName
            << "-c:v"
            << "copy"
            << "-map"
            << "0:v:0"
            << "-map"
            << "1:a:0"
            << outputFileName;

    nonVocalVideoFileName = outputFileName;
    return args;
}

QStringList ArgGenerator::BurnSubtitle(QString subtitleFileName, QString outputFileName) {
    QStringList args;
    QString subArg = QString("subtitles=%1:force_style='Fontname=DejaVu Serif,FontSize=50'").arg(subtitleFileName);

    // ffmpeg -i video.avi -vf subtitles=subtitle.srt out.avi
    args    << "-y"
            << "-i"
            << nonVocalVideoFileName
            << "-vf"
            << subArg
            << outputFileName;

    return args;
}

QStringList ArgGenerator::SeparateAudioAndVideo() {
    // ffmpeg -i vid.avi -map 0:a audio.wav -map 0:v onlyvideo.avi
    QStringList args;

    args    << "-y"
            << "-i"
            << inputFileName
            << "-map"
            << "0:a"
            << "audio.mp3"
            << "-map"
            << "0:v"
            << "video.mp4";

    // qInfo() << args;
    return args;
}

QStringList ArgGenerator::SeparateVocal(QString audioFileName) {
    QStringList args;
    args        << "-m" << "demucs.separate"
                << "-n" << "htdemucs"
                << "--mp3" << "--mp3-bitrate=320"
                << "--two-stems=vocals"
                << audioFileName;
    return args;
}
