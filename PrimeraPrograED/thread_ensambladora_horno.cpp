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
    this->running = false;
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

            ensambladora->sumarSegundo();
            try {
                    this->progressBar->setValue(((double)this->ensambladora->timeActual/this->ensambladora->duracionSegundos)*100);
                }  catch (...) {
                    qDebug()<<EXIT_FAILURE;
                }

            sleep(1);
            if(ensambladora->timeActual >= ensambladora->duracionSegundos){

                this->mutexMachineEnsambladora->lock();
                int cantGalletas = ensambladora->makeCookies(mezcla, choco);
                this->mutexMachineEnsambladora->unlock();

                this->mutexEnsambladoraHorno->lock();
                horno->banda->cantNow += cantGalletas;
                this->mutexEnsambladoraHorno->unlock();
                stop();
            }

    }
}

void ThreadEnsambladoraHorno::stop(){
    this->running = false;
    ensambladora->timeActual = 0;
    this->ensambladora->flagProcesando = false;
}

void ThreadEnsambladoraHorno::pause() {
    this->paused = true;
}

void ThreadEnsambladoraHorno::resume() {
    this->paused = false;
}
