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

    QStringList AddNewAudio(QString videoFileName = "video.mp4", QString audioFileName = "./separated/htdemucs/audio/no_vocals.mp3", QString outputFileName = "outputNoSub.mp4");

    void setVideoInputFileName(QString input);

    const QString ffmpeg = "/usr/local/Cellar/ffmpeg/7.0.1/bin/ffmpeg";
    const QString python = "/usr/local/Cellar/python@3.11/3.11.7_1/Frameworks/Python.framework/Versions/3.11/Resources/Python.app/Contents/MacOS/Python";

private:
    QString inputFileName;
    QString newAudioVideoFileName;
};

#endif // ARGGENERATOR_H
