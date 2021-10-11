#include "main_thread.h"

thread_main::thread_main(){

}

void thread_main::escribirTexto(const QString &name){
    emit enviarTexto(name);
}

void thread_main::__init__(Main_Struct * mainStruct,QMainWindow* ui) {
    this->mainStruct = mainStruct;
    this->running = false;
    this->paused = false;
    this->ui = ui;
}

void thread_main::run() {
    this->running = true;

    QMutex *mutexMachinesCarrito = new QMutex;

    this->escribirTexto("Doggie");

    for(int i= 0; i<3; i++){
            int cantNow = mainStruct->arrayMachine->array[i]->cantNow;
            int cantMin = mainStruct->arrayMachine->array[i]->min;
            bool estadoDeLlenado = mainStruct->arrayMachine->array[i]->fillState;
            qDebug()<<"Cantidad actual "<<mainStruct->arrayMachine->array[i]->cantNow;
            qDebug()<<"Cantidad minima "<<mainStruct->arrayMachine->array[i]->min;

        if(cantNow < cantMin && estadoDeLlenado == false){
            hiloCarritoMachines[i] = new ThreadAlmacenMachines();
            hiloCarritoMachines[i]->__init__(mainStruct->almacen, mainStruct->arrayMachine->array[i], mutexMachinesCarrito,ui->centralWidget()->findChild<QFrame*>("panelMain")->findChild<QLabel*>("lbCarro"));
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
