#ifndef MAIN_STRUCT_H
#define MAIN_STRUCT_H

#include "estructuras_planificacion.h"
#include "estructuras_almacen.h"
#include "estructuras_mezcladoras.h"
#include "estructuras_ensambladora.h"
#include "estructuras_peticiones.h"
#include "estructuras_progressbar.h"
#include "estructuras_horno.h"
#include "estructuras_inspectores.h"
#include "estructuras_empacadora.h"

#include <QLabel>
struct MainStruct{

    ListaCircular *listaCircularTiposGalletas ;
    ListaSimplePlanificaciones * listaPlanificaciones ;
    Almacen * almacen;
    ArrayMachines * arrayMachine;
    ColaPeticiones * colaPeticiones;
    Ensambladora * ensambladora;
    Receta * receta;
    Horno * horno;
    Inspectores * inspectores;
    Empacadora *empacadora;

    MainStruct();
    MainStruct(Almacen * _almacen,  ArrayMachines * _arrayMachine, Receta * _receta,ColaPeticiones * cola, Ensambladora * assembler, Horno * _horno, ListaCircular *listC, ListaSimplePlanificaciones * listP, Empacadora *em);

    void encolarPeticiones();

    void requestRawMaterial();
};

#endif // MAIN_STRUCT_H
