#ifndef THREAD_EMPACADORA_TRANSPORTE_H
#define THREAD_EMPACADORA_TRANSPORTE_H

#include <QtCore>
#include <QMutex>
#include <QDebug>
#include <QCheckBox>

#include "main_struct.h"

class ThreadEmpacadoraTransporte:public QThread{
public:
    ThreadEmpacadoraTransporte();
    //data
    QMutex * mutexEmpacadoraTransporte;
    QMutex * mutexInspectorEmpacadora;
    QStringList listaPlanificaciones;
    Empacadora * empacadora;
     ArrayTransportadores * transportadores;





    EstructuraProgressBar * progressBar;
    QCheckBox * checkOnOff;

    int id;

     //propios
    bool running;
    bool paused;
    bool waiting;
    bool esperarGalletas;
    bool flagParando;


    void __init__(QMutex *mutex1,QMutex *mutex2, Empacadora * empacadora, ArrayTransportadores * transporte, EstructuraProgressBar * progressBar, QCheckBox * checkOnOff);
    void run();
    void stop();
    void pause();
    void resume();
    int* ordenarArray(int array[], int len);
};

#endif // THREAD_EMPACADORA_TRANSPORTE_H
