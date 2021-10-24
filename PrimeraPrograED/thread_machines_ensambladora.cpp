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
    this->machine->flagProcesando = false;
    if(machine->nombre != "Chocolatera"){
        banda = ensambladora->bandas->array[0];
    }else{
        banda = ensambladora->bandas->array[1];
    }
    paused = true;
    while (running){
        this->machine->flagProcesando = false;
        while (paused){
            int cantNow = machine->cantNow;
            int cantMin = machine->min;
            bool flagProcesando = machine->flagProcesando;
            if(cantNow >= cantMin && flagProcesando == false  && checkOnOff->isChecked() && machine->state){
                machine->flagProcesando = true;
                resume();
            }
            msleep(500);
        }
        //Pause conditions
        if(machine->gramosProcesar > (banda->capacidad-banda->cantNow)){
            checkOnOff->setChecked(false);
            paused = true;
        }else{
            //Own Statements
            this->machine->procesar();
            this->machine->lbTitulo->setText("Processing...");
            this->progressBar->setValue(((double)this->machine->tiempoActual/this->machine->duracionSegudos)*100);
            msleep(machine->sleepTime);

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

                pause();
                banda->imprimir();

            }
        }
    }
}

void ThreadMachinesEnsambladora::pause() {
    this->paused = true;
    this->machine->lbTitulo->setText(machine->nombre+" Waiting...");
    this->mutexCarritoMachine->lock();
    NodoPeticion *peticion = this->colaPeticiones->verUltimo();
    int gramosEncolar =  machine->gramosProcesar;
    if(machine->aviableEncolar){
        if(peticion != NULL){
            if(peticion->peticion->idMachine == this->machine->id){
                peticion->peticion->cant += gramosEncolar;
            }else{
                this->colaPeticiones->encolar(this->machine->nombre,gramosEncolar, this->machine->id);
            }
        }else{
            this->colaPeticiones->encolar(this->machine->nombre, gramosEncolar, this->machine->id);
        }
    }
    colaPeticiones->imprimir();
    this->mutexCarritoMachine->unlock();


    this->machine->imprimirDatos();

}

void ThreadMachinesEnsambladora::stop() {
    this->paused = false;
    this->running = false;

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
