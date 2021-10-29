#include "estructuras_ensambladora.h"

void Banda::imprimir(){
    lbDatos->setText("Cant Actual: "+QString::number(cantNow)
                     +"\nMax: "+QString::number(capacidad));
}
void Ensambladora::sumarSegundo(){
    timeActual++;
}

int Ensambladora::makeCookies(int mezcla, int choco){
    bandas->array[0]->cantNow-= (mezcla * cant);
    bandas->array[1]->cantNow-= (choco * cant);
    bandas->array[0]->imprimir();
    bandas->array[1]->imprimir();
    return cant;
}

void Ensambladora::imprimir(){
    lbDatos->setText("Galletas Hechas: "+QString::number(galletasHechas));
}


