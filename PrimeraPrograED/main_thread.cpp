#include "main_thread.h"

thread_main::thread_main(){

}

void thread_main::__init__(Main_Struct * mainStruct,QFrame *mainPanel, QLabel * lbCarro) {
    this->mainStruct = mainStruct;
    this->running = false;
    this->paused = false;
    this->mainPanel = mainPanel;
    this->lbCarro = lbCarro;
}

void thread_main::run() {
    this->running = true;

    QMutex *mutexMachinesCarrito = new QMutex;

    for(int i= 0; i<3; i++){
            int cantNow = mainStruct->arrayMachine->array[i]->cantNow;
            int cantMin = mainStruct->arrayMachine->array[i]->min;
            bool estadoDeLlenado = mainStruct->arrayMachine->array[i]->fillState;
            qDebug()<<"Cantidad actual "<<mainStruct->arrayMachine->array[i]->cantNow;
            qDebug()<<"Cantidad minima "<<mainStruct->arrayMachine->array[i]->min;

        if(cantNow < cantMin && estadoDeLlenado == false){
            hiloCarritoMachines[i] = new ThreadAlmacenMachines();
            hiloCarritoMachines[i]->__init__(mainStruct->almacen, mainStruct->arrayMachine->array[i], mutexMachinesCarrito,this->lbCarro);
            hiloCarritoMachines[i]->start();
        }
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
