#include "thread_almacen_machines.h"

ThreadAlmacenMachines::ThreadAlmacenMachines(){

}

void ThreadAlmacenMachines::__init__(Almacen * almacen, Machine * machine, QMutex * mutex, QLabel * label) {
    this->almacen = almacen;
    this->running = false;
    this->paused = false;
    this->mutex = mutex;
    this->machine = machine;
    this->label = label;
}

void ThreadAlmacenMachines::run() {
    this->mutex->lock();
    this->running = true;
    while (running) {
        while (paused) {
            sleep(1);
        }
        this->almacen->carrito->libre = false;
        this->almacen->carrito->sumarSegundo();

        this->label->setText(QString::number(this->almacen->carrito->timeActual)+" de "+QString::number(this->almacen->carrito->duracionTotal)
                             +" segundos para llegar a la "+this->machine->nombre);
        sleep(1);
        if(this->almacen->carrito->duracionTotal == this->almacen->carrito->timeActual){
            this->machine->cantNow = this->almacen->carrito->capacidad;
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

    this->machine->fillState = false;

    this->running = false;
}

void ThreadAlmacenMachines::resume() {
    this->paused = false;
}
