#ifndef ESTRUCTURAS_PLANIFICACION_H
#define ESTRUCTURAS_PLANIFICACION_H
#include <QDebug>
#include <QString>
#include <QRandomGenerator>
// Estructura de tipos de galletas
struct TipoGalleta{
    QString nombre;
    int cantGalletas;

    int cantEmpacado;
    double tiempoEmpacado;

    TipoGalleta (QString _nombre, int _cantidad, double tiempo, int cant){
        nombre = _nombre;
        cantGalletas = _cantidad;
        cantEmpacado = cant;
        tiempoEmpacado = tiempo;
    }
    // imprime la informacion de un hijo
    void imprimir(){
        qDebug() <<"Nombre: "<<nombre<<", Cantidad: "<< cantGalletas <<"\nTiempo empacado: "<<tiempoEmpacado <<", CantEmpacado: "<<cantEmpacado;
    }
    QString toString(){
        return nombre+", "+QString::number(cantGalletas)+", "+QString::number(tiempoEmpacado)+", "+QString::number(cantEmpacado);
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

    NodoTipoGalleta(QString _nombre, int _cantidad){
        tipo->nombre = _nombre;
        tipo->cantGalletas = _cantidad;
        siguiente = anterior =NULL;
    }

};

struct ListaCircular{
    NodoTipoGalleta * primerNodo;

    ListaCircular(){
        primerNodo = NULL;
    }

    void insertar(QString name, int cant,double tiempoEmpacdo,int cantEmpacado);
    void insertar(TipoGalleta * tipo);
    bool exist(TipoGalleta * tipo);
    void imprimir();
    NodoTipoGalleta * buscar(QString name, int cant);
    NodoTipoGalleta * eliminar(QString name, int cant);
    QStringList toString();
};

struct Planificacion{
    TipoGalleta * tipoGalleta;
    int cantTipos;
    int probalidad;

    Planificacion(){
        tipoGalleta = NULL;
        cantTipos = 0;
    }

    Planificacion(TipoGalleta * _tipoGalleta, int _cantTipos){
        tipoGalleta = _tipoGalleta;
        cantTipos = _cantTipos;
    }
    void imprimir ();
    QString toString(){
        return tipoGalleta->toString()+" | "+QString::number(cantTipos);
    }

    QString toStringParaEmpacadora(){

        return QString::number(tipoGalleta->tiempoEmpacado)+" | "+QString::number(tipoGalleta->cantEmpacado)+
                " | "+QString::number(probalidad)+" | "+QString::number(cantTipos)+" | "+tipoGalleta->nombre+" | "+QString::number(tipoGalleta->cantGalletas);
    }

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
    void borrar(QString tipoGalleta, int cant);
    int getLargo();
    void imprimir();
    NodoPlanificacion* buscar(int index);
    QStringList toString();
    bool exist(Planificacion * _planificacion);
    void calcularProbalidad();
    QStringList toStringParaEmpacadora();



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
