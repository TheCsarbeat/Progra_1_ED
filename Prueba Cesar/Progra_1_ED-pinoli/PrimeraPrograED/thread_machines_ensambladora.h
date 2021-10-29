#ifndef THREAD_MACHINES_ENSAMBLADORA_H
#define THREAD_MACHINES_ENSAMBLADORA_H

#include <QtCore>
#include <QMutex>
#include <QDebug>
#include "main_struct.h"

#include <QLabel>
#include <QCheckBox>
class ThreadMachinesEnsambladora: public QThread{
public:
    ThreadMachinesEnsambladora();

    Machine * machine;
    Ensambladora * ensambladora;
    ColaPeticiones * colaPeticiones;
    QMutex * mutexCarritoMachine;
    QMutex * mutexMachineEnsambladora;

    EstructuraProgressBar * progressBar;
    QCheckBox * checkOnOff;

    bool running;
    bool paused;

    void __init__(Machine * machine, ColaPeticiones * colaPeticiones, Ensambladora * ensambladora, QMutex * mutexCarritoMa, QMutex * mutexEnsam, EstructuraProgressBar * progressBar, QCheckBox * checkOnOff);
    void run();
    void stop();
    void pause();
    void resume();
    void resetDatos();


};

#endif // THREAD_MACHINES_ENSAMBLADORA_H
