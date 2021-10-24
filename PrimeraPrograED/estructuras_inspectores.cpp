#include "estructuras_inspectores.h"

int Inspector::inspect(){
    int rechazadas = 0, aceptadas = 0;
    rechazadas = actualGalletas * ((double)rate / 100);
    aceptadas = actualGalletas - rechazadas;
    totalRejected += rechazadas;
    totalAccepted += aceptadas;
    return aceptadas;
}

void Inspector::imprimir(){
    lbDatos->setText("Cant Actual: "+QString::number(actualGalletas)
                     +"\nMax: "+QString::number(capacidad)
                     +"\nAceptadas: "+QString::number(totalAccepted)
                     +"\nRechazadas: "+QString::number(totalRejected));
    lbDatos->update();
}

void Inspector::sumarSegundo(){
    tiempoNow++;
}

void Inspectores::imprimir(){
    arrayInspectores->array[0]->imprimir();
    arrayInspectores->array[1]->imprimir();
    arrayBandas->array[0]->imprimir();
    arrayBandas->array[1]->imprimir();
    otraBanda->imprimir();
}

