#ifndef MAIN_STRUCT_H
#define MAIN_STRUCT_H

#include "estructuras_planificacion.h"
#include "estructuras_almacen.h"
#include "estructuras_mezcladoras.h"
#include "estructuras_ensambladora.h"
#include "estructuras_peticiones.h"
#include "estructuras_progressbar.h"
#include "estructuras_horno.h"

#include <QLabel>
struct MainStruct{

    Almacen * almacen;
    ArrayMachines * arrayMachine;
    ColaPeticiones * colaPeticiones;
    Ensambladora * ensambladora;
    Receta * receta;
    Horno * horno;

    MainStruct();
    MainStruct(Almacen * _almacen,  ArrayMachines * _arrayMachine, Receta * _receta,ColaPeticiones * cola, Ensambladora * assembler, Horno * _horno);

    void encolarPeticiones();

    void requestRawMaterial();
};

#endif // MAIN_STRUCT_H
