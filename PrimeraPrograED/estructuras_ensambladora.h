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
        nombre = "";
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

    ArrayBandas(){
        array[0] = new Banda("banda",new QLabel);
        array[0] = new Banda("banda",new QLabel);
    }
    ArrayBandas(QLabel * banda1, QLabel * banda2, QString banda1Name, QString banda2Name){
        array[0] = new Banda(banda1Name,banda1);
        array[1] = new Banda(banda2Name,banda2);
    }
};


struct Ensambladora{
    ArrayBandas * bandas;
    int duracionSegundos;
    int cant;
    int timeActual;
    int galletasHechas;
    bool flagProcesando;
    bool state;
    QLabel * lbTitulo;
    QLabel * lbDatos;
    Ensambladora(){
        bandas = new ArrayBandas(new QLabel, new QLabel, "Banda 1", "Banda 2");
        duracionSegundos = 0;
        cant = 0;
        timeActual = 0;
        flagProcesando = false;
        galletasHechas = 0;
        state = true;

    }
    Ensambladora(QLabel * titulo, QLabel * datos, QLabel * banda1, QLabel * banda2){
        bandas = new ArrayBandas(banda1, banda2, "Banda 1", "Banda 2");
        duracionSegundos = 0;
        cant = 0;
        timeActual = 0;
        flagProcesando = false;
        galletasHechas = 0;
        lbTitulo = titulo;
        lbDatos = datos;
        state = true;
    }

    void sumarSegundo();
    int makeCookies(int mezcla, int choco);
    void imprimir();
};

#endif // ESTRUCTURAS_ENSAMBLADORA_H
