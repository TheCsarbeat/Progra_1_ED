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
    this->colaPeticiones = colaPeticiones;
    this->progressBar = progressBar;
    this->checkOnOff = checkOnOff;
}

void ThreadAlmacenMachines::run() {

    this->running = true;

    this->paused=true;


    //almacen->carrito->imprimir();
    almacen->carrito->lbDatos->setText("Carga: "+QString::number(almacen->carrito->cargaNow)
                                       +"\nChocolate entregado: "+QString::number(almacen->carrito->chocoTotal)
                                       +"\nMezcla entregada: "+QString::number(almacen->carrito->mezclaTotal));

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
            msleep(this->almacen->carrito->sleepTime);

            //Stop Condition
            if(this->almacen->carrito->duracionTotal == this->almacen->carrito->timeActual){
                this->mutex->lock();
                this->machine->cantNow += this->almacen->carrito->cargaNow;
                if(machine->nombre == "Chocolatera"){
                    almacen->carrito->chocoTotal += almacen->carrito->cargaNow;
                }else{
                    almacen->carrito->mezclaTotal += almacen->carrito->cargaNow;
                }
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

    almacen->carrito->lbDatos->setText("Carga: "+QString::number(almacen->carrito->cargaNow)
                                       +"\nChocolate entregado: "+QString::number(almacen->carrito->chocoTotal)
                                       +"\nMezcla entregada: "+QString::number(almacen->carrito->mezclaTotal));
    this->mutex->lock();
    if(colaPeticiones->vacia())checkOnOff->setChecked(false);
    this->mutex->unlock();
    if(almacen->carrito->chocoTotal == almacen->totalChocolate && almacen->carrito->mezclaTotal == almacen->totalMezcla)stop();
}

void ThreadAlmacenMachines::stop() {
    this->paused = false;
    this->running = false;
}

void ThreadAlmacenMachines::resume() {
    this->paused = false;
    this->almacen->carrito->libre = false;
    this->mutex->lock();
    almacen->carrito->idMachine = machine->id;
    getCantPeticion();
    this->mutex->unlock();
    almacen->carrito->imprimir();

}

void ThreadAlmacenMachines::getCantPeticion(){

    Peticion * peticion = colaPeticiones->verFrente()->peticion;

    int cargaCarrito = almacen->carrito->capacidad;
    /*int diferencia =0;
    if(peticion->idMachine == 2)
        diferencia = almacen->totalChocolate - almacen->carrito->chocoTotal;
    else
        diferencia = almacen->totalMezcla - almacen->carrito->mezclaTotal;

    if(diferencia>=almacen->carrito->capacidad)encolarNormal(peticion, cargaCarrito);
    else{
        if(diferencia == 0){
            almacen->carrito->libre = true;
            paused = true;
        }else
            almacen->carrito->cargaNow = diferencia;
        colaPeticiones->desencolar();
        machine->aviableEncolar= false;
    }*/
    encolarNormal(peticion, cargaCarrito);
    colaPeticiones->imprimir();
}

void ThreadAlmacenMachines::encolarNormal(Peticion * peticion, int cargaCarrito){
    if(peticion->cant>= cargaCarrito){
        peticion->cant -= cargaCarrito;
        this->almacen->carrito->cargaNow = almacen->carrito->capacidad;
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
