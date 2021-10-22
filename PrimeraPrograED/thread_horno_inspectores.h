#ifndef THREAD_HORNO_INSPECTORES_H
#define THREAD_HORNO_INSPECTORES_H


#include <QtCore>
#include <QMutex>
#include <QDebug>
#include <QCheckBox>

#include "main_struct.h"

class ThreadHornoInspectores:public QThread
{
public:
    //data
    QMutex * mutexHornoInspectores;
    QMutex * mutexEnsambladoraHorno;
    Horno * horno;
    Inspectores * inspectores;

    EstructuraProgressBar * progressBar;
    QCheckBox * checkOnOff;

     //propios
    bool running;
    bool paused;

    ThreadHornoInspectores();
    void __init__(QMutex *mutex1,QMutex *mutex2, Horno * horno, Inspectores * inspectores, EstructuraProgressBar * progressBar, QCheckBox * checkOnOff);
    void run();
    void stop();
    void pause();
    void resume();
};

#endif // THREAD_HORNO_INSPECTORES_H
