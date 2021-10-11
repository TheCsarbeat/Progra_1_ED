#ifndef MAIN_THREAD_H
#define MAIN_THREAD_H

#include<QtCore>
#include <QDebug>
#include <QFrame>
#include <QMainWindow>

#include "main_struct.h"
#include "thread_almacen_machines.h"


#include <QLabel>
#include <QObject>


class thread_main :public QThread {
public:

    thread_main();
    //Variables propias
    Main_Struct * mainStruct;
    bool running;
    bool paused;


    //Label de cada elemento
    QMainWindow* ui;
    //Sub hilos
    ThreadAlmacenMachines * hiloCarritoMachines[3];

    void escribirTexto(const QString &name);

    void __init__(Main_Struct * mainStruct,QMainWindow* ui);
    void run();
    void stop();
    void pause();
    void resume();

signals:
    void enviarTexto(QString);



};


#endif // MAIN_THREAD_H
