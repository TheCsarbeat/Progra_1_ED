#include "main_thread.h"

thread_main::thread_main(){

}

void thread_main::__init__(MainStruct * mainStruct, QFrame *mainPanel, EstructuraProgressBar * arrayProgressBar[40],QCheckBox * checkOnOff[40]) {
    this->mainStruct = mainStruct;
    this->running = false;
    this->paused = false;
    this->mainPanel = mainPanel;

    //Array Progress Bar
    this->arrayProgressBar[0] = arrayProgressBar[0];
    this->arrayProgressBar[1] = arrayProgressBar[1];
    this->arrayProgressBar[2] = arrayProgressBar[2];
    this->arrayProgressBar[3] = arrayProgressBar[3];

    //Array Checkbox
    this->checkOnOff[0] = checkOnOff[0];
    this->checkOnOff[1] = checkOnOff[1];
    this->checkOnOff[2] = checkOnOff[2];
    this->checkOnOff[3] = checkOnOff[3];


    colaPeticiones = mainStruct->colaPeticiones;
    mutexMachinesEnsabladora = new QMutex();
    mutexMachinesCarrito = new QMutex();

}

void thread_main::run() {
    this->running = true;
    encolar();
    while (running) {
        while (paused) {
            sleep(1);
        }

        arrancarCarrito();
        arrancarMezcladoras();


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

void thread_main::arrancarCarrito(){
    bool libreCarrito = mainStruct->almacen->carrito->libre;
    if(!colaPeticiones->vacia() && libreCarrito == true){
        Peticion * peticion = colaPeticiones->verFrente()->peticion;

        hiloCarritoMachines = new ThreadAlmacenMachines();
        hiloCarritoMachines->__init__(mainStruct->almacen, mainStruct->arrayMachine->array[peticion->idMachine], mutexMachinesCarrito,colaPeticiones,arrayProgressBar[0], checkOnOff[0]);
        hiloCarritoMachines->start();
    }
}

void thread_main::arrancarMezcladoras(){
    for(int i= 0; i<3; i++){
            int cantNow = mainStruct->arrayMachine->array[i]->cantNow;
            int cantMin = mainStruct->arrayMachine->array[i]->min;
            bool flagProcesando = mainStruct->arrayMachine->array[i]->flagProcesando;

        if(cantNow >= cantMin && flagProcesando == false){
            mainStruct->arrayMachine->array[i]->flagProcesando = true;
            hiloMachinesEnsambladora[i] = new ThreadMachinesEnsambladora();
            hiloMachinesEnsambladora[i]->__init__(mainStruct->arrayMachine->array[i], colaPeticiones, mainStruct->ensambladora, mutexMachinesEnsabladora,arrayProgressBar[i+1], checkOnOff[i+1]);
            hiloMachinesEnsambladora[i]->start();
            msleep(300);
        }else{
            bool flagHiloStop = true;
        }
    }
}

void thread_main::arrancarEnsambladora(){
    /*
    int cantMezcla = mainStruct->ensambladora->cant * mainStruct->receta->cantMezcla;
    int cantChoco = mainStruct->ensambladora->cant * mainStruct->receta->cantChocolate;
    int banda1Now = mainStruct->ensambladora->bandas->array[0]->cantNow;
    int banda2Now = mainStruct->ensambladora->bandas->array[1]->cantNow;
    if(banda2Now>=cantChoco && banda)
    */
}

void thread_main::imprimirDatos(){
    mainStruct->almacen->carrito->imprimir();
    for(int i= 0; i<3; i++)mainStruct->arrayMachine->array[i]->imprimirDatos();
}

void thread_main::pause() {
    this->paused = true;
}

void thread_main::stop() {
    this->running = false;
}

void thread_main::resume() {
    this->paused = false;
}
