#include "thread_machines_ensambladora.h"

ThreadMachinesEnsambladora::ThreadMachinesEnsambladora(){

}

void ThreadMachinesEnsambladora::__init__(Machine * machine, ColaPeticiones * colaPeticiones, Ensambladora * ensambladora, QMutex * mutex, QLabel * label, QLabel *lbCola, QLabel * arraylbDatosMachines[6]) {
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
}

void ThreadMachinesEnsambladora::run() {

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
