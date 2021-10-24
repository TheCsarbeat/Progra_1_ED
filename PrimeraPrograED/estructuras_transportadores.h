#ifndef ESTRUCTURAS_TRANSPORTADORES_H
#define ESTRUCTURAS_TRANSPORTADORES_H

#include <QDebug>
#include <QString>
#include <QLabel>

#include "estructuras_planificacion.h"

struct Transportadores;
struct NodoTransportador;
struct Transportador;

struct Transportador{
    int capacidad;
    int cantNow;
    bool busy;
    QString nombre;
    TipoGalleta * tipoPaquete;

    Transportador(){
        capacidad = 0;
        nombre = "";
        tipoPaquete = NULL;
        busy = false;
        cantNow = 0;
    }

    Transportador(int _capacidad, QString _nombre, TipoGalleta * _tipoPaquete){
        capacidad = _capacidad;
        nombre = _nombre;
        tipoPaquete = _tipoPaquete;
        busy = false;
        cantNow = 0;
    }
};

struct NodoTransportador{
    Transportador * transportador;
    NodoTransportador * siguiente;

    NodoTransportador(){
        transportador = NULL;
        siguiente = NULL;
    }
    NodoTransportador(Transportador * _transportador){
        transportador = _transportador;
        siguiente = NULL;
    }
};

struct ListaTransportadores{
    NodoTransportador * primerNodo;
    NodoTransportador * ultimoNodo;
    int largo;

    ListaTransportadores(){
        primerNodo = ultimoNodo = NULL;
        largo = 0;
    }

    void insertar(Transportador * transportador);
    NodoTransportador * buscar(QString name);
    void agregarPaquete(QString name, int cant);
};

#endif // ESTRUCTURAS_TRANSPORTADORES_H
