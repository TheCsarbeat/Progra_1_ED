#include "thread_machines_ensambladora.h"

ThreadMachinesEnsambladora::ThreadMachinesEnsambladora(){

}

void ThreadMachinesEnsambladora::__init__(Machine * machine, ColaPeticiones * colaPeticiones, Ensambladora * ensambladora, QMutex * mutex,EstructuraProgressBar * progressBar, QCheckBox * checkOnOff) {
    this->running = false;
    this->paused = false;
    this->machine = machine;
    this->ensambladora = ensambladora;
    this->mutex = mutex;
    this->colaPeticiones = colaPeticiones;
    this->progressBar = progressBar;
    this->checkOnOff = checkOnOff;
}

void ThreadMachinesEnsambladora::run() {

    this->running = true;
    Banda * banda;
    this->machine->flagProcesando = true;
    if(machine->nombre != "Chocolatera"){
        banda = ensambladora->bandas->array[0];
    }else{
        banda = ensambladora->bandas->array[1];
    }
    while (running) {
        while (paused) {
            if(checkOnOff->isChecked()) resume();
            msleep(500);
        }
        if(!checkOnOff->isChecked()) pause();
        else{
            //Own Statements
            this->machine->procesar();
            this->machine->lbTitulo->setText("Processing...");
            this->progressBar->setValue(((double)this->machine->tiempoActual/this->machine->duracionSegudos)*100);
            sleep(1);

            //Stop Condition
            if(this->machine->tiempoActual == this->machine->duracionSegudos){
                resetDatos();
                banda->cantNow += this->machine->gramosProcesar;

                this->mutex->lock();
                this->machine->cantNow -= this->machine->gramosProcesar;
                this->mutex->unlock();

                stop();
            }
        }


    }

}

void ThreadMachinesEnsambladora::pause() {
    this->paused = true;
    this->machine->lbTitulo->setText(machine->nombre+" Waiting...");

}

void ThreadMachinesEnsambladora::stop() {

    this->running = false;
    this->colaPeticiones->encolar(this->machine->nombre, this->machine->gramosProcesar, this->machine->id);
    colaPeticiones->imprimir();
    this->machine->imprimirDatos();

}

void ThreadMachinesEnsambladora::resume() {
    this->paused = false;
}

void ThreadMachinesEnsambladora::resetDatos(){
    //Visuales
    this->machine->lbTitulo->setText(machine->nombre+" Waiting...");
    this->progressBar->setValue(0);

    //Code
    this->machine->tiempoActual = 0;
    this->machine->flagProcesando = false;
}
