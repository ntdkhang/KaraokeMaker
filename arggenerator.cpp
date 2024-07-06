#include "arggenerator.h"

ArgGenerator::ArgGenerator(QString input) {
    inputFile = input;
}

void ArgGenerator::CreateText(QString text) {
    args.clear();
    QString textOverlay = QString("drawtext=fontfile=/Library/Fonts/SF-Compact-Display-Regular.otf:text='%1':fontcolor=white:fontsize=24:box=1:boxcolor=black@0.5:boxborderw=5:x=(w-text_w)/2:y=(h-text_h)/2").arg(text);
    QString output = "/Users/dk/Downloads/testOutput.mp4";

    args    << "-i"
            << inputFile
            << "-vf"
            << textOverlay
            << "-codec:a"
            << "copy"
            << output;
}


QStringList ArgGenerator::getArgs() {
    return args;
}
