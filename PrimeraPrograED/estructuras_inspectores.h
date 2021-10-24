#ifndef ESTRUCTURAS_INSPECTORES_H
#define ESTRUCTURAS_INSPECTORES_H

#include "estructuras_ensambladora.h"

struct Inspectores;
struct ArrayInspectores;
struct Inspector;

struct Inspector{
    int id;
    bool state;
    bool flagProcesando;
    int rate;
    int actualGalletas;
    int capacidad;
    int tiempoNow;
    int tiempo;
    int totalRejected;
    int totalAccepted;
    QLabel * lbTitle;
    QLabel * lbDatos;
    QString nombre;

    Inspector(){
        id = 0;
        state = true;
        flagProcesando = false;
        rate = 0;
        actualGalletas = 0;
        capacidad = 0;
        tiempo = 0;
        tiempoNow = 0;
        totalAccepted = 0;
        totalRejected = 0;
        lbDatos = new QLabel();
        lbTitle = new QLabel();
        nombre = "";
    }
    Inspector(int _id, QString name){
        id = _id;
        state = true;
        flagProcesando = false;
        rate = 0;
        actualGalletas = 0;
        capacidad = 0;
        tiempo = 0;
        tiempoNow = 0;
        totalAccepted = 0;
        totalRejected = 0;
        lbDatos = new QLabel();
        lbTitle = new QLabel();
        nombre = name;
    }

    int inspect();
    void imprimir();
    void sumarSegundo();
};

struct ArrayInspectores{
    Inspector * array[2];

    ArrayInspectores(){
        array[0] = new Inspector(0, "Inspector 1");
        array[1] = new Inspector(1, "Inspector 2");
    }
};


struct Inspectores{
    ArrayBandas * arrayBandas;
    ArrayInspectores * arrayInspectores;
    Banda * otraBanda;

    Inspectores(){
        arrayBandas = new ArrayBandas();
        arrayInspectores = new ArrayInspectores();
        otraBanda = new Banda();
    }
    Inspectores(QLabel * lbDatos1, QLabel * lbDatos2){
        arrayBandas = new ArrayBandas(lbDatos1, lbDatos2, "Banda sin inspeccionar", "Banda del medio");
        arrayInspectores = new ArrayInspectores();
        otraBanda = new Banda();
    }
    void imprimir();
};

#endif // ESTRUCTURAS_INSPECTORES_H
