#ifndef THREAD_PRIMER_INSPECTORH_H
#define THREAD_PRIMER_INSPECTORH_H


#include <QtCore>
#include <QMutex>
#include <QDebug>
#include <QCheckBox>

#include "main_struct.h"

class ThreadPrimerInspector:public QThread
{
public:
    //data
    QMutex * mutexHornoInspector1;
    QMutex * mutexInspector1ToInspector2;
    Horno * horno;
    Inspectores * inspectores;
    Inspector * inspector;
    Empacadora * empacadora;

    EstructuraProgressBar * progressBar;
    QCheckBox * checkOnOff;

     //propios
    bool running;
    bool paused;

    ThreadPrimerInspector();
    void __init__(QMutex *mutex1,QMutex *mutex2, Horno * horno, Inspectores * inspectores,Inspector * inspector,Empacadora * empacadora, EstructuraProgressBar * progressBar, QCheckBox * checkOnOff);
    void run();
    void stop();
    void pause();
    void resume();
};

#endif // THREAD_PRIMER_INSPECTORH_H
