#include "thread_almacen_machines.h"

ThreadAlmacenMachines::ThreadAlmacenMachines(){

}

void ThreadAlmacenMachines::__init__(Almacen * almacen, ArrayMachines * machines, QMutex * mutex, ColaPeticiones * colaPeticiones,EstructuraProgressBar * progressBar, QCheckBox * checkOnOff) {
    this->almacen = almacen;
    this->running = false;
    this->state = true;
    this->paused = false;
    this->mutex = mutex;
    this->machines = machines;
    this->colaPeticiones= colaPeticiones;
    this->progressBar = progressBar;
    this->checkOnOff = checkOnOff;
}

void ThreadAlmacenMachines::run() {

    this->running = true;

    this->paused=true;

    //almacen->carrito->imprimir();
    almacen->carrito->lbDatos->setText("Carga: "+QString::number(almacen->carrito->cargaNow)
                     +"\nTotal entregada: "+QString::number(almacen->carrito->materiaPrimaEntregada));
    while (running) {
        this->almacen->carrito->libre = true;
        while (paused) {

            if(!colaPeticiones->vacia() && this->almacen->carrito->libre == true  && checkOnOff->isChecked() && this->almacen->carrito->estado){
                machine = machines->array[colaPeticiones->verFrente()->peticion->idMachine];
                this->almacen->carrito->libre = false;
                resume();                
            }

            msleep(500);
        }
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
                pause();
            }



    }

}

void ThreadAlmacenMachines::pause() {
    this->paused = true;
    this->almacen->carrito->lbTitulo->setText("Waiting...");
    colaPeticiones->imprimir();
    machine->imprimirDatos();
    almacen->carrito->imprimir();
    if(colaPeticiones->vacia())checkOnOff->setChecked(false);
}

void ThreadAlmacenMachines::stop() {
    this->running = false;

    colaPeticiones->imprimir();
    machine->imprimirDatos();
    almacen->carrito->imprimir();   
    if(colaPeticiones->vacia())checkOnOff->setChecked(false);
    //destroyed();
}

void ThreadAlmacenMachines::resume() {
    this->paused = false;

    this->almacen->carrito->libre = false;

    this->mutex->lock();
    getCantPeticion();
    this->mutex->unlock();

    almacen->carrito->imprimir();

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
    this->almacen->carrito->imprimir();
    this->progressBar->setValue(0);

    //Code
    this->almacen->carrito->libre = true;
    this->almacen->carrito->timeActual = 0;
    this->almacen->carrito->cargaNow=0;
}
