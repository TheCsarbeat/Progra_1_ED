#include "thread_inspectores_ensambladora.h"

ThreadPrimerInspector::ThreadPrimerInspector()
{

}

void ThreadPrimerInspector::__init__(QMutex *mutex1,QMutex *mutex2, Horno * horno, Inspectores * inspectores,Inspector * inspector, Empacadora * empacadora, EstructuraProgressBar * progressBar, QCheckBox * checkOnOff){
    this->mutexHornoInspector1 = mutex1;
    this->mutexInspector1ToInspector2 = mutex2;
    this->horno = horno;
    this->inspectores = inspectores;
    this->progressBar = progressBar;
    this->running = false;
    this->paused = false;
    this->checkOnOff = checkOnOff;
    this->inspector = inspector;
    this->empacadora = empacadora;
}

void ThreadPrimerInspector::run(){
    this->running = true;
    this->paused = true;
    Banda * bandaSiguiente;
    Banda * bandaActual;
    mutexInspector1ToInspector2->lock();
    if(inspector->id == 0){
        bandaActual = inspectores->arrayBandas->array[0];
        bandaSiguiente = inspectores->arrayBandas->array[1];
    }else{
        bandaActual = inspectores->arrayBandas->array[1];
        bandaSiguiente = empacadora->banda;
    }
    mutexInspector1ToInspector2->unlock();
    while(running){
        this->inspector->flagProcesando = false;
        while(paused){
            inspector->lbTitle->setText("Waiting...");
            if(inspector->flagProcesando == false && checkOnOff->isChecked() && inspector->state && bandaActual->cantNow > 0){
                inspector->flagProcesando = true;
                resume();
            }
            msleep(500);
        }
        //pause conditions
        if(inspector->capacidad > (bandaSiguiente->capacidad - bandaSiguiente->cantNow)){
            checkOnOff->setChecked(false);
            pause();
        }else if(inspector->capacidad > inspector->actualGalletas && bandaActual->cantNow > 0){
            inspector->lbTitle->setText("Cargando...");
            inspector->actualGalletas++;
            bandaActual->cantNow--;
            inspectores->imprimir();
            msleep(500);
        }else if(inspector->capacidad <= inspector->actualGalletas){
            inspector->lbTitle->setText("Descartando..");
            inspector->sumarSegundo();
            //progressBar->setValue(((double)inspector->tiempoNow/inspector->tiempo)*100);
            sleep(1);
            if(inspector->tiempoNow == inspector->tiempo){
                mutexHornoInspector1->lock();
                int aprobadas = inspector->inspect();
                mutexHornoInspector1->unlock();

                mutexInspector1ToInspector2->lock();
                bandaSiguiente->cantNow += aprobadas;
                mutexInspector1ToInspector2->unlock();
                pause();
            }
        }
    }
}

void ThreadPrimerInspector::resume() {
    this->paused = false;
}

void ThreadPrimerInspector::pause() {
    this->paused = true;
    inspector->flagProcesando = false;
    inspector->tiempoNow = 0;
    inspector->actualGalletas = 0;
    inspectores->imprimir();
    empacadora->banda->imprimir();
}

void ThreadPrimerInspector::stop(){
    this->paused = false;
    this->running = false;
}

