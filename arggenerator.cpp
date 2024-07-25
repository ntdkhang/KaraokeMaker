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

QStringList ArgGenerator::BurnSubtitle(QString subtitleFileName) {
    QStringList args;
    QString output = "/Users/dk/Downloads/testOutput.mp4";

    // ffmpeg -i video.avi -vf subtitles=subtitle.srt out.avi
    args    << "-i"
            << inputFileName
            << "-vf"
            << "subtitles=sub.srt"
            << output;
    return args;
}

