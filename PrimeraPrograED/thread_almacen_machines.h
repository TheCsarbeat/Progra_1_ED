#ifndef THREAD_ALMACEN_MACHINES_H
#define THREAD_ALMACEN_MACHINES_H

#include <QtCore>
#include <QMutex>
#include <QDebug>
#include <QCheckBox>

#include "main_struct.h"




class ThreadAlmacenMachines :public QThread {
public:
    ThreadAlmacenMachines();
    Almacen * almacen;
    ArrayMachines * machines;
    QMutex * mutex;
    Machine* machine;

    ColaPeticiones * colaPeticiones;

    EstructuraProgressBar * progressBar;
    QCheckBox * checkOnOff;
    bool running;
    bool paused;
    bool state;

    void __init__(Almacen * almacen, ArrayMachines * machines,QMutex *mutex, ColaPeticiones * colaPeticiones,EstructuraProgressBar * progressBar, QCheckBox * checkOnOff);
    void run();
    void stop();
    void pause();
    void resume();
    void getCantPeticion();
    void resetDatos();

};

#endif // THREAD_ALMACEN_MACHINES_H
