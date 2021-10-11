#include "thread_machines_ensambladora.h"

ThreadMachinesEnsambladora::ThreadMachinesEnsambladora(){

}

void ThreadMachinesEnsambladora::__init__(Machine * machine, ColaPeticiones * colaPeticiones, Ensambladora * ensambladora, QMutex * mutex, QLabel * label, QLabel *lbCola) {
    this->running = false;
    this->paused = false;
    this->machine = machine;
    this->ensambladora = ensambladora;
    this->mutex = mutex;
    this->label = label;
    this->colaPeticiones = colaPeticiones;
    this->lbCola = lbCola;
}

void ThreadMachinesEnsambladora::run() {
    this->mutex->lock();
    this->running = true;
    Banda * banda1 = ensambladora->bandas->array[0];
    Banda * banda2 = ensambladora->bandas->array[1];
    this->machine->flagProcesando = true;

    while (running) {
        while (paused) {
            sleep(1);
        }

        this->machine->procesar();

        this->label->setText(QString::number(this->machine->tiempoActual)+" de "+QString::number(this->machine->duracionSegudos)
                             +" segundos para procesar a la "+banda1->nombre);
        sleep(1);
        if(this->machine->tiempoActual == this->machine->duracionSegudos){
            if(machine->nombre != "Chocolatera"){
                banda1->cantNow += this->machine->gramosProcesar;
            }else{
                banda2->cantNow += this->machine->gramosProcesar;
            }
            stop();
        }

    }
    this->mutex->unlock();
}

void ThreadMachinesEnsambladora::pause() {
    this->paused = true;
}

void ThreadMachinesEnsambladora::stop() {
    this->running = false;
    this->machine->tiempoActual =0;
    this->colaPeticiones->encolar(this->machine->nombre, this->machine->gramosProcesar, this->machine->id);
    this->lbCola->setText(colaPeticiones->toString());

}

void ThreadMachinesEnsambladora::resume() {
    this->paused = false;
}
