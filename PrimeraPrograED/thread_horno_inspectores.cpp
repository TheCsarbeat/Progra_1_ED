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

    this->running = true;
    this->paused = true;
    qDebug() << "Soy un horno";
    while(running){
        horno->flagProcesando = false;
        while(paused){
            bool flag = horno->flagProcesando;
            horno->lbTitulo->setText("Waiting...");
            if(!flag && horno->banda->cantNow > 0  && horno->state && checkOnOff->isChecked()){
                horno->flagProcesando = true;
                resume();
            }
            msleep(500);
        }
        if(horno->capacidad > horno->getCurrentCantidad() && horno->banda->cantNow > 0){
            horno->lbTitulo->setText("Llenando...");
            sleep(horno->tiempoRellenado);
            horno->llenarBandejas();
            horno->imprimir();
        }else if(horno->capacidad <= horno->getCurrentCantidad()){
            horno->lbTitulo->setText("Horneando...");
            progressBar->setValue(((double)this->horno->tiempoNow/this->horno->tiempoHorneado)*100);
            horno->sumarSegundo();
            qDebug() << "tiempoNow: "+QString::number(horno->tiempoNow);
            sleep(1);
            if(horno->tiempoHorneado <= horno->tiempoNow){
                mutexEnsambladoraHorno->lock();
                int horneado = horno->hornear();
                mutexEnsambladoraHorno->unlock();

                mutexHornoInspectores->lock();
                qDebug() << "Working on it";
                mutexHornoInspectores->unlock();
                pause();
            }
        }else{
            msleep(500);
        }

    }
}

void ThreadHornoInspectores::pause() {
    this->paused = true;
    horno->flagProcesando = false;
    horno->tiempoNow = 0;
    progressBar->setValue(0);
    horno->imprimir();

}

void ThreadHornoInspectores::stop() {
    running = false;

}

void ThreadHornoInspectores::resume() {
    this->paused = false;
}
