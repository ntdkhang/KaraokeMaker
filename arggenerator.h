#ifndef ARGGENERATOR_H
#define ARGGENERATOR_H

#include <QtCore>

class ArgGenerator
{
public:
    ArgGenerator(QString input);

    void CreateText(QString text);

    QStringList getArgs();

private:
    QStringList args;
    QString inputFile;
};

#endif // ARGGENERATOR_H
