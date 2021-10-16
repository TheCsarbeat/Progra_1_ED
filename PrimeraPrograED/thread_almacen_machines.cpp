#include "thread_almacen_machines.h"

ThreadAlmacenMachines::ThreadAlmacenMachines(){

}

void ThreadAlmacenMachines::__init__(Almacen * almacen, Machine * machine, QMutex * mutex, QLabel * label, ColaPeticiones * colaPeticiones, QLabel * lbCola, QLabel * arraylbDatosMachines[6]) {
    this->almacen = almacen;
    this->running = false;
    this->paused = false;
    this->mutex = mutex;
    this->machine = machine;
    this->label = label;
    this->colaPeticiones= colaPeticiones;
    this->lbCola =lbCola;
    this->arraylbDatosMachines[0] = arraylbDatosMachines[3];
    this->arraylbDatosMachines[1] = arraylbDatosMachines[4];
    this->arraylbDatosMachines[2] = arraylbDatosMachines[5];

}

void ThreadAlmacenMachines::run() {
    this->mutex->lock();
    this->running = true;
    Peticion * peticion = colaPeticiones->verFrente()->peticion;



    this->lbCola->setText(colaPeticiones->toString());
    this->machine->flagEncolado= true;
    this->almacen->carrito->libre = false;

    int cantPeticion = peticion->cant;
    int cargaCarrito = almacen->carrito->capacidad;
    if(cantPeticion>= cargaCarrito){
        this->almacen->carrito->cargaNow = almacen->carrito->capacidad;
        peticion->cant = peticion->cant-cargaCarrito;
    }else{
        this->almacen->carrito->cargaNow = peticion->cant;
        peticion->cant = 0;
    }


    while (running) {
        while (paused) {
            sleep(1);
        }

        this->almacen->carrito->sumarSegundo();

        this->label->setText(QString::number(this->almacen->carrito->timeActual)+" de "+QString::number(this->almacen->carrito->duracionTotal)
                             +" segundos para llegar a la "+this->machine->nombre);

        sleep(1);
        if(this->almacen->carrito->duracionTotal == this->almacen->carrito->timeActual){
            this->machine->cantNow += this->almacen->carrito->cargaNow;
            stop();
        }

    }
    this->mutex->unlock();
}

void ThreadAlmacenMachines::pause() {
    this->paused = true;
}

void ThreadAlmacenMachines::stop() {


    this->almacen->carrito->libre = true;
    this->almacen->carrito->timeActual = 0;
    this->running = false;

    NodoPeticion * listo = colaPeticiones->verFrente();

    if(listo->peticion->cant == 0){
        colaPeticiones->desencolar();
        this->machine->flagEncolado= false;
    }


    this->lbCola->setText(colaPeticiones->toString());

    this->arraylbDatosMachines[this->machine->id]->setText(+"\n cantidad Actual: "+QString::number(machine->cantNow)
                                                           +"\n Min: "+QString::number(machine->min)
                                                           +"\n Max: "+QString::number(machine->max));
}

void ThreadAlmacenMachines::resume() {
    this->paused = false;
}
