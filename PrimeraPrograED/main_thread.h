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


#include <QLabel>
#include <QCheckBox>


class thread_main :public QThread {
public:

    thread_main();
    //Variables propias
    MainStruct * mainStruct;
    QFrame * mainPanel;

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

    //Mutex
    QMutex *mutexCarritoMachines;
    QMutex *mutexMachinesEnsambladora;
    QMutex *mutexEnsambladoraHorno;

    void __init__(MainStruct * mainStruct, QFrame *mainPanel, EstructuraProgressBar * arrayProgressBar[40], QCheckBox * checkOnOff[40]);
    void run();
    void stop();
    void pause();
    void resume();

    void encolar();
    void arrancarCarrito();
    void arrancarMezcladoras();
    void arrancarEnsambladora();

    void imprimirDatos();

};


#endif // MAIN_THREAD_H
