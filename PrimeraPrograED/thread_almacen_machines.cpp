#include "thread_almacen_machines.h"

ThreadAlmacenMachines::ThreadAlmacenMachines(){

}

void ThreadAlmacenMachines::__init__(Almacen * almacen, Machine * machine, QMutex * mutex, ColaPeticiones * colaPeticiones,EstructuraProgressBar * progressBar, QCheckBox * checkOnOff) {
    this->almacen = almacen;
    this->running = false;
    this->paused = false;
    this->mutex = mutex;
    this->machine = machine;
    this->colaPeticiones= colaPeticiones;
    this->progressBar = progressBar;
    this->checkOnOff = checkOnOff;
}

void ThreadAlmacenMachines::run() {

    this->running = true;
    this->almacen->carrito->libre = false;
    getCantPeticion();
    almacen->carrito->imprimir();
    while (running) {
        while (paused) {
            if(checkOnOff->isChecked()) resume();
            msleep(500);
        }

        if(!checkOnOff->isChecked()) pause();
        else{

                //Own Statements
                this->almacen->carrito->sumarSegundo();
                this->almacen->carrito->lbTitulo->setText("Llevando a: "+this->machine->nombre);
                this->progressBar->setValue(((double)this->almacen->carrito->timeActual/this->almacen->carrito->duracionTotal)*100);
                sleep(1);

                //Stop Condition
                if(this->almacen->carrito->duracionTotal == this->almacen->carrito->timeActual){


                    this->mutex->lock();
                    this->machine->cantNow += this->almacen->carrito->cargaNow;
                    almacen->carrito->materiaPrimaEntregada += almacen->carrito->cargaNow;
                    if(colaPeticiones->verFrente()->peticion->cant == 0)colaPeticiones->desencolar();
                    this->mutex->unlock();
                    resetDatos();

                    //if(colaPeticiones->vacia())checkOnOff->setChecked(false);

                    stop();
                }


        }
    }

}

void ThreadAlmacenMachines::pause() {
    this->paused = true;
    this->almacen->carrito->lbTitulo->setText("Waiting...");
}

void ThreadAlmacenMachines::stop() {
    this->running = false;

    colaPeticiones->imprimir();
    machine->imprimirDatos();
    almacen->carrito->imprimir();

}

void ThreadAlmacenMachines::resume() {
    this->paused = false;
}

void ThreadAlmacenMachines::getCantPeticion(){

    Peticion * peticion = colaPeticiones->verFrente()->peticion;
    int cantPeticion = peticion->cant;
    int cargaCarrito = almacen->carrito->capacidad;
    colaPeticiones->imprimir();
    if(cantPeticion>= cargaCarrito){
        this->almacen->carrito->cargaNow = almacen->carrito->capacidad;
        peticion->cant = peticion->cant-cargaCarrito;
    }else{
        this->almacen->carrito->cargaNow = peticion->cant;
        peticion->cant = 0;
    }


}

void ThreadAlmacenMachines::resetDatos(){
    //Visuales
    this->almacen->carrito->lbTitulo->setText("Waiting...");
    almacen->carrito->imprimir();
    this->progressBar->setValue(0);

    //Code
    this->almacen->carrito->libre = true;
    this->almacen->carrito->timeActual = 0;
    this->almacen->carrito->cargaNow=0;
}
