#ifndef THREAD_TRANSPORTADORES_ALMACEN_H
#define THREAD_TRANSPORTADORES_ALMACEN_H


#include <QtCore>
#include <QMutex>
#include <QDebug>
#include <QCheckBox>

#include "main_struct.h"
class ThreadTransportadoresAlmacen:public QThread{
public:
    ThreadTransportadoresAlmacen();

    //data
    QMutex * mutexEmpacadoraTransporte;
    QMutex * mutexInspectorEmpacadora;
    ArrayTransportadores * transportadores;
    Empacadora * empacadora;

    EstructuraProgressBar * progressBar;
    QCheckBox * checkOnOff;
    int i;

     //propios
    bool running;
    bool paused;
    bool waiting;
    bool esperarGalletas;


    void __init__(QMutex *mutex1, ArrayTransportadores * transportadores,int id,Empacadora * empacadora,  EstructuraProgressBar * progressBar, QCheckBox * checkOnOff);
    void run();
    void stop();
    void pause();
    void resume();

};

#endif // THREAD_TRANSPORTADORES_ALMACEN_H
