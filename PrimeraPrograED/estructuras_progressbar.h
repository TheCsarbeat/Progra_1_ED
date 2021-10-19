#ifndef ESTRUCTURAS_PROGRESSBAR_H
#define ESTRUCTURAS_PROGRESSBAR_H

#include <QLabel>
#include <QFrame>
#include <QDebug>


struct EstructuraProgressBar{

    EstructuraProgressBar(QFrame * frame, QLabel * lb);

    QFrame * progressBar;
    QLabel * lbProgress;

    void setValue(int value);

};

#endif // ESTRUCTURAS_PROGRESSBAR_H
