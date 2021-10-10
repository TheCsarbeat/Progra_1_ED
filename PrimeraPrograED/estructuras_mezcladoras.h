#ifndef ESTRUCTURAS_MEZCLADORAS_H
#define ESTRUCTURAS_MEZCLADORAS_H
#include <QDebug>
#include <QString>

//Estructuras de las maquinas mezcladoras
struct Machine{
    QString nombre;
    int max;
    int min;
    int cantNow;
    char type;
    bool state;
    bool fillState;

    Machine();

    void setMax(int _max);
    void setMin(int _min);
    void setCantNow(int _cantNow);
    void setType(char _type);
    void setState(bool _state);

};

struct ArrayMachines{
    Machine* array[3];
    ArrayMachines();
};

struct Peticion{
    QString nombreMachine;
    int cant;

    Peticion(){
        nombreMachine = "";
        cant = 0;
    }
    Peticion(QString _nombreMachine, int _cant){
        nombreMachine = _nombreMachine;
        cant = _cant;
    }
    void imprimir(){
        qDebug()<<"Machine: "<<nombreMachine<<"\n cantidad: "<<cant;
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
};

struct ColaPeticiones{
    NodoPeticion *frente; // ERROR sin ultimo nodo

    ColaPeticiones(){
         frente = NULL;
    }

    // encabezados de funcion
    void encolar(QString _nombreMachine, int _cant);
    NodoPeticion * desencolar (void);
    NodoPeticion * verFrente(void);
    bool vacia(void);
    void imprimir(void);
};

#endif // ESTRUCTURAS_MEZCLADORAS_H
