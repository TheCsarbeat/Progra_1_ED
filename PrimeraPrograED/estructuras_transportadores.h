#ifndef ESTRUCTURAS_TRANSPORTADORES_H
#define ESTRUCTURAS_TRANSPORTADORES_H

#include <QDebug>
#include <QString>
#include <QLabel>

#include "estructuras_planificacion.h"

struct Transportadores;
struct NodoTransportador;
struct Transportador;

struct Transportador{


    //datos de el
    int capacidad;
    int cargaNow;
    double speed;
    bool flagProcesando;


    //procesar
    int timeNow;
    int sleepTime;


    //Datos de paquete
    QString nombre;
    int id;



    Transportador(){
        capacidad = 0;
        flagProcesando = false;
        cargaNow = 0;
        speed = 0;
        timeNow = 0;
        nombre = "";
        id = 0;
    }
    QString toString(){
        return "Carrito de: "+nombre+"\nCantidad Actual: "+QString::number(cargaNow)+"\nMax: "+QString::number(capacidad);
    }
    QString toStringMoving(){
        return "Tiempo Actual: "+QString::number(timeNow)+ "\nCarrito de: "+nombre+"\nCantidad Actual: "+QString::number(cargaNow)+"\nMax: "+QString::number(capacidad);
    }
    void sumarSegundo(){
        if(timeNow==0){
            double num = speed- (int)speed;
            timeNow = num;
            sleepTime = num*1000;
            if(num==0){
                timeNow ++;
                sleepTime =1000;
            }
        }else{
            timeNow ++;
            sleepTime =1000;
        }
    }
};


struct ArrayTransportadores{

    Transportador *p[200];
    bool state;
    int len;

    //Visual
    QLabel * lbDatos;
    QLabel * lbtitulo;

    ArrayTransportadores(){
        for(int i= 0; i <200; i++){
            p[i] = new Transportador();
        }
    }
    ArrayTransportadores(ListaSimplePlanificaciones * lista, QLabel * titulo, QLabel *datos){
        lbDatos = datos;
        lbtitulo = titulo;
        state = true;
        QStringList listaPlanificaciones = lista->toStringParaEmpacadora();
        len = listaPlanificaciones.length();

        for(int i = 0; i< len; i++){
            QString dato = listaPlanificaciones.at(i);
            p[i] = new Transportador();
            p[i]->nombre = listaPlanificaciones.at(i).split(" | ").at(4);
            p[i]->id = listaPlanificaciones.at(i).split(" | ").at(6).toInt();
            p[i]->capacidad =dato.split(" | ").at(7).toInt();
            p[i]->speed =dato.split(" | ").at(8).toDouble();

        }

        for(int i = 0; i< len; i++){
           qDebug()<<"-------------------------ff";
           qDebug()<<"Nombre: "<<p[i]->nombre;
           qDebug()<<"id: "<<p[i]->id;
           qDebug()<<"capacidad: "<<p[i]->capacidad;
           qDebug()<<"speed: "<<p[i]->speed;
        }


    }



    void imprimir(){
        QString res = "";
        for(int i = 0; i< len; i++){
           res += p[i]->toStringMoving();
           res += "\n--------------\n\n";

        }
        lbDatos->setText(res);
        //lbDatos->update();
    }
};

#endif // ESTRUCTURAS_TRANSPORTADORES_H
