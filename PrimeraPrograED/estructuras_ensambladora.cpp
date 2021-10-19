#include "estructuras_ensambladora.h"

void Ensambladora::sumarSegundo(){
    timeActual++;
}

int Ensambladora::makeCookies(int mezcla, int choco){
    bandas->array[0]->cantNow-= (mezcla * cant);
    bandas->array[1]->cantNow-= (choco * cant);
    return cant;
}
