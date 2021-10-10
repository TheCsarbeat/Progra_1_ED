
#include "main_struct.h"


Main_Struct::Main_Struct(){
    almacen = new Almacen();
    arrayMachine = new ArrayMachines();
}

Main_Struct::Main_Struct(Almacen * _almacen,  ArrayMachines * _arrayMachine){
    almacen = _almacen;
    arrayMachine = _arrayMachine;
}
