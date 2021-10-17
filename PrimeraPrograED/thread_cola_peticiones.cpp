#include "thread_cola_peticiones.h"

ThreadColaPeticiones::ThreadColaPeticiones()
{

}

void ThreadColaPeticiones::__init__(Almacen * almacen, bool * flagCarritoProcesando, bool * flagCarritoEncolado, bool * running, ColaPeticiones * colaPeticiones){
    this->almacen = almacen;
    this->flagCarritoProcesando = flagCarritoProcesando;
    this->running = running;
    this->colaPeticiones;
}

void ThreadColaPeticiones::run(){

}
