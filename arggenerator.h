#ifndef ARGGENERATOR_H
#define ARGGENERATOR_H

#include <QtCore>

class ArgGenerator
{
public:
    ArgGenerator(QString input);

    QStringList CreateText(QString text);

    QStringList BurnSubtitle(QString subtitleFileName, QString output = "output.mp4");

private:
    QString inputFileName;
};

#endif // ARGGENERATOR_H
