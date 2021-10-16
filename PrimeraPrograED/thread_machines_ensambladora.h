#ifndef THREAD_MACHINES_ENSAMBLADORA_H
#define THREAD_MACHINES_ENSAMBLADORA_H

#include <QtCore>
#include <QMutex>
#include <QDebug>
#include "main_struct.h"

#include <QLabel>
class ThreadMachinesEnsambladora: public QThread{
public:
    ThreadMachinesEnsambladora();

    Machine * machine;
    Ensambladora * ensambladora;
    ColaPeticiones * colaPeticiones;
    QMutex * mutex;
    QLabel * label;
    QLabel *lbCola;

    QLabel * arraylbDatosMachines[3];
    bool running;
    bool paused;

    void __init__(Machine * machine, ColaPeticiones * colaPeticiones, Ensambladora * ensambladora, QMutex * mutex, QLabel * label, QLabel *lbCola, QLabel * arraylbDatosMachines[6]);
    void run();
    void stop();
    void pause();
    void resume();


};

#endif // THREAD_MACHINES_ENSAMBLADORA_H
