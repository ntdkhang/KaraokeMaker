#include "arggenerator.h"

ArgGenerator::ArgGenerator(QString input) {
    inputFileName = input;
}

QStringList ArgGenerator::CreateText(QString text) {
    QStringList args;
    QString textOverlay = QString("drawtext=fontfile=/Library/Fonts/SF-Compact-Display-Regular.otf:text='%1':fontcolor=white:fontsize=24:box=1:boxcolor=black@0.5:boxborderw=5:x=(w-text_w)/2:y=(h-text_h)/2").arg(text);
    QString output = "/Users/dk/Downloads/testOutput.mp4";

    args    << "-i"
            << inputFileName
            << "-vf"
            << textOverlay
            << "-codec:a"
            << "copy"
            << output;

    return args;
}

QStringList ArgGenerator::BurnSubtitle(QString subtitleFileName, QString outputFileName) {
    QStringList args;
    QString subArg = QString("subtitles=%1:force_style='Fontname=DejaVu Serif,FontSize=50'").arg(subtitleFileName);

    // ffmpeg -i video.avi -vf subtitles=subtitle.srt out.avi
    args    << "-i"
            << inputFileName
            << "-vf"
            << subArg
            << outputFileName;

    return args;
}

QStringList ArgGenerator::SeparateAudioAndVideo() {
    // ffmpeg -i vid.avi -map 0:a audio.wav -map 0:v onlyvideo.avi
    QStringList args;

    args    << "-i"
            << inputFileName
            << "-map"
            << "0:a"
            << "audio.mp3"
            << "-map"
            << "0:v"
            << "video.mp4";

    qInfo() << args;
    return args;
}
