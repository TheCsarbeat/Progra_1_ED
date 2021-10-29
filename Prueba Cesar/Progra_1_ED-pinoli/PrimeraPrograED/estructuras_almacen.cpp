#include "estructuras_almacen.h"

MateriaPrima::MateriaPrima(){
    nombre = "";
    cant = 0;

}
MateriaPrima::MateriaPrima(QString _name, int _cant){
    nombre = _name;
    cant = _cant;

}

Carrito::Carrito(QLabel *lb, QLabel * Datos){
    capacidad = 0;
    duracionTotal = 0;
    cargaNow = 0;
    estado = true;
    timeActual = 0;
    libre = true;
    lbTitulo = lb;
    lbDatos = Datos;
    materiaPrimaEntregada = 0;
}

Carrito::Carrito(int _capacidad, int _duracionTotal, bool _estado, QLabel *lb,QLabel * Datos){
    capacidad = _capacidad;
    duracionTotal = _duracionTotal;
    estado = _estado;    
    timeActual = 0;
    libre = false;
    lbTitulo = lb;
    lbDatos = Datos;
    materiaPrimaEntregada = 0;

}

void Carrito::sumarSegundo(){
    timeActual++;
}

void Carrito::imprimir(){

    lbDatos->update();
    lbDatos->setText("Carga: "+QString::number(cargaNow)
                     +"\nTotal entregada: "+QString::number(materiaPrimaEntregada));
    lbDatos->update();
}

Almacen::Almacen(){
    carrito = new Carrito(new QLabel, new QLabel);
}


Almacen::Almacen(Carrito * _car){
    carrito = _car;
}