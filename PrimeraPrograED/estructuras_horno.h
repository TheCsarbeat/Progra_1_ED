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
    int totalHorneado;
    bool active;
    QLabel * lbDatos;

    Bandeja(){
        nombre = "";
        cantGalletasNow = 0;
        capacidad = 0;
        active = false;
        totalHorneado = 0;
    }
    Bandeja(QString _nombre, QLabel * _lbDatos){
        nombre = _nombre;
        capacidad = 0;
        cantGalletasNow = 0;
        active = true;
        lbDatos = _lbDatos;
        totalHorneado = 0;
    }

    void sumarHorneadas();
    void imprimir();
};

struct ArrayBandejas{
    Bandeja * array[6];

    ArrayBandejas(QLabel * arrayLbBandejas[6]){
        array[0] = new Bandeja("Bandeja 1",arrayLbBandejas[0]);
        array[1] = new Bandeja("Bandeja 2",arrayLbBandejas[1]);
        array[2] = new Bandeja("Bandeja 3",arrayLbBandejas[2]);
        array[3] = new Bandeja("Bandeja 4",arrayLbBandejas[3]);
        array[4] = new Bandeja("Bandeja 5",arrayLbBandejas[4]);
        array[5] = new Bandeja("Bandeja 6",arrayLbBandejas[5]);
    }
};


struct Horno{
    Banda * banda;
    ArrayBandejas * bandejas;
    QLabel * lbTitulo;
    bool flagProcesando;
    int tiempoHorneado;
    int tiempoNow;
    int capacidad;
    int tiempoRellenado;
    int cantidadRellenado;

    Horno(QLabel * lbDatosBanda, int _capacidad, int _cantidadRellenado, int _tiempoRellenado,QLabel * _lbTitulo, QLabel * arrayLbBandejas[6]){
        banda = new Banda("Banda Horno",lbDatosBanda);
        bandejas = new ArrayBandejas(arrayLbBandejas);
        lbTitulo = _lbTitulo;
        flagProcesando = false;
        tiempoHorneado = 0;
        capacidad = _capacidad;
        cantidadRellenado = _cantidadRellenado;
        tiempoRellenado = _tiempoRellenado;
    }
    int getCurrentCantidad();
    void apagarBandejas();
    bool llenarBandejas();
    void sumarSegundo();
    int hornear();
    void imprimir();
};





#endif // ESTRUCTURAS_HORNO_H
