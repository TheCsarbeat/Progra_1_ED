#ifndef MAIN_THREAD_H
#define MAIN_THREAD_H

#include<QtCore>
#include <QDebug>
#include <QFrame>

#include "main_struct.h"
#include "thread_almacen_machines.h"
#include "thread_machines_ensambladora.h"
#include "thread_ensambladora_horno.h"


#include <QLabel>


class thread_main :public QThread {
public:

    thread_main();
    //Variables propias
    MainStruct * mainStruct;
    QFrame * mainPanel;
    bool running;
    bool paused;


    //Label de cada elemento
    QLabel * lbCarro;
    QLabel * arraylbMachines[6];
    QLabel * lbCola;
    ColaPeticiones * colaPeticiones;

    QLabel * arrayLbEnsambladora[4];

    //Sub hilos
    ThreadAlmacenMachines * hiloCarritoMachines[3];
    ThreadMachinesEnsambladora * hiloMachinesEnsambladora[3];
    ThreadEnsambladoraHorno * hiloEnsambladoraHorno;

    //Mutex
    QMutex *mutexMachinesCarrito;
    QMutex *mutexMachinesEnsabladora;
    QMutex *mutexEnsambladoraHorno;

    void __init__(MainStruct * mainStruct, QFrame *mainPanel, QLabel * lbCarro, QLabel * arraylbMachines[3], QLabel * lbCola, QLabel * arrayLbEnsambladora[4]);
    void run();
    void stop();
    void pause();
    void resume();

    void encolar();
    void arrancarCarrito();
    void arrancarMezcladoras();
    void arrancarEnsambladora();

};


#endif // MAIN_THREAD_H
