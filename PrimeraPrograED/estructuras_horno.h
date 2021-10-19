#ifndef ESTRUCTURAS_HORNO_H
#define ESTRUCTURAS_HORNO_H

#include "estructuras_ensambladora.h"

struct Horno;
struct Bandeja;
struct ArrayBandejas;

struct Bandeja{
    QString nombre;
    int cantGalletasNow;
    int capacidad;
    bool active;

    Bandeja(){
        nombre = "";
        cantGalletasNow = 0;
        capacidad = 0;
        active = false;
    }
    Bandeja(QString _nombre){
        nombre = _nombre;
        capacidad = 0;
        cantGalletasNow = 0;
        active = true;
    }
};

struct ArrayBandejas{
    Bandeja * array[6];

    ArrayBandejas(){
        array[0] = new Bandeja("Bandeja 1");
        array[1] = new Bandeja("Bandeja 2");
        array[2] = new Bandeja("Bandeja 3");
        array[3] = new Bandeja("Bandeja 4");
        array[4] = new Bandeja("Bandeja 5");
        array[5] = new Bandeja("Bandeja 6");
    }
};


struct Horno{
    Banda * banda;
    ArrayBandejas * bandejas;
    int capacidadGalletas;
    bool encendido;
    int tiempoHorneado;
    int tiempoNow;

    Horno(){
        banda = new Banda();
        bandejas = new ArrayBandejas();
        capacidadGalletas = 0;
        encendido = true;
        tiempoHorneado = 0;
    }

    void setCapacidad();
    void apagarBandejas();
    void llenarBandejas();
    void sumarSegundo();
};





#endif // ESTRUCTURAS_HORNO_H
