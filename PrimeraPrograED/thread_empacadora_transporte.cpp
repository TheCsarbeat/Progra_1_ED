#include "thread_empacadora_transporte.h"

ThreadEmpacadoraTransporte::ThreadEmpacadoraTransporte(){

}


void ThreadEmpacadoraTransporte::__init__(QMutex *mutex1,QMutex *mutex2, Empacadora * empacadora, EstructuraProgressBar * progressBar, QCheckBox * checkOnOff){
    this->mutexEmpacadoraTransporte = mutex1;
    this->mutexInspectorEmpacadora = mutex2;
    this->empacadora = empacadora;
    this->running = false;
    this->paused = false;
    this->progressBar = progressBar;
    this->checkOnOff = checkOnOff;
    this->listaPlanificaciones = empacadora->lista->toStringParaEmpacadora();


}

void ThreadEmpacadoraTransporte::run(){
    this->running = true;

    int sumaProbabilidades = 0;

    this->empacadora->flagProcesando = false;
    this->paused = true;
    while(running){
        while(paused){
            this->empacadora->lbDatos->setText("Nombre : \nCantidad paquete: "+QString::number(empacadora->cantTiposEmpacandoActual)
                                               +"\nGalletas por paquete: "+QString::number(empacadora->cantGalletasAEmpacar));
            int random = rand()%100;
            empacadora->imprimir();
            for(int i = 0; i<listaPlanificaciones.length(); i++){
                int diferencia = empacadora->p[i]->cantPaquetesPorEmpacar - empacadora->p[i]->totalPaquetesEmpacados;
                if(empacadora->p[i]->probabilidad+sumaProbabilidades>=random && empacadora->p[i]->probabilidad !=0 && empacadora->p[i]->cantEmpacado<= diferencia){
                     int galletasAEmpacar = empacadora->p[i]->cantEmpacado* empacadora->p[i]->cantGalletasPorPaquete;

                    qDebug()<<"\n\nNombre: "<<empacadora->p[i]->nombre;
                    qDebug()<<"Probabilidad: "<<empacadora->p[i]->probabilidad;
                    qDebug()<<"Random: "<<random;
                    qDebug()<<"Cant de Paquetes que empaca la empacadora: "<<empacadora->p[i]->cantEmpacado;
                    qDebug()<<"Cant galletas por paquete: "<<empacadora->p[i]->cantGalletasPorPaquete;
                    qDebug()<<"Paquetes Restantes: "<<diferencia;

                    qDebug()<<"Galletas por paquete: "<<empacadora->p[i]->cantGalletasPorPaquete;
                    qDebug()<<"Galletas a empaquetar: "<<galletasAEmpacar;

                    id = i;
                    esperarGalletas = true;


                        if(empacadora->p[i]->totalPaquetesEmpacados < empacadora->p[i]->cantPaquetesPorEmpacar && !this->empacadora->flagProcesando && checkOnOff->isChecked() && empacadora->state){
                            empacadora->flagProcesando = true;
                            empacadora->cantGalletasAEmpacar =galletasAEmpacar;
                            while(empacadora->banda->cantNow < galletasAEmpacar){
                                 this->empacadora->lbtitulo->setText("Esperando Galletas"+empacadora->p[i]->nombre);
                                  msleep(500);
                            }
                            resume();
                        }



                }
                sumaProbabilidades+=empacadora->p[i]->probabilidad;

            }
            sumaProbabilidades =0;
            msleep(500);
        } //Fin While pause


        /*if(machine->gramosProcesar > (banda->capacidad-banda->cantNow)){
            checkOnOff->setChecked(false);
            paused = true;
        }else{*/
            //Own Statements
            this->empacadora->sumarSegundo(empacadora->p[id]->tiempoDuracion);
            this->empacadora->lbtitulo->setText("Empacando...");
            this->empacadora->lbDatos->setText("Nombre : "+empacadora->p[id]->nombre+ "\nCantidad paquete: "+QString::number(empacadora->cantTiposEmpacandoActual)+
                                               "\nGalletas por paquete: "+QString::number(empacadora->p[id]->cantGalletasPorPaquete));
            this->progressBar->setValue(((double)this->empacadora->timeNow/empacadora->p[id]->tiempoDuracion)*100);
            msleep(this->empacadora->sleepTime);

            //Stop Condition
            if(this->empacadora->timeNow == empacadora->p[id]->tiempoDuracion){
                /*if(!this->transportador->aviable){
                    waiting = true;
                    while(waiting){
                        if(this->transportador->aviable)waiting=false;
                    }
                }*/
                pause();


            }
        //}



    }
}

void ThreadEmpacadoraTransporte::stop(){
    this->running = false;

}

void ThreadEmpacadoraTransporte::pause() {
    this->paused = true;
    this->empacadora->lbtitulo->setText("Waiting...");

    this->empacadora->p[id]->totalPaquetesEmpacados += this->empacadora->cantTiposEmpacandoActual;
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

    mutexInspectorEmpacadora->lock();
    empacadora->cantTiposEmpacandoActual = empacadora->p[id]->cantEmpacado;
    empacadora->banda->cantNow -=empacadora->cantGalletasAEmpacar;
    mutexInspectorEmpacadora->unlock();


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
