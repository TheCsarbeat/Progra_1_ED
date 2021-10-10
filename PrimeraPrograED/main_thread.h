#ifndef MAIN_THREAD_H
#define MAIN_THREAD_H

#include<QtCore>
#include <QDebug>
#include <QFrame>

#include "main_struct.h"
#include "thread_almacen_machines.h"


#include <QLabel>


class thread_main :public QThread {
public:

    thread_main();
    //Variables propias
    Main_Struct * mainStruct;
    QFrame * mainPanel;
    bool running;
    bool paused;


    //Label de cada elemento
    QLabel * lbCarro;
    //Sub hilos
    ThreadAlmacenMachines * hiloCarritoMachines[3];

    void __init__(Main_Struct * mainStruct, QFrame *mainPanel, QLabel * lbCarro);
    void run();
    void stop();
    void pause();
    void resume();

};


#endif // MAIN_THREAD_H
