#include "main_thread.h"

thread_main::thread_main(){

}

void thread_main::__init__(MainStruct * mainStruct, EstructuraProgressBar * arrayProgressBar[40],QCheckBox * checkOnOff[40], QCheckBox * checkOnOffHorno[5]) {
    this->mainStruct = mainStruct;
    this->running = false;
    this->paused = false;

    //Array Progress Bar
    this->arrayProgressBar[0] = arrayProgressBar[0];
    this->arrayProgressBar[1] = arrayProgressBar[1];
    this->arrayProgressBar[2] = arrayProgressBar[2];
    this->arrayProgressBar[3] = arrayProgressBar[3];
    this->arrayProgressBar[4] = arrayProgressBar[4];
    this->arrayProgressBar[5] = arrayProgressBar[5];
    this->arrayProgressBar[6] = arrayProgressBar[6];
    this->arrayProgressBar[7] = arrayProgressBar[7];
    this->arrayProgressBar[8] = arrayProgressBar[8];
    this->arrayProgressBar[10] = arrayProgressBar[10];

    //Array Checkbox
    this->checkOnOff[0] = checkOnOff[0];
    this->checkOnOff[1] = checkOnOff[1];
    this->checkOnOff[2] = checkOnOff[2];
    this->checkOnOff[3] = checkOnOff[3];
    this->checkOnOff[4] = checkOnOff[4];
    this->checkOnOff[5] = checkOnOff[5]; //El horno
    this->checkOnOff[6] = checkOnOff[6];
    this->checkOnOff[7] = checkOnOff[7];
    this->checkOnOff[8] = checkOnOff[8];
    this->checkOnOff[10] = checkOnOff[10];


    //Array CheckBox Horno
    this->checkOnOffHorno[0] = checkOnOffHorno[0];
    this->checkOnOffHorno[1] = checkOnOffHorno[1];
    this->checkOnOffHorno[2] = checkOnOffHorno[2];
    this->checkOnOffHorno[3] = checkOnOffHorno[3];
    this->checkOnOffHorno[4] = checkOnOffHorno[4];

    colaPeticiones = mainStruct->colaPeticiones;

    mutexCarritoMachines = new QMutex();
    mutexMachinesEnsambladora = new QMutex();
    mutexEnsambladoraHorno = new QMutex();
    mutexHornoInspector1 = new QMutex();
    mutexInspectoresEmpacadora = new QMutex();
    mutexEmpacadoraTransporte = new QMutex();


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
            sleep(2);
        }
        msleep(1500);
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
    hiloHornoInspectores->__init__(mutexEnsambladoraHorno,mutexHornoInspector1,mainStruct->horno,mainStruct->inspectores,arrayProgressBar[5],checkOnOffHorno);
    hiloHornoInspectores->start();

    hiloInspectores[0] = new ThreadPrimerInspector();
    hiloInspectores[0]->__init__(mutexHornoInspector1, mutexInspectoresEmpacadora, mainStruct->horno, mainStruct->inspectores, mainStruct->inspectores->arrayInspectores->array[0], mainStruct->empacadora, arrayProgressBar[6], checkOnOff[5]);
    hiloInspectores[0]->start();

    hiloInspectores[1] = new ThreadPrimerInspector();
    hiloInspectores[1]->__init__(mutexHornoInspector1, mutexInspectoresEmpacadora, mainStruct->horno, mainStruct->inspectores, mainStruct->inspectores->arrayInspectores->array[1], mainStruct->empacadora, arrayProgressBar[7], checkOnOff[6]);
    hiloInspectores[1]->start();

    //Empacadora
    hiloEmpacadoraTransporte = new ThreadEmpacadoraTransporte();
    hiloEmpacadoraTransporte->__init__(mutexInspectoresEmpacadora,mutexEmpacadoraTransporte,mainStruct->empacadora,arrayProgressBar[7],checkOnOff[7]);
    hiloEmpacadoraTransporte->start();


}

void thread_main::calcularGalletas(){
    mainStruct->listaPlanificaciones->imprimir();
    for(int i= 0; i<mainStruct->listaPlanificaciones->getLargo(); i++){
        NodoPlanificacion * p = mainStruct->listaPlanificaciones->buscar(i);
        qDebug()<<"Cantidad de tipos: "<<p->planificacion->cantTipos<<", Canti galletas por tipo: "<<p->planificacion->tipoGalleta->cantGalletas;
        TotalGalletas += (p->planificacion->cantTipos * p->planificacion->tipoGalleta->cantGalletas);
    }
    cantChocolate = mainStruct->receta->cantChocolate * TotalGalletas;
    cantMezcla = mainStruct->receta->cantMezcla * TotalGalletas;

    mainStruct->almacen->totalChocolate = cantChocolate;
    mainStruct->almacen->totalMezcla = cantMezcla;

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
    mainStruct->inspectores->arrayInspectores->array[0]->state = false;
    mainStruct->inspectores->arrayInspectores->array[1]->state = false;
}

void thread_main::stop() {
    this->running = false;
    mainStruct->almacen->carrito->estado = false;
    for(int i= 0; i<3; i++){
      mainStruct->arrayMachine->array[i]->state =false;
    }
    mainStruct->ensambladora->state = false;
    mainStruct->horno->state = false;
    mainStruct->inspectores->arrayInspectores->array[0]->state = false;
    mainStruct->inspectores->arrayInspectores->array[1]->state = false;
}

void thread_main::resume() {
    qDebug()<<"La cantidad de Galletas total son: "<<TotalGalletas;
    qDebug()<<"Chocolate necesario: "<<cantChocolate;
    qDebug()<<"Mezcla necesaria: "<<cantMezcla;
    this->paused = false;
    mainStruct->almacen->carrito->estado = true;
    for(int i= 0; i<3; i++){
      mainStruct->arrayMachine->array[i]->state =true;
    }
    mainStruct->ensambladora->state = true;
    mainStruct->horno->state = true;
    mainStruct->inspectores->arrayInspectores->array[0]->state = true;
    mainStruct->inspectores->arrayInspectores->array[1]->state = true;
}
