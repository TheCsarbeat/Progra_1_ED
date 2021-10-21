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
    this->running = true;
    encolar();
    iniciarThreads();
    while (running) {
        while (paused) {
            sleep(1);
        }

        arrancarCarrito();
        arrancarMezcladoras();
        arrancarEnsambladora();
        arrancarHorno();

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
        hiloCarritoMachines[peticion->idMachine]->start();
    }
}

void thread_main::arrancarMezcladoras(){
    for(int i= 0; i<3; i++){
            int cantNow = mainStruct->arrayMachine->array[i]->cantNow;
            int cantMin = mainStruct->arrayMachine->array[i]->min;
            bool flagProcesando = mainStruct->arrayMachine->array[i]->flagProcesando;


        if(cantNow >= cantMin && flagProcesando == false){
            mainStruct->arrayMachine->array[i]->flagProcesando = true;
            hiloMachinesEnsambladora[i]->start();
            msleep(300);
        }
    }
}

void thread_main::arrancarEnsambladora(){

    int cantMezcla = mainStruct->ensambladora->cant * mainStruct->receta->cantMezcla;
    int cantChoco = mainStruct->ensambladora->cant * mainStruct->receta->cantChocolate;
    int banda1Now = mainStruct->ensambladora->bandas->array[0]->cantNow;
    int banda2Now = mainStruct->ensambladora->bandas->array[1]->cantNow;

    bool flagEnsambladora = mainStruct->ensambladora->flagProcesando;
    if(banda1Now>=cantMezcla && banda2Now>=cantChoco && !flagEnsambladora){
        mainStruct->ensambladora->flagProcesando = true;
        hiloEnsambladoraHorno->start();
    }
    msleep(500);
}

void thread_main::arrancarHorno(){
    qDebug() << "Entro a arrancar horno";
    int flag = mainStruct->horno->flagProcesando;
    //int cantNow = mainStruct->horno->getCurrentCantidad();
    //int capacidad = mainStruct->horno->capacidad;
    if(!flag && mainStruct->horno->banda->cantNow > 0){
        qDebug() << "Entro al if de que puede procesar";
        hiloHornoInspectores->start();
    }
}

void thread_main::iniciarThreads(){

    for(int i= 0; i<3; i++){
        hiloCarritoMachines[i] = new ThreadAlmacenMachines();
        hiloCarritoMachines[i]->__init__(mainStruct->almacen, mainStruct->arrayMachine->array[i], mutexCarritoMachines,colaPeticiones,arrayProgressBar[0], checkOnOff[0]);

        //MachinesEnsambladora
        hiloMachinesEnsambladora[i] = new ThreadMachinesEnsambladora();
        hiloMachinesEnsambladora[i]->__init__(mainStruct->arrayMachine->array[i], colaPeticiones, mainStruct->ensambladora, mutexCarritoMachines,mutexMachinesEnsambladora,arrayProgressBar[i+1], checkOnOff[i+1]);
        msleep(100);
    }

    //Ensambladora
    hiloEnsambladoraHorno = new ThreadEnsambladoraHorno();
    hiloEnsambladoraHorno->__init__(mutexMachinesEnsambladora,mutexEnsambladoraHorno, mainStruct->ensambladora,mainStruct->horno,mainStruct->receta, arrayProgressBar[4], checkOnOff[4]);

    //Horno
    hiloHornoInspectores = new ThreadHornoInspectores();
    hiloHornoInspectores->__init__(mutexEnsambladoraHorno,mutexHornoInspectores,mainStruct->horno,mainStruct->inspectores,arrayProgressBar[5],checkOnOff[5]);
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
