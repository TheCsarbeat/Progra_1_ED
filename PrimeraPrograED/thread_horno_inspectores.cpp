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
    while(running){
        horno->flagProcesando = false;
        while(paused){
            bool flag = horno->flagProcesando;
            //int cantNow = mainStruct->horno->getCurrentCantidad();
            //int capacidad = mainStruct->horno->capacidad;
            if(!flag && horno->banda->cantNow > 0  && checkOnOff->isChecked() && horno->state ){
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
    horno->imprimir();

}

void ThreadHornoInspectores::stop() {
    running = false;

}

void ThreadHornoInspectores::resume() {
    this->paused = false;
}
