#ifndef ESTRUCTURAS_MEZCLADORAS_H
#define ESTRUCTURAS_MEZCLADORAS_H
#include <QDebug>
#include <QString>

//Estructuras de las maquinas mezcladoras
struct Machine{
    QString nombre;
    int id;
    int max;
    int min;
    int cantNow;
    int gramosProcesar;
    int tiempoActual;
    int duracionSegudos;

    bool state;
    bool flagEncolado;
    bool flagProcesando;

    Machine();

    void setMax(int _max);
    void setMin(int _min);
    void setCantNow(int _cantNow);
    void setState(bool _state);
    void procesar();

};

struct ArrayMachines{
    Machine* array[3];
    ArrayMachines();

};

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

#endif // ESTRUCTURAS_MEZCLADORAS_H
