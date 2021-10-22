#include "main_thread.h"

thread_main::thread_main(){

}

void thread_main::__init__(MainStruct * mainStruct, EstructuraProgressBar * arrayProgressBar[40],QCheckBox * checkOnOff[40]) {
    this->mainStruct = mainStruct;
    this->running = false;
    this->paused = false;

    //Array Progress Bar
    this->arrayProgressBar[0] = arrayProgressBar[0];
    this->arrayProgressBar[1] = arrayProgressBar[1];
    this->arrayProgressBar[2] = arrayProgressBar[2];
    this->arrayProgressBar[3] = arrayProgressBar[3];
    this->arrayProgressBar[4] = arrayProgressBar[4];

    //Array Checkbox
    this->checkOnOff[0] = checkOnOff[0];
    this->checkOnOff[1] = checkOnOff[1];
    this->checkOnOff[2] = checkOnOff[2];
    this->checkOnOff[3] = checkOnOff[3];
    this->checkOnOff[4] = checkOnOff[4];


    colaPeticiones = mainStruct->colaPeticiones;


    mutexCarritoMachines = new QMutex();
    mutexMachinesEnsambladora = new QMutex();
    mutexEnsambladoraHorno = new QMutex();
    mutexHornoInspectores = new QMutex();

}

void thread_main::run() {
    //

    mainStruct->almacen->carrito->estado = true;
    for(int i= 0; i<3; i++){
      mainStruct->arrayMachine->array[i]->state =true;
    }
    calcularGalletas();
    this->running = true;
    encolar();
    iniciarThreads();

    while (running) {
        while (paused) {
            sleep(1);
        }
        //arrancarHorno();
        msleep(500);
    }

}

void thread_main::encolar(){
    for(int i= 0; i<3; i++){
            int cantNow = mainStruct->arrayMachine->array[i]->cantNow;
            int cantMin = mainStruct->arrayMachine->array[i]->min;
            int cantMax = mainStruct->arrayMachine->array[i]->max;
            bool flagProcesando = mainStruct->arrayMachine->array[i]->flagProcesando;

        if(cantNow <= cantMin && flagProcesando == false){
            colaPeticiones->encolar(mainStruct->arrayMachine->array[i]->nombre, cantMax-cantNow, i);
            mainStruct->arrayMachine->array[i]->flagEncolado = true;
        }
    }
}

void thread_main::arrancarHorno(){
    int flag = mainStruct->horno->flagProcesando;
    //int cantNow = mainStruct->horno->getCurrentCantidad();
    //int capacidad = mainStruct->horno->capacidad;
    if(!flag && mainStruct->horno->banda->cantNow > 0){
        hiloHornoInspectores->start();
    }
}

void thread_main::iniciarThreads(){

    hiloCarritoMachines = new ThreadAlmacenMachines();
    hiloCarritoMachines->__init__(mainStruct->almacen, mainStruct->arrayMachine, mutexCarritoMachines,colaPeticiones,arrayProgressBar[0], checkOnOff[0]);
    hiloCarritoMachines->start();

    for(int i= 0; i<3; i++){

        //MachinesEnsambladora
        hiloMachinesEnsambladora[i] = new ThreadMachinesEnsambladora();
        hiloMachinesEnsambladora[i]->__init__(mainStruct->arrayMachine->array[i], colaPeticiones, mainStruct->ensambladora, mutexCarritoMachines,mutexMachinesEnsambladora,arrayProgressBar[i+1], checkOnOff[i+1]);
        hiloMachinesEnsambladora[i]->start();
        msleep(100);
    }


    //Ensambladora
    hiloEnsambladoraHorno = new ThreadEnsambladoraHorno();
    hiloEnsambladoraHorno->__init__(mutexMachinesEnsambladora,mutexEnsambladoraHorno, mainStruct->ensambladora,mainStruct->horno,mainStruct->receta, arrayProgressBar[4], checkOnOff[4]);
    hiloEnsambladoraHorno->start();



    //Horno
    hiloHornoInspectores = new ThreadHornoInspectores();
    hiloHornoInspectores->__init__(mutexEnsambladoraHorno,mutexHornoInspectores,mainStruct->horno,mainStruct->inspectores,arrayProgressBar[5],checkOnOff[5]);
    hiloHornoInspectores->start();


}

void thread_main::calcularGalletas(){
    int cantMezcla = 0, cantChocolate =0 , TotalGalletas =0;
    for(int i= 0; i<mainStruct->listaPlanificaciones->getLargo(); i++){
        NodoPlanificacion * p = mainStruct->listaPlanificaciones->buscar(i);
        TotalGalletas += (p->planificacion->cantTipos * p->planificacion->tipoGalleta->cantGalletas);
    }
    cantChocolate = mainStruct->receta->cantChocolate * TotalGalletas;
    cantMezcla = mainStruct->receta->cantMezcla * TotalGalletas;

    qDebug()<<"La cantidad de Galletas total son: "<<TotalGalletas;
    qDebug()<<"Chocolate necesario: "<<cantChocolate;
    qDebug()<<"Mezcla necesaria: "<<cantMezcla;
}



void thread_main::pause() {
    this->paused = true;
    mainStruct->almacen->carrito->estado = false;
    for(int i= 0; i<3; i++){
      mainStruct->arrayMachine->array[i]->state =false;
    }
    mainStruct->ensambladora->state = false;
    mainStruct->horno->state = false;
}

void thread_main::stop() {
    this->running = false;
    mainStruct->almacen->carrito->estado = false;
    for(int i= 0; i<3; i++){
      mainStruct->arrayMachine->array[i]->state =false;
    }
    mainStruct->ensambladora->state = false;
    mainStruct->horno->state = false;
}

void thread_main::resume() {
    this->paused = false;
    mainStruct->almacen->carrito->estado = true;
    for(int i= 0; i<3; i++){
      mainStruct->arrayMachine->array[i]->state =true;
    }
    mainStruct->ensambladora->state = true;
    mainStruct->horno->state = true;
}
