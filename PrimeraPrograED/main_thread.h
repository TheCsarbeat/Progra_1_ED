#ifndef MAIN_THREAD_H
#define MAIN_THREAD_H

#include<QtCore>
#include <QDebug>
#include <QFrame>
#include <QProgressBar>
#include "main_struct.h"
#include "thread_almacen_machines.h"
#include "thread_machines_ensambladora.h"
#include "thread_ensambladora_horno.h"
#include "thread_horno_inspectores.h"


#include <QLabel>
#include <QCheckBox>


class thread_main :public QThread {
public:

    thread_main();
    //Variables propias
    MainStruct * mainStruct;
    bool running;
    bool paused;

    ColaPeticiones * colaPeticiones;

    //Array ProgressBar
    EstructuraProgressBar * arrayProgressBar[40];

    //CheckBox Elements
    QCheckBox * checkOnOff[40];

    //Sub hilos
    ThreadAlmacenMachines * hiloCarritoMachines;
    ThreadMachinesEnsambladora * hiloMachinesEnsambladora[3];
    ThreadEnsambladoraHorno * hiloEnsambladoraHorno;
    ThreadHornoInspectores * hiloHornoInspectores;

    //Mutex
    QMutex *mutexCarritoMachines;
    QMutex *mutexMachinesEnsambladora;
    QMutex *mutexEnsambladoraHorno;
    QMutex *mutexHornoInspectores;

    void __init__(MainStruct * mainStruct, EstructuraProgressBar * arrayProgressBar[40], QCheckBox * checkOnOff[40]);
    void run();
    void stop();
    void pause();
    void resume();

    void encolar();
    void arrancarHorno();
    void iniciarThreads();
    void calcularGalletas();

};


#endif // MAIN_THREAD_H
