#include "estructuras_horno.h"

void Bandeja::sumarHorneadas(){
    totalHorneado += capacidad;
}
void Bandeja::imprimir(){
    lbDatos->setText("Cant Actual: "+QString::number(cantGalletasNow) //segmentation fault arreglar
                     +"\nMax: "+QString::number(capacidad)
                     +"\nHorneadas: "+QString::number(totalHorneado));
}

void Horno::apagarBandejas(){
    for(unsigned int i = 2; i < 6;i++){
        bandejas->array[i]->active = false;
    }
}

bool Horno::llenarBandejas(){
    if(banda->cantNow > 0){
        for(unsigned int i = 0; i < 6;i++){
                if(bandejas->array[i]->cantGalletasNow < bandejas->array[i]->capacidad && bandejas->array[i]->active){
                    if(cantidadRellenado <= banda->cantNow){
                        int suma = bandejas->array[i]->cantGalletasNow + cantidadRellenado;
                        if(suma <= bandejas->array[i]->capacidad){
                            bandejas->array[i]->cantGalletasNow = suma;
                            banda->cantNow -= cantidadRellenado;
                            return true;
                        }else if(bandejas->array[i]->nombre != "Bandeja 6" && bandejas->array[i+1]->active){
                            int overflow = suma - bandejas->array[i]->capacidad;
                            bandejas->array[i]->cantGalletasNow = bandejas->array[i]->capacidad;
                            bandejas->array[i+1]->cantGalletasNow += overflow;
                            banda->cantNow -= cantidadRellenado;
                            return true;
                        }else{
                            int diferencia = bandejas->array[i]->capacidad - bandejas->array[i]->cantGalletasNow;
                            bandejas->array[i]->cantGalletasNow = bandejas->array[i]->capacidad;
                            banda->cantNow -= diferencia;
                            return true;
                        }
                    }else{                       
                        return false;
                    }
                }
        }

    }
    return false;
}

void Horno::sumarSegundo(){
    tiempoNow++;
}

int Horno::getCurrentCantidad(){
    int cantidadTotal = 0;
    for(unsigned int i = 0; i < 6;i++){
        if(bandejas->array[i]->active == true){
         cantidadTotal+=bandejas->array[i]->cantGalletasNow;
        }
    }
    return cantidadTotal;
}

int Horno::hornear(){
    int horneadas = 0;
    for(unsigned int i = 0; i < 6;i++){
        if(bandejas->array[i]->active == true){
            bandejas->array[i]->sumarHorneadas();
            horneadas += bandejas->array[i]->capacidad;
            bandejas->array[i]->cantGalletasNow = 0;
        }
    }
    return horneadas;
}

void Horno::imprimir(){
    for(unsigned int i = 0; i < 6;i++){
        bandejas->array[i]->imprimir();
    }
    banda->imprimir();
}
