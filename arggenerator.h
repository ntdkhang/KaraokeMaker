#ifndef ARGGENERATOR_H
#define ARGGENERATOR_H

#include <QtCore>

class ArgGenerator
{
public:
    ArgGenerator(QString input);

    QStringList CreateText(QString text);

    QStringList BurnSubtitle(QString subtitleFileName, QString outputFileName = "output.mp4");

    QStringList SeparateAudioAndVideo();

private:
    QString inputFileName;
};

#endif // ARGGENERATOR_H
