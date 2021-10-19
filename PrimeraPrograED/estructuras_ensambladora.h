#ifndef ESTRUCTURAS_ENSAMBLADORA_H
#define ESTRUCTURAS_ENSAMBLADORA_H

#include <QDebug>
#include <QString>
struct Banda{
    int cantNow;
    int capacidad;
    QString nombre;
    Banda(){
        cantNow = 0;
        capacidad = 0;
    }
};

struct ArrayBandas{
    Banda * array[2];

    ArrayBandas(){
        array[0] = new Banda();
        array[0]->nombre = "Banda 1";
        array[1] = new Banda();
        array[1]->nombre = "Banda 2";
    }
};


struct Ensambladora{
    ArrayBandas * bandas;
    int duracionSegundos;
    int cant;
    int timeActual;
    bool flagProcesando;
    Ensambladora(){
        bandas = new ArrayBandas();
        duracionSegundos = 0;
        cant = 0;
        timeActual = 0;
        flagProcesando = false;
    }

    void sumarSegundo();
    int makeCookies(int mezcla, int choco);
};

#endif // ESTRUCTURAS_ENSAMBLADORA_H
