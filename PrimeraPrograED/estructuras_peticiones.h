#ifndef ESTRUCTURAS_PETICIONES_H
#define ESTRUCTURAS_PETICIONES_H

#include <QDebug>
#include <QString>
#include <QLabel>

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
        return "\n\nMachine: "+nombreMachine+"\nCantidad: "+QString::number(cant);
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
    QLabel * lbTitulo;
    ColaPeticiones(){
         frente = NULL;
    }
    ColaPeticiones(QLabel * titulo){
         frente = NULL;
         lbTitulo = titulo;
    }

    // encabezados de funcion
    void encolar(QString _nombreMachine, int _cant, int id);
    NodoPeticion * desencolar (void);
    NodoPeticion * verFrente(void);
    NodoPeticion * verUltimo(void);
    bool vacia(void);
    void imprimir(void);
    QString toString();

    int getPeticionMachine(int id);
};

#endif // ESTRUCTURAS_PETICIONES_H
