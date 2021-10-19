#ifndef THREAD_ENSAMBLADORA_HORNO_H
#define THREAD_ENSAMBLADORA_HORNO_H

#include <QtCore>
#include <QMutex>
#include <QDebug>
#include <QCheckBox>

#include "main_struct.h"

class ThreadEnsambladoraHorno:public QThread
{
public:
    //data
    QMutex * mutexMachineEnsambladora;
    QMutex * mutexEnsambladoraHorno;
    Ensambladora * ensambladora;
    Horno * horno;
    Receta * receta;

    EstructuraProgressBar * progressBar;
    QCheckBox * checkOnOff;

     //propios
    bool running;
    bool paused;

    ThreadEnsambladoraHorno();
    void __init__(QMutex *mutex1,QMutex *mutex2, Ensambladora * ensambladora, Horno * horno, Receta * receta,EstructuraProgressBar * progressBar, QCheckBox * checkOnOff);
    void run();
    void stop();
    void pause();
    void resume();
};

#endif // THREAD_ENSAMBLADORA_HORNO_H
