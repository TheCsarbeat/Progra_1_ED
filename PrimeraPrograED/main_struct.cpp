
#include "main_struct.h"


MainStruct::MainStruct(){
    almacen = new Almacen();
    arrayMachine = new ArrayMachines();
    colaPeticiones = new ColaPeticiones();
}

MainStruct::MainStruct(Almacen * _almacen,  ArrayMachines * _arrayMachine, Receta * _receta, ColaPeticiones * cola){
    almacen = _almacen;
    arrayMachine = _arrayMachine;
    colaPeticiones = cola;
    receta = _receta;
}

void MainStruct::encolarPeticiones(){
    for(int i= 0; i<3; i++){
        int cantNow = arrayMachine->array[i]->cantNow;
        int cantMax = arrayMachine->array[i]->max;
        colaPeticiones->encolar(arrayMachine->array[i]->nombre, cantMax-cantNow, i);
    }
}
