#ifndef THREAD_ALMACEN_MACHINES_H
#define THREAD_ALMACEN_MACHINES_H

#include <QtCore>
#include <QMutex>
#include <QDebug>
#include "main_struct.h"


#include <QLabel>

class ThreadAlmacenMachines :public QThread {
public:
    ThreadAlmacenMachines();
    Almacen * almacen;
    Machine * machine;
    QMutex * mutex;
    ColaPeticiones * colaPeticiones;

    QLabel * label;
    QLabel * lbCola;
    QLabel * arraylbDatosMachines[3];

    bool running;
    bool paused;

    void __init__(Almacen * almacen, Machine * machine,QMutex *mutex, QLabel * label, ColaPeticiones * colaPeticiones, QLabel *lbCola, QLabel * arraylbDatosMachines[6]);
    void run();
    void stop();
    void pause();
    void resume();

};

#endif // THREAD_ALMACEN_MACHINES_H
