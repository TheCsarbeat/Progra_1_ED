#ifndef THREAD_COLA_PETICIONES_H
#define THREAD_COLA_PETICIONES_H

#include <QLabel>
#include <QMutex>
#include <QtCore>
#include <QDebug>

#include "main_struct.h"

class ThreadColaPeticiones:public QThread {
public:
    ThreadColaPeticiones();
    //attributes
    Almacen * almacen;
    bool * flagCarritoProcesando;
    bool * flagCarritoEncolado;
    bool * running;
    ColaPeticiones * colaPeticiones;

    //ui attributes

    void __init__(Almacen * almacen, bool * flagCarritoProcesando, bool * flagCarritoEncolado, ColaPeticiones * colaPeticiones);
    void run();
    void stop();
    void pause();
    void resume();
};

#endif // THREAD_COLA_PETICIONES_H
