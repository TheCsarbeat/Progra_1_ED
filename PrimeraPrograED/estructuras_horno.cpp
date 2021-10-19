#include "estructuras_horno.h"

void Horno::setCapacidad(){
    int capacidadTotal = 0;
    for(unsigned int i = 0; i < sizeof(bandejas);i++){
        capacidadTotal+=bandejas->array[i]->capacidad;
    }
    this->capacidadGalletas = capacidadTotal;
}

void Horno::apagarBandejas(){
    for(unsigned int i = 2; i < sizeof(bandejas);i++){
        bandejas->array[i]->active = false;
    }
}

void Horno::llenarBandejas(){
    if(banda->cantNow > 0){
        for(unsigned int i = 0; i < sizeof(bandejas);i++){
                while(bandejas->array[i]->cantGalletasNow > bandejas->array[i]->capacidad){
                    bandejas->array[i]->cantGalletasNow++;
                    banda->cantNow--;
                    if(banda->cantNow == 0){
                        return;
                    }
                }
        }
    }
}

void Horno::sumarSegundo(){
    tiempoNow++;
}
