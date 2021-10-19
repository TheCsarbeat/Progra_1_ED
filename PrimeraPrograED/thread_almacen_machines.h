#ifndef THREAD_ALMACEN_MACHINES_H
#define THREAD_ALMACEN_MACHINES_H

#include <QtCore>
#include <QMutex>
#include <QDebug>
#include <QCheckBox>

#include "main_struct.h"



#include <QLabel>

class ThreadAlmacenMachines :public QThread {
public:
    ThreadAlmacenMachines();
    Almacen * almacen;
    Machine * machine;
    QMutex * mutex;

    ColaPeticiones * colaPeticiones;

    EstructuraProgressBar * progressBar;
    QCheckBox * checkOnOff;
    bool running;
    bool paused;

    void __init__(Almacen * almacen, Machine * machine,QMutex *mutex, ColaPeticiones * colaPeticiones,EstructuraProgressBar * progressBar, QCheckBox * checkOnOff);
    void run();
    void stop();
    void pause();
    void resume();
    void getCantPeticion();
    void updateData();
    void resetDatos();

};

#endif // THREAD_ALMACEN_MACHINES_H
