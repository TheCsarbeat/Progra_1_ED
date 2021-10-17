#include "main_thread.h"

thread_main::thread_main(){

}

void thread_main::__init__(MainStruct * mainStruct, QFrame *mainPanel, QLabel * lbCarro, QLabel * arraylbMachines[6], QLabel *lbCola) {
    this->mainStruct = mainStruct;
    this->running = false;
    this->paused = false;
    this->mainPanel = mainPanel;
    this->lbCarro = lbCarro;
    this->arraylbMachines[0] = arraylbMachines[0];
    this->arraylbMachines[1] = arraylbMachines[1];
    this->arraylbMachines[2] = arraylbMachines[2];
    this->arraylbMachines[3] = arraylbMachines[3];
    this->arraylbMachines[4] = arraylbMachines[4];
    this->arraylbMachines[5] = arraylbMachines[5];
    this->lbCola = lbCola;
}

void thread_main::run() {
    this->running = true;
    QMutex *mutexMachinesCarrito = new QMutex;
    QMutex *mutexMachinesEnsabladora = new QMutex;
    ColaPeticiones * colaPeticiones = new ColaPeticiones();
    int corrida = 0;

    while (running) {
        while (paused) {
            sleep(1);
        }
        for(int i= 0; i<3; i++){
                int cantNow = mainStruct->arrayMachine->array[i]->cantNow;
                int cantMin = mainStruct->arrayMachine->array[i]->min;
                int cantMax = mainStruct->arrayMachine->array[i]->max;
                bool flagEncolado = mainStruct->arrayMachine->array[i]->flagEncolado;
                bool flagProcesando = mainStruct->arrayMachine->array[i]->flagProcesando;

            if(cantNow <= cantMin && flagEncolado == false && flagProcesando == false){
                colaPeticiones->encolar(mainStruct->arrayMachine->array[i]->nombre, cantMax-cantNow, i);
                mainStruct->arrayMachine->array[i]->flagEncolado = true;
            }

            msleep(500);
        }



        bool libreCarrito = mainStruct->almacen->carrito->libre;
        if(!colaPeticiones->vacia() && libreCarrito == true){
            Peticion * peticion = colaPeticiones->verFrente()->peticion;

            corrida++;
            hiloCarritoMachines[peticion->idMachine] = new ThreadAlmacenMachines();
            hiloCarritoMachines[peticion->idMachine]->__init__(mainStruct->almacen, mainStruct->arrayMachine->array[peticion->idMachine], mutexMachinesCarrito,this->lbCarro, colaPeticiones, lbCola,
                    arraylbMachines);
            hiloCarritoMachines[peticion->idMachine]->start();

            msleep(500);
        }

        for(int i= 0; i<3; i++){
                int cantNow = mainStruct->arrayMachine->array[i]->cantNow;
                int cantMin = mainStruct->arrayMachine->array[i]->min;
                /*int cantMax = mainStruct->arrayMachine->array[i]->max;
                bool flagEncolado = mainStruct->arrayMachine->array[i]->flagEncolado;*/
                bool flagProcesando = mainStruct->arrayMachine->array[i]->flagProcesando;

            if(cantNow >= cantMin && flagProcesando == false){
                mainStruct->arrayMachine->array[i]->flagProcesando = true;
                qDebug()<<"\n*****************";
                qDebug()<<"Nombre"<<mainStruct->arrayMachine->array[i]->nombre;
                qDebug()<<"Cantidad actual "<<mainStruct->arrayMachine->array[i]->cantNow;
                qDebug()<<"Cantidad minima "<<mainStruct->arrayMachine->array[i]->min;
                qDebug()<<"*****************\n";

                hiloMachinesEnsambladora[i] = new ThreadMachinesEnsambladora();
                hiloMachinesEnsambladora[i]->__init__(mainStruct->arrayMachine->array[i], colaPeticiones, mainStruct->ensambladora, mutexMachinesEnsabladora,arraylbMachines[i], lbCola, arraylbMachines);
                hiloMachinesEnsambladora[i]->start();
            }else{
                bool flagHiloStop = true;
            }

            msleep(500);
        }



        msleep(100);
    }

}

void thread_main::pause() {
    this->paused = true;
}

void thread_main::stop() {
    this->running = false;
}

void thread_main::resume() {
    this->paused = false;
}
