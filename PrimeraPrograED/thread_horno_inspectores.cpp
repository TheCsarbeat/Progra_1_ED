#include "thread_horno_inspectores.h"

ThreadHornoInspectores::ThreadHornoInspectores()
{

}

void ThreadHornoInspectores::__init__(QMutex *mutex1,QMutex *mutex2, Horno * horno, Inspectores * inspectores, EstructuraProgressBar * progressBar, QCheckBox * checkOnOff[5]){
    this->mutexEnsambladoraHorno = mutex1;
    this->mutexHornoInspectores = mutex2;
    this->horno = horno;
    this->inspectores = inspectores;
    this->progressBar = progressBar;
    this->running = false;
    this->paused = false;

    this->arrayCheckOnOff[0] = checkOnOff[0];
    this->arrayCheckOnOff[1] = checkOnOff[1];
    this->arrayCheckOnOff[2] = checkOnOff[2];
    this->arrayCheckOnOff[3] = checkOnOff[3];
    this->arrayCheckOnOff[4] = checkOnOff[4];
}

void ThreadHornoInspectores::run(){
    this->running = true;
    this->paused = true;
    while(running){
        horno->flagProcesando = false;
        while(paused){
            bool flag = horno->flagProcesando;
            horno->lbTitulo->setText("Waiting...");
            if(!flag && horno->banda->cantNow > 0  && horno->state && arrayCheckOnOff[0]->isChecked()){
                if(arrayCheckOnOff[1]->isChecked()){
                    horno->bandejas->array[2]->active = true;
                }else{
                    horno->bandejas->array[2]->active = false;
                }
                if(arrayCheckOnOff[2]->isChecked()){
                    horno->bandejas->array[3]->active = true;
                }else{
                    horno->bandejas->array[3]->active = false;
                }
                if(arrayCheckOnOff[3]->isChecked()){
                    horno->bandejas->array[4]->active = true;
                }else{
                    horno->bandejas->array[4]->active = false;
                }
                if(arrayCheckOnOff[4]->isChecked()){
                    horno->bandejas->array[5]->active = true;
                }else{
                    horno->bandejas->array[5]->active = false;
                }
                horno->flagProcesando = true;
                resume();
            }
            msleep(500);
        }
        if(horno->getCapacidad() > (inspectores->arrayBandas->array[0]->capacidad - inspectores->arrayBandas->array[0]->cantNow)){
            arrayCheckOnOff[0]->setChecked(false);
            pause();
        }
        if(horno->getCapacidad() > horno->getCurrentCantidad() && horno->banda->cantNow > 0){
            horno->lbTitulo->setText("Llenando...");
            sleep(horno->tiempoRellenado);
            horno->llenarBandejas();
            horno->imprimir();
        }else if(horno->getCapacidad() <= horno->getCurrentCantidad()){
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
                inspectores->arrayBandas->array[0]->cantNow += horneado;
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
    inspectores->imprimir();
}

void ThreadHornoInspectores::stop() {
    running = false;

}

void ThreadHornoInspectores::resume() {
    this->paused = false;
}
