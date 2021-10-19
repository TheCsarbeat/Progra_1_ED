#ifndef THREAD_ENSAMBLADORA_HORNO_H
#define THREAD_ENSAMBLADORA_HORNO_H

#include <QtCore>
#include <QMutex>
#include <QDebug>
#include "main_struct.h"


#include <QLabel>

class ThreadEnsambladoraHorno:public QThread
{
public:
    //data
    QMutex * mutex;
    Ensambladora * ensambladora;
    Horno * horno;
    Receta * receta;

    //ui
    QLabel * arrayLbEnsambladora[4];

    //propios
    bool running;
    bool paused;

    ThreadEnsambladoraHorno();
    void __init__(QMutex *mutex, Ensambladora * ensambladora, Horno * horno, Receta * receta, QLabel * arrayLbEnsambladora[4]);
    void run();
    void stop();
    void pause();
    void resume();
};

#endif // THREAD_ENSAMBLADORA_HORNO_H
