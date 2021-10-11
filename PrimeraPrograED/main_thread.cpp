#include "main_thread.h"

thread_main::thread_main(){

}

void thread_main::__init__(Main_Struct * mainStruct, QFrame *mainPanel, QLabel * lbCarro, QLabel * arraylbMachines[5], QLabel *lbCola) {
    this->mainStruct = mainStruct;
    this->running = false;
    this->paused = false;
    this->mainPanel = mainPanel;
    this->lbCarro = lbCarro;
    this->arraylbMachines[0] = arraylbMachines[0];
    this->arraylbMachines[1] = arraylbMachines[1];
    this->arraylbMachines[2] = arraylbMachines[2];
    this->lbCola = lbCola;
    this->lbTotalChocolate = arraylbMachines[3];
    this->lbTotalMezcla = arraylbMachines[4];
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
            hiloCarritoMachines[peticion->idMachine]->__init__(mainStruct->almacen, mainStruct->arrayMachine->array[peticion->idMachine], mutexMachinesCarrito,this->lbCarro, colaPeticiones, lbCola, lbTotalChocolate, lbTotalMezcla);
            hiloCarritoMachines[peticion->idMachine]->start();

            msleep(500);
        }

        for(int i= 0; i<3; i++){
                int cantNow = mainStruct->arrayMachine->array[i]->cantNow;
                int cantMin = mainStruct->arrayMachine->array[i]->min;
                int cantMax = mainStruct->arrayMachine->array[i]->max;
                bool flagEncolado = mainStruct->arrayMachine->array[i]->flagEncolado;
                bool flagProcesando = mainStruct->arrayMachine->array[i]->flagProcesando;

            if(cantNow > cantMin){
                qDebug()<<"\n\nminima: "<<cantMin<<"  now: "<<cantNow<<"\n\n";
                hiloMachinesEnsambladora[i] = new ThreadMachinesEnsambladora();
                hiloMachinesEnsambladora[i]->__init__(mainStruct->arrayMachine->array[i], colaPeticiones, mainStruct->ensambladora, mutexMachinesEnsabladora,arraylbMachines[i], lbCola);
                hiloMachinesEnsambladora[i]->start();
            }

            msleep(500);
        }



        sleep(2);
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
