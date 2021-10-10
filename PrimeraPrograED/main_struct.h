#ifndef MAIN_STRUCT_H
#define MAIN_STRUCT_H

#include "estructuras_planificacion.h"
#include "estructuras_almacen.h"
#include "estructuras_mezcladoras.h"


struct Main_Struct{

    Almacen * almacen;
    ArrayMachines * arrayMachine;

    Main_Struct();
    Main_Struct(Almacen * _almacen,  ArrayMachines * _arrayMachine);

    void requestRawMaterial();
};

#endif // MAIN_STRUCT_H
