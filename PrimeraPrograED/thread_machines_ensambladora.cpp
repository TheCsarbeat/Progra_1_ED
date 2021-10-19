#include "thread_machines_ensambladora.h"

ThreadMachinesEnsambladora::ThreadMachinesEnsambladora(){

}

void ThreadMachinesEnsambladora::__init__(Machine * machine, ColaPeticiones * colaPeticiones, Ensambladora * ensambladora, QMutex * mutex, QLabel * label, QLabel *lbCola, QLabel * arraylbDatosMachines[6], QLabel * arrayLbEnsambladora[4]) {
    this->running = false;
    this->paused = false;
    this->machine = machine;
    this->ensambladora = ensambladora;
    this->mutex = mutex;
    this->label = label;
    this->colaPeticiones = colaPeticiones;
    this->lbCola = lbCola;
    this->arraylbDatosMachines[0] = arraylbDatosMachines[3];
    this->arraylbDatosMachines[1] = arraylbDatosMachines[4];
    this->arraylbDatosMachines[2] = arraylbDatosMachines[5];

    this->arrayLbEnsambladora[0] = arrayLbEnsambladora[0];
    this->arrayLbEnsambladora[1] = arrayLbEnsambladora[1];
}

void ThreadMachinesEnsambladora::run() {

    this->running = true;
    Banda * banda;
    this->machine->flagProcesando = true;
    int pBanda;
    if(machine->nombre != "Chocolatera"){
        banda = ensambladora->bandas->array[0];
        pBanda = 0;
    }else{
        banda = ensambladora->bandas->array[1];
        pBanda = 1;
    }
    while (running) {
        while (paused) {
            sleep(1);
        }

        this->machine->procesar();
        this->label->setText(QString::number(this->machine->tiempoActual)+" de "+QString::number(this->machine->duracionSegudos)
                             +" segundos para procesar a la "+banda->nombre);


        sleep(1);

        if(this->machine->tiempoActual == this->machine->duracionSegudos){
            this->mutex->lock();
            banda->cantNow += this->machine->gramosProcesar;
            arrayLbEnsambladora[pBanda]->setText("\n cantidad Actual: "+QString::number(banda->cantNow) //volver aqui mañana porque no se imprime la cant actual de la banda
                                                 +"\n Max: "+QString::number(banda->capacidad));
            this->mutex->unlock();
            this->machine->cantNow -= this->machine->gramosProcesar;
            stop();
        }

    }

}

void ThreadMachinesEnsambladora::pause() {
    this->paused = true;
}

void ThreadMachinesEnsambladora::stop() {
    this->running = false;
    this->machine->tiempoActual = 0;
    this->machine->flagProcesando = false;
    this->colaPeticiones->encolar(this->machine->nombre, this->machine->gramosProcesar, this->machine->id);
    this->lbCola->setText(colaPeticiones->toString());
    this->arraylbDatosMachines[this->machine->id]->setText(+"\n cantidad Actual: "+QString::number(machine->cantNow)
                                                           +"\n Min: "+QString::number(machine->min)
                                                           +"\n Max: "+QString::number(machine->max));

}

void ThreadMachinesEnsambladora::resume() {
    this->paused = false;
}
