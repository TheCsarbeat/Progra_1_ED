#ifndef ESTRUCTURAS_INSPECTORES_H
#define ESTRUCTURAS_INSPECTORES_H

#include "estructuras_ensambladora.h"

struct Inspectores;
struct ArrayInspectores;
struct Inspector;

struct Inspector{
    int id;

    Inspector(int _id){
        id = _id;
    }
};

struct ArrayInspectores{
    Inspector * array[2];

    ArrayInspectores(){
        array[0] = new Inspector(1);
        array[1] = new Inspector(2);
    }
};

struct Inspectores{
    ArrayInspectores * inspectores;

    Inspectores(){
        inspectores = new ArrayInspectores();
    }
};

#endif // ESTRUCTURAS_INSPECTORES_H
