#include "thread_transportadores_almacen.h"

ThreadTransportadoresAlmacen::ThreadTransportadoresAlmacen()
{

}

void ThreadTransportadoresAlmacen::__init__(QMutex *mutex1, ArrayTransportadores * transportadores, int id, Empacadora * empacadora, EstructuraProgressBar * progressBar, QCheckBox * checkOnOff){
    this->mutexEmpacadoraTransporte = mutex1;
    this->transportadores = transportadores;
    this->running = false;
    this->paused = false;
    this->progressBar = progressBar;
    this->checkOnOff = checkOnOff;
    this->i = id;
    this->empacadora = empacadora;
}

void ThreadTransportadoresAlmacen::run(){
    this->running = true;



    this->transportadores->p[i]->flagProcesando= false;
    this->paused = true;
    while(running){
        while(paused){
            this->transportadores->imprimir();
            this->transportadores->imprimirRegistro();
            if(transportadores->p[i]->cargaNow == transportadores->p[i]->capacidad && !this->transportadores->p[i]->flagProcesando && checkOnOff->isChecked() && transportadores->state){
                this->transportadores->p[i]->flagProcesando=true;
                resume();
            }
            msleep(500);
        }


        /*if(machine->gramosProcesar > (banda->capacidad-banda->cantNow)){
            checkOnOff->setChecked(false);
            paused = true;
        }else{*/
            //Own Statements
            this->transportadores->p[i]->sumarSegundo();
            this->transportadores->p[i]->toString();
            this->transportadores->imprimir();
            //this->progressBar->setValue(((double)this->transportadores->p[i]->timeNow/transportadores->p[i]->speed)*100);
            msleep(this->transportadores->p[i]->sleepTime);

            //Stop Condition
            if(this->transportadores->p[i]->timeNow == transportadores->p[i]->speed){
                transportadores->p[i]->cantProcesado += transportadores->p[i]->capacidad;
                pause();


            }
        //}



    }
}

void ThreadTransportadoresAlmacen::stop(){
    this->paused = false;
    this->running = false;
}

void ThreadTransportadoresAlmacen::pause() {
    this->paused = true;

    this->transportadores->p[i]->timeNow =0;
    this->transportadores->p[i]->cargaNow =0;
    this->transportadores->p[i]->flagProcesando =false;

    //this->progressBar->setValue(0);


}

void ThreadTransportadoresAlmacen::resume() {
    this->paused = false;

}
