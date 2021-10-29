#ifndef ESTRUCTURAS_ENSAMBLADORA_H
#define ESTRUCTURAS_ENSAMBLADORA_H

#include <QDebug>
#include <QString>
#include <QLabel>

struct Banda{
    int cantNow;
    int capacidad;
    QString nombre;
    QLabel *lbDatos ;
    Banda(){
        cantNow = 0;
        capacidad = 0;
        lbDatos = new QLabel();
    }
    Banda(QString nombreBanda, QLabel * lbDatosBanda){
        cantNow = 0;
        capacidad = 0;
        nombre = nombreBanda;
        lbDatos = lbDatosBanda;
    }

    void imprimir();
};

struct ArrayBandas{
    Banda * array[2];

    ArrayBandas(QLabel * banda1, QLabel * banda2){
        array[0] = new Banda("Banda 1",banda1);
        array[1] = new Banda("Banda 2",banda2);
    }
};


struct Ensambladora{
    ArrayBandas * bandas;
    int duracionSegundos;
    int cant;
    int timeActual;
    int galletasHechas;
    bool flagProcesando;
    QLabel * lbTitulo;
    QLabel * lbDatos;
    Ensambladora(){
        bandas = new ArrayBandas(new QLabel, new QLabel);
        duracionSegundos = 0;
        cant = 0;
        timeActual = 0;
        flagProcesando = false;
        galletasHechas = 0;

    }
    Ensambladora(QLabel * titulo, QLabel * datos, QLabel * banda1, QLabel * banda2){
        bandas = new ArrayBandas(banda1, banda2);
        duracionSegundos = 0;
        cant = 0;
        timeActual = 0;
        flagProcesando = false;
        galletasHechas = 0;
        lbTitulo = titulo;
        lbDatos = datos;
    }

    void sumarSegundo();
    int makeCookies(int mezcla, int choco);
    void imprimir();
};

#endif // ESTRUCTURAS_ENSAMBLADORA_H
