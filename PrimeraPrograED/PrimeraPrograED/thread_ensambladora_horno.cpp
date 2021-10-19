#include "thread_ensambladora_horno.h"

ThreadEnsambladoraHorno::ThreadEnsambladoraHorno()
{

}

void ThreadEnsambladoraHorno::__init__(QMutex *mutex, Ensambladora * ensambladora, Horno * horno, Receta * receta, QLabel * arrayLbEnsambladora[4]){
    this->mutex = mutex;
    this->ensambladora = ensambladora;
    this->horno = horno;
    this->receta = receta;
    this->arrayLbEnsambladora[0] = arrayLbEnsambladora[0];
    this->arrayLbEnsambladora[1] = arrayLbEnsambladora[1];
    this->arrayLbEnsambladora[2] = arrayLbEnsambladora[2];
    this->arrayLbEnsambladora[3] = arrayLbEnsambladora[3];
    this->running = false;
    this->running = false;

}

void ThreadEnsambladoraHorno::run(){
    this->running = true;
    this->ensambladora->flagProcesando = true;
    int mezcla = receta->cantMezcla;
    int choco = receta->cantChocolate;
    while(running){
        ensambladora->sumarSegundo();
        arrayLbEnsambladora[2]->setText(QString::number(ensambladora->timeActual)+" de "+QString::number(ensambladora->duracionSegundos) +" para hacer las "+QString::number(ensambladora->cant)+" galletas");
        sleep(1);
        if(ensambladora->timeActual == ensambladora->duracionSegundos){
            this->mutex->lock();
            horno->banda->cantNow += ensambladora->makeCookies(mezcla, choco);
            arrayLbEnsambladora[0]->setText("\n cantidad Actual: "+QString::number(ensambladora->bandas->array[0]->cantNow)
                                                 +"\n Max: "+QString::number(ensambladora->bandas->array[0]->capacidad));
            arrayLbEnsambladora[1]->setText("\n cantidad Actual: "+QString::number(ensambladora->bandas->array[0]->cantNow)
                                                 +"\n Max: "+QString::number(ensambladora->bandas->array[0]->capacidad));
            arrayLbEnsambladora[3]->setText("\n cantidad Actual: "+QString::number(horno->banda->cantNow)
                    +"\n Max: "+QString::number(horno->banda->capacidad));
            this->mutex->unlock();
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
