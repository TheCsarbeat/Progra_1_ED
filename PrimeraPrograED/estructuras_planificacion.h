#ifndef ESTRUCTURAS_PLANIFICACION_H
#define ESTRUCTURAS_PLANIFICACION_H
#include <QDebug>
#include <QString>

// Estructura de tipos de galletas
struct TipoGalleta{
    QString nombre;
    int cantGalletas;

    TipoGalleta (QString _nombre, int _cantidad){
        nombre = _nombre;
        cantGalletas = _cantidad;
    }
    // imprime la informacion de un hijo
    void imprimir(){
        qDebug() <<nombre<<"\t(" << cantGalletas <<")\n";
    }
};

struct NodoTipoGalleta{
    TipoGalleta * tipo;
    NodoTipoGalleta * siguiente;
    NodoTipoGalleta * anterior;

    NodoTipoGalleta(TipoGalleta * _tipo){
        tipo = _tipo;
        siguiente = anterior =NULL;
    }
};

struct ListaCircular{
    NodoTipoGalleta * primerNodo;

    ListaCircular(){
        primerNodo = NULL;
    }

    void insertar(QString name, int cant);
    void imprimir();
    NodoTipoGalleta * buscar(QString name, int cant);
    NodoTipoGalleta * eliminar(QString name, int cant);
};

struct Planificacion{
    TipoGalleta * tipoGalleta;
    int cantTipos;

    Planificacion(){
        tipoGalleta = NULL;
        cantTipos = 0;
    }

    Planificacion(TipoGalleta * _tipoGalleta, int _cantTipos){
        tipoGalleta = _tipoGalleta;
        cantTipos = _cantTipos;
    }
    void imprimir ();

};
//Estructura de plafinicacion
struct NodoPlanificacion{
    Planificacion * planificacion;
    NodoPlanificacion *siguiente;

    NodoPlanificacion(){
        planificacion = NULL;
        siguiente = NULL;

    }
    NodoPlanificacion(Planificacion * _planificacion){
        planificacion = _planificacion;
        siguiente = NULL;
    }
    void imprimir ();

};

struct ListaSimplePlanificaciones{
    NodoPlanificacion * primerNodo, *ultimoNodo;

    int largo;

    ListaSimplePlanificaciones(){
        primerNodo = ultimoNodo= NULL;
        largo = 0;
    }

    bool isEmpty();
    void insertarAlInicio(Planificacion * _planificacion);
    NodoPlanificacion* borrarAlInicio();
    int getLargo();
    void imprimir();
};
struct Receta{
    int cantMezcla;
    int cantChocolate;

    Receta(){
        cantMezcla = 0;
        cantChocolate = 0;
    }
    Receta(int _cantMezcla, int _cantChocolate){
        cantMezcla = _cantMezcla;
        cantChocolate = _cantChocolate;
    }
};

#endif // ESTRUCTURAS_PLANIFICACION_H
