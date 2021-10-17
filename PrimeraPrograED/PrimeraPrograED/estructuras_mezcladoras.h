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



#endif // ESTRUCTURAS_MEZCLADORAS_H
