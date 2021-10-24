#ifndef ESTRUCTURAS_MEZCLADORAS_H
#define ESTRUCTURAS_MEZCLADORAS_H
#include <QDebug>
#include <QString>
#include <QLabel>
//Estructuras de las maquinas mezcladoras
struct Machine{
    QString nombre;

    int id;
    int max;
    int min;
    int cantNow;
    int gramosProcesar;
    int tiempoActual;
    double duracionSegudos;
    int totalMezclado;
    QLabel * lbTitulo;
    QLabel * lbDatos;

    int sleepTime;

    bool aviableEncolar;

    bool state;
    bool flagEncolado;
    bool flagProcesando;

    Machine(QLabel * titulo , QLabel * datos);

    void setMax(int _max);
    void setMin(int _min);
    void setCantNow(int _cantNow);
    void setState(bool _state);
    void procesar();

    void imprimirDatos();

};

struct ArrayMachines{
    Machine * array[3];
    QLabel * lbTitulos[3];
    QLabel * lbDatos[3];
    ArrayMachines();
    ArrayMachines(QLabel * lbTitulo[3],QLabel * lbDatos[3] );

};



#endif // ESTRUCTURAS_MEZCLADORAS_H
