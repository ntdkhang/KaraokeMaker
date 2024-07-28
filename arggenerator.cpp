#include "arggenerator.h"
#include <string>

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

QStringList ArgGenerator::BurnSubtitle(QString subtitleFileName, QString output) {
    QStringList args;
    std::string sub = "subtitles=sub.srt:force_style='Fontname=DejaVu Serif,FontSize=50'";

    // ffmpeg -i video.avi -vf subtitles=subtitle.srt out.avi
    args    << "-i"
            << inputFileName
            << "-vf"
            << QString::fromStdString(sub)
            // << "\"subtitles=sub.srt:force_style=\'Fontname=DejaVu Serif,FontSize=50\'\""
            << output;
    return args;
}

