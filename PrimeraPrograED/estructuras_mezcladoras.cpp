#include "estructuras_mezcladoras.h"
Machine::Machine(){
    id = 0;
    nombre = "";
    max = 0;
    min = 0;
    cantNow = 0;
    gramosProcesar = 0;
    duracionSegudos = 0;
    tiempoActual = 0;
    state = false;
    flagEncolado = false;
    flagProcesando = false;

}
void Machine::setMax(int _max){
    max = _max;
}
void Machine::setMin(int _min){
    min = _min;
}
void Machine::setCantNow(int _cantNow){
    cantNow = _cantNow;
}
void Machine::setState(bool _state){
    state = _state;
}

void Machine::procesar(){
    tiempoActual++;
}

ArrayMachines::ArrayMachines(){
    array[0] = new Machine();
    array[0]->id = 0;
    array[0]->nombre = "Mezcladora 1";

    array[1] = new Machine();
    array[1]->id = 1;
    array[1]->nombre = "Mezcladora 2";

    array[2] = new Machine();
    array[2]->id = 2;
    array[2]->nombre = "Chocolatera";
}



