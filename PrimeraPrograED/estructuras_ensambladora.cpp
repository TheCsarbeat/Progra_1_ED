#include "estructuras_ensambladora.h"

void Banda::imprimir(){
    lbDatos->setText("Cant Actual: "+QString::number(cantNow)
                     +"\nMax: "+QString::number(capacidad));
    lbDatos->update();
}
void Ensambladora::sumarSegundo(){
    if(timeActual==0){
        double num = duracionSegundos- (int)duracionSegundos;

        timeActual = num;
        sleepTime = num*1000;
        if(num==0){
            timeActual ++;
            sleepTime =1000;
        }
    }else{
        timeActual ++;
        sleepTime =1000;
    }
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
    lbDatos->update();
}


