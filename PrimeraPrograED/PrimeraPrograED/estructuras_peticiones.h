#ifndef ESTRUCTURAS_PETICIONES_H
#define ESTRUCTURAS_PETICIONES_H

#include <QDebug>
#include <QString>

struct Peticion{
    QString nombreMachine;
    int idMachine;
    int cant;

    Peticion(){
        nombreMachine = "";
        idMachine = -1;
        cant = 0;
    }
    Peticion(QString _nombreMachine, int _cant, int id){
        nombreMachine = _nombreMachine;
        cant = _cant;
        idMachine = id;
    }
    void imprimir(){
        qDebug()<<"ID: "<<idMachine<<"\nMachine: "<<nombreMachine<<"\n cantidad: "<<cant;
    }

    QString toString(){
        return "\n\nID: "+QString::number(idMachine)+"\nMachine: "+nombreMachine+"\nCantidad: "+QString::number(cant);
    }

};

struct NodoPeticion{
    Peticion * peticion;
    NodoPeticion * siguiente;

    NodoPeticion(){
        siguiente = NULL;
        peticion = NULL;
    }
    NodoPeticion(Peticion * _peticion){
        siguiente = NULL;
        peticion = _peticion;
    }
    void imprimir(){
        peticion->imprimir();
    }
    QString toString(){
        return peticion->toString();
    }
};

struct ColaPeticiones{
    NodoPeticion *frente; // ERROR sin ultimo nodo

    ColaPeticiones(){
         frente = NULL;
    }

    // encabezados de funcion
    void encolar(QString _nombreMachine, int _cant, int id);
    NodoPeticion * desencolar (void);
    NodoPeticion * verFrente(void);
    bool vacia(void);
    void imprimir(void);
    QString toString();
};

#endif // ESTRUCTURAS_PETICIONES_H
