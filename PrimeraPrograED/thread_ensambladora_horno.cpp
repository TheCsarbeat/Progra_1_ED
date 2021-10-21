#include "thread_ensambladora_horno.h"

ThreadEnsambladoraHorno::ThreadEnsambladoraHorno()
{

}

void ThreadEnsambladoraHorno::__init__(QMutex *mutex1,QMutex *mutex2, Ensambladora * ensambladora, Horno * horno, Receta * receta,EstructuraProgressBar * progressBar, QCheckBox * checkOnOff){
    this->mutexMachineEnsambladora = mutex1;
    this->mutexEnsambladoraHorno = mutex2;
    this->ensambladora = ensambladora;
    this->horno = horno;
    this->receta = receta;
    this->running = false;
    this->paused = false;
    this->progressBar = progressBar;
    this->checkOnOff = checkOnOff;


}

void ThreadEnsambladoraHorno::run(){
    this->running = true;
    this->ensambladora->flagProcesando = true;
    int mezcla = receta->cantMezcla;
    int choco = receta->cantChocolate;
    while(running){
        while(paused){
            if(checkOnOff->isChecked()) resume();
            msleep(500);
        }
        if(!checkOnOff->isChecked()) pause();
        else{
            if(ensambladora->cant > (horno->banda->capacidad - horno->banda->cantNow)){
                checkOnOff->setChecked(false);
                pause();
            }
            ensambladora->sumarSegundo();
            this->progressBar->setValue(((double)this->ensambladora->timeActual/this->ensambladora->duracionSegundos)*100);
            sleep(1);
            if(ensambladora->timeActual == ensambladora->duracionSegundos){

                this->mutexMachineEnsambladora->lock();
                int cantGalletas = ensambladora->makeCookies(mezcla, choco); //hace las galletas y asigna a una variable
                ensambladora->galletasHechas+=cantGalletas; //suma el total de galletas hechas
                this->mutexMachineEnsambladora->unlock();

                this->mutexEnsambladoraHorno->lock();
                horno->banda->cantNow += cantGalletas; // pasa las galletas hechas a la banda del horno
                this->mutexEnsambladoraHorno->unlock();
                stop();
            }
        }
    }
}

void ThreadEnsambladoraHorno::stop(){
    this->running = false;
    ensambladora->timeActual = 0;
    this->ensambladora->flagProcesando = false;
    this->progressBar->setValue(0);
    ensambladora->imprimir();
    horno->banda->imprimir();
}

void ThreadEnsambladoraHorno::pause() {
    this->paused = true;
}

void ThreadEnsambladoraHorno::resume() {
    this->paused = false;
}
