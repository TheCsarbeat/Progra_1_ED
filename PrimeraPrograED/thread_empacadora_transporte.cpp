#include "thread_empacadora_transporte.h"

ThreadEmpacadoraTransporte::ThreadEmpacadoraTransporte(){

}


void ThreadEmpacadoraTransporte::__init__(QMutex *mutex1,QMutex *mutex2, Empacadora * empacadora, ArrayTransportadores * transporte, EstructuraProgressBar * progressBar, QCheckBox * checkOnOff){
    this->mutexEmpacadoraTransporte = mutex1;
    this->mutexInspectorEmpacadora = mutex2;
    this->empacadora = empacadora;
    this->running = false;
    this->paused = false;
    this->progressBar = progressBar;
    this->checkOnOff = checkOnOff;
    this->listaPlanificaciones = empacadora->lista->toStringParaEmpacadora();
    this->transportadores = transporte;
    this->flagParando = true;

}

void ThreadEmpacadoraTransporte::run(){
    this->running = true;

    int sumaProbabilidades = 0;


    this->paused = true;
    int index;
    while(running){
        this->empacadora->flagProcesando = false;
        while(paused){
            if(empacadora->state){
            this->empacadora->lbDatos->setText("Nombre : \nCantidad paquete: "+QString::number(empacadora->cantTiposEmpacandoActual)
                                               +"\nGalletas por paquete: "+QString::number(empacadora->cantGalletasAEmpacar));
            int random = rand()%100;
            empacadora->imprimir();
            for(int i = 0; i<listaPlanificaciones.length(); i++){
                if(empacadora->p[i]->probabilidad+sumaProbabilidades>=random && empacadora->p[i]->probabilidad !=0 ){
                    id = i;
                    for(int j =0; j<this->transportadores->len; j++){
                        if(transportadores->p[j]->id == empacadora->p[id]->id)index = j;
                    }
                }
                sumaProbabilidades+=empacadora->p[i]->probabilidad;
            }
            sumaProbabilidades=0;

            int diferencia = empacadora->p[id]->cantPaquetesPorEmpacar - empacadora->p[id]->totalPaquetesEmpacados;
            int galletasAEmpacar = empacadora->p[id]->cantEmpacado * empacadora->p[id]->cantGalletasPorPaquete;
            if( empacadora->p[id]->cantEmpacado<= diferencia && empacadora->p[id]->totalPaquetesEmpacados < empacadora->p[id]->cantPaquetesPorEmpacar && !this->empacadora->flagProcesando && checkOnOff->isChecked() && empacadora->state){
                qDebug("Estamos entrando");
                empacadora->flagProcesando = true;
                empacadora->cantGalletasAEmpacar =galletasAEmpacar;
                    while(empacadora->banda->cantNow < galletasAEmpacar){
                        qDebug()<<"Galletas a empacar:"<< galletasAEmpacar;
                        qDebug()<<"Cant Now:"<< empacadora->banda->cantNow;
                        this->empacadora->lbtitulo->setText("Waiting for cookies: "+empacadora->p[id]->nombre+"...");
                        msleep(500);
                    }

                    mutexInspectorEmpacadora->lock();
                    empacadora->banda->cantNow -=empacadora->cantGalletasAEmpacar;
                    mutexInspectorEmpacadora->unlock();
                resume();
            }

            msleep(500);
            }

        } //Fin While pause


        if(empacadora->p[id]->cantEmpacado > (transportadores->p[index]->capacidad - transportadores->p[index]->cargaNow)){
            checkOnOff->setChecked(false);
            paused = true;
            empacadora->banda->cantNow +=empacadora->cantGalletasAEmpacar;
        }else{
            //Own Statements

            this->empacadora->sumarSegundo(empacadora->p[id]->tiempoDuracion);
            this->empacadora->lbtitulo->setText("Empacando...");
            this->empacadora->lbDatos->setText("Nombre : "+empacadora->p[id]->nombre+ "\nCantidad paquete: "+QString::number(empacadora->p[id]->cantEmpacado)+
                                               "\nGalletas por paquete: "+QString::number(empacadora->p[id]->cantGalletasPorPaquete));
            this->progressBar->setValue(((double)this->empacadora->timeNow/empacadora->p[id]->tiempoDuracion)*100);
            msleep(this->empacadora->sleepTime);

            //Stop Condition
            if(this->empacadora->timeNow == empacadora->p[id]->tiempoDuracion){

                for(int i =0; i<this->transportadores->len; i++){
                    if(transportadores->p[i]->id == empacadora->p[id]->id){
                        if(this->transportadores->p[i]->flagProcesando){
                            qDebug()<<"Emtro ";
                            waiting = true;
                            while(waiting){
                                if(!this->transportadores->p[i]->flagProcesando)waiting=false;
                                msleep(500);
                            }

                        }
                    }
                }
                pause();
            }
        }//fin else

    }
}

void ThreadEmpacadoraTransporte::stop(){
    this->paused = false;
    this->running = false;
}

void ThreadEmpacadoraTransporte::pause() {
    this->paused = true;
    this->empacadora->lbtitulo->setText("Waiting...");

    this->mutexEmpacadoraTransporte->lock();

    for(int i =0; i<this->transportadores->len; i++){
        if(transportadores->p[i]->id == empacadora->p[id]->id){
            this->transportadores->p[i]->cargaNow += this->empacadora->p[id]->cantEmpacado;

        }
    }

    this->mutexEmpacadoraTransporte->unlock();

    this->empacadora->p[id]->totalPaquetesEmpacados += this->empacadora->p[id]->cantEmpacado;
    this->empacadora->cantTiposEmpacandoActual =0;
    this->empacadora->cantGalletasAEmpacar= 0;
    this->empacadora->imprimir();

    empacadora->timeNow = 0;
    this->empacadora->flagProcesando = false;
    this->progressBar->setValue(0);

    int diferencia = empacadora->p[id]->cantPaquetesPorEmpacar - empacadora->p[id]->totalPaquetesEmpacados;
    if(empacadora->p[id]->cantEmpacado> diferencia)
         empacadora->p[id]->probabilidad =0;

}

void ThreadEmpacadoraTransporte::resume() {
    this->paused = false;
}

int* ThreadEmpacadoraTransporte::ordenarArray(int miArray[], int len){
    int temporal;
    for (int i = 0;i < len; i++){
        for (int j = 0; j< len-1; j++){
            if (miArray[j] > miArray[j+1]){ // Ordena el array de mayor a menor, cambiar el "<" a ">" para ordenar de menor a mayor
            temporal = miArray[j];
            miArray[j] = miArray[j+1];
            miArray[j+1] = temporal;
            }
        }
    }
    return miArray;
}
