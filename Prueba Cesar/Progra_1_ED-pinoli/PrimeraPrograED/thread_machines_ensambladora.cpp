#include "thread_machines_ensambladora.h"

ThreadMachinesEnsambladora::ThreadMachinesEnsambladora(){

}

void ThreadMachinesEnsambladora::__init__(Machine * machine, ColaPeticiones * colaPeticiones, Ensambladora * ensambladora,QMutex * mutexCarritoMa, QMutex * mutexEnsam,EstructuraProgressBar * progressBar, QCheckBox * checkOnOff) {
    this->running = false;
    this->paused = false;
    this->machine = machine;
    this->ensambladora = ensambladora;
    this->mutexCarritoMachine = mutexCarritoMa;
    this->mutexMachineEnsambladora = mutexEnsam;
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
            msleep(500);
            if(checkOnOff->isChecked())resume();
        }

        //Pause conditions
        if(machine->gramosProcesar > (banda->capacidad-banda->cantNow)){
            checkOnOff->setChecked(false);
            pause();
        }else{
            //Own Statements
            this->machine->procesar();
            this->machine->lbTitulo->setText("Processing...");
            this->progressBar->setValue(((double)this->machine->tiempoActual/this->machine->duracionSegudos)*100);
            sleep(1);

            //Stop Condition
            if(this->machine->tiempoActual == this->machine->duracionSegudos){
                resetDatos();
                mutexMachineEnsambladora->lock();
                banda->cantNow += this->machine->gramosProcesar;
                machine->totalMezclado += this->machine->gramosProcesar;
                mutexMachineEnsambladora->unlock();

                mutexCarritoMachine->lock();
                this->machine->cantNow -= this->machine->gramosProcesar;
                mutexCarritoMachine->unlock();

                stop();
                banda->imprimir();

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

    this->mutexCarritoMachine->lock();
    NodoPeticion *peticion = this->colaPeticiones->verUltimo();
    if(peticion != NULL){
        if(peticion->peticion->idMachine == this->machine->id){
            colaPeticiones->verUltimo()->peticion->cant += this->machine->gramosProcesar;
        }else{
            this->colaPeticiones->encolar(this->machine->nombre, this->machine->gramosProcesar, this->machine->id);
        }
    }else{
        this->colaPeticiones->encolar(this->machine->nombre, this->machine->gramosProcesar, this->machine->id);
    }
    this->mutexCarritoMachine->unlock();

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
