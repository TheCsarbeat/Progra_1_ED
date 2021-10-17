#ifndef MAIN_STRUCT_H
#define MAIN_STRUCT_H

#include "estructuras_planificacion.h"
#include "estructuras_almacen.h"
#include "estructuras_mezcladoras.h"
#include "estructuras_ensambladora.h"
#include "estructuras_peticiones.h"

struct MainStruct{

    Almacen * almacen;
    ArrayMachines * arrayMachine;
    ColaPeticiones * colaPeticiones;
    Ensambladora * ensambladora;

    MainStruct();
    MainStruct(Almacen * _almacen,  ArrayMachines * _arrayMachine);

    void encolarPeticiones();

    void requestRawMaterial();
};

#endif // MAIN_STRUCT_H
