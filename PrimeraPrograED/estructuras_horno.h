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
        lbDatos = new QLabel;
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
    ArrayBandejas(){
        array[0] = new Bandeja("Bandeja 1",new QLabel);
        array[1] = new Bandeja("Bandeja 2",new QLabel);
        array[2] = new Bandeja("Bandeja 3",new QLabel);
        array[3] = new Bandeja("Bandeja 4",new QLabel);
        array[4] = new Bandeja("Bandeja 5",new QLabel);
        array[5] = new Bandeja("Bandeja 6",new QLabel);
    }
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
    int tiempoRellenado;
    int cantidadRellenado;
    bool state;
    Horno(){
        banda = new Banda("Banda Horno",new QLabel);
        bandejas = new ArrayBandejas();
        flagProcesando = false;
        tiempoHorneado = 0;
        cantidadRellenado = 0;
        tiempoRellenado = 0;
        tiempoNow = 0;
        state = true;
    }
    Horno(QLabel * lbDatosBanda, int _cantidadRellenado, int _tiempoRellenado, int _tiempoHorneado,QLabel * _lbTitulo, QLabel * arrayLbBandejas[6]){
        banda = new Banda("Banda Horno",lbDatosBanda);
        bandejas = new ArrayBandejas(arrayLbBandejas);
        lbTitulo = _lbTitulo;
        flagProcesando = false;
        tiempoHorneado = _tiempoHorneado;
        cantidadRellenado = _cantidadRellenado;
        tiempoRellenado = _tiempoRellenado;
        tiempoNow = 0;
        state = true;
    }
    int getCurrentCantidad();
    int getCapacidad();
    void apagarBandeja();
    bool llenarBandejas();
    void sumarSegundo();
    int hornear();
    void imprimir();
};





#endif // ESTRUCTURAS_HORNO_H
