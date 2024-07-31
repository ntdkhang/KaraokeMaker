#ifndef ARGGENERATOR_H
#define ARGGENERATOR_H

#include <QtCore>

class ArgGenerator
{
public:
    ArgGenerator(QString input);
    ArgGenerator();

    QStringList CreateText(QString text);

    QStringList BurnSubtitle(QString subtitleFileName, QString outputFileName = "output.mp4");

    QStringList SeparateAudioAndVideo();

    QStringList SeparateVocal(QString audioFileName = "audio.mp3");

    QStringList AddNewAudio(QString videoFileName = "video.mp4", QString audioFileName = "audio.mp3", QString outputFileName = "outputNoSub.mp4");

    void setVideoInputFileName(QString input);

private:
    QString inputFileName;
};

#endif // ARGGENERATOR_H
