
#include "main_struct.h"


MainStruct::MainStruct(){
    almacen = new Almacen();
    arrayMachine = new ArrayMachines();
    colaPeticiones = new ColaPeticiones();
    listaCircularTiposGalletas = new ListaCircular();
    listaPlanificaciones = new ListaSimplePlanificaciones();

    ensambladora = new Ensambladora();
    receta = new Receta();
    horno = new Horno();
    inspectores = new Inspectores();
}


MainStruct::MainStruct(Almacen * _almacen,  ArrayMachines * _arrayMachine, Receta * _receta, ColaPeticiones * cola, Ensambladora * assembler,
                       Horno * _horno, Inspectores * _inspectores,ListaCircular *listC, ListaSimplePlanificaciones * listP, Empacadora *em, ArrayTransportadores *transpo){
    almacen = _almacen;
    arrayMachine = _arrayMachine;
    colaPeticiones = cola;
    receta = _receta;
    horno = _horno;
    ensambladora = assembler;
    inspectores = _inspectores;
    listaCircularTiposGalletas = listC;
    listaPlanificaciones = listP;
    empacadora = em;
    arrayTransportadores = transpo;
}

void MainStruct::encolarPeticiones(){
    for(int i= 0; i<3; i++){
        int cantNow = arrayMachine->array[i]->cantNow;
        int cantMax = arrayMachine->array[i]->max;
        colaPeticiones->encolar(arrayMachine->array[i]->nombre, cantMax-cantNow, i);
    }
}
