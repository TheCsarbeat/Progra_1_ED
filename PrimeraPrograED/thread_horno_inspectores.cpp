#include "thread_horno_inspectores.h"

ThreadHornoInspectores::ThreadHornoInspectores()
{

}

void ThreadHornoInspectores::__init__(QMutex *mutex1,QMutex *mutex2, Horno * horno, Inspectores * inspectores, EstructuraProgressBar * progressBar, QCheckBox * checkOnOff){
    this->mutexEnsambladoraHorno = mutex1;
    this->mutexHornoInspectores = mutex2;
    this->horno = horno;
    this->inspectores = inspectores;
    this->progressBar = progressBar;
    this->checkOnOff = checkOnOff;
    this->running = false;
    this->paused = false;
}

void ThreadHornoInspectores::run(){
    horno->flagProcesando = true;
    this->running = true;
    while(running){
        while(paused){
            if(checkOnOff->isChecked()) resume();
            msleep(500);
        }
        qDebug() << "Llegue antes del if dentro del hilo";
        if(horno->capacidad > horno->getCurrentCantidad() && horno->banda->cantNow > 0){
            horno->lbTitulo->setText("Llenando...");
            sleep(horno->tiempoRellenado);
            horno->llenarBandejas();
            horno->imprimir();
        }else{
            horno->lbTitulo->setText("Horneando...");
            horno->sumarSegundo();
            sleep(1);
            if(horno->tiempoHorneado == horno->tiempoNow){
                mutexEnsambladoraHorno->lock();
                int horneado = horno->hornear();
                mutexEnsambladoraHorno->unlock();

                mutexHornoInspectores->lock();
                qDebug() << "Working on it";
                mutexHornoInspectores->unlock();
                stop();
            }
        }

    }
}

void ThreadHornoInspectores::pause() {
    this->paused = true;

}

void ThreadHornoInspectores::stop() {
    running = false;
    horno->flagProcesando = false;
    horno->tiempoNow = 0;
    horno->imprimir();
}

void ThreadHornoInspectores::resume() {
    this->paused = false;
}
