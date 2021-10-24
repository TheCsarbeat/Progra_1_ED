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
    this->paused = true;
    while(running){
        int mezcla = receta->cantMezcla;
        int choco = receta->cantChocolate;
        this->ensambladora->flagProcesando = false;
        while(paused){
            mutexMachineEnsambladora->lock();
            int banda1Now = ensambladora->bandas->array[0]->cantNow;
            int banda2Now = ensambladora->bandas->array[1]->cantNow;
             mutexMachineEnsambladora->unlock();
            int cantMezcla = ensambladora->cant *receta->cantMezcla;
            int cantChoco = ensambladora->cant * receta->cantChocolate;
            bool flagEnsambladora = ensambladora->flagProcesando;
            if(banda1Now>=cantMezcla && banda2Now>=cantChoco && !flagEnsambladora  && checkOnOff->isChecked() && ensambladora->state){
                ensambladora->flagProcesando = true;
                resume();
            }
            msleep(500);
        }
        if(ensambladora->cant > (horno->banda->capacidad - horno->banda->cantNow)){
            checkOnOff->setChecked(false);
            pause();
        }else{
            ensambladora->sumarSegundo();
            this->progressBar->setValue(((double)this->ensambladora->timeActual/this->ensambladora->duracionSegundos)*100);
            qDebug()<<ensambladora->sleepTime;
            msleep(ensambladora->sleepTime);
            if(ensambladora->timeActual == ensambladora->duracionSegundos){
                this->mutexMachineEnsambladora->lock();
                int cantGalletas = ensambladora->makeCookies(mezcla, choco); //hace las galletas y asigna a una variable
                ensambladora->galletasHechas+=cantGalletas; //suma el total de galletas hechas
                this->mutexMachineEnsambladora->unlock();

                this->mutexEnsambladoraHorno->lock();
                horno->banda->cantNow += cantGalletas; // pasa las galletas hechas a la banda del horno
                this->mutexEnsambladoraHorno->unlock();
                pause();
            }
        }


    }
}

void ThreadEnsambladoraHorno::stop(){
    this->paused = false;
    this->running = false;
}

void ThreadEnsambladoraHorno::pause() {
    this->paused = true;
    ensambladora->timeActual = 0;
    this->ensambladora->flagProcesando = false;
    this->progressBar->setValue(0);
    ensambladora->imprimir();
    horno->banda->imprimir();
}

void ThreadEnsambladoraHorno::resume() {
    this->paused = false;
}
