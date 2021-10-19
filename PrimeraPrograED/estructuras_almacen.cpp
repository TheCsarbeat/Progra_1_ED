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
    estado = false;
    timeActual = 0;
    libre = true;
    lbTitulo = lb;
    lbDatos = Datos;
}

Carrito::Carrito(int _capacidad, int _duracionTotal, bool _estado, QLabel *lb,QLabel * Datos){
    capacidad = _capacidad;
    duracionTotal = _duracionTotal;
    estado = _estado;    
    timeActual = 0;
    libre = false;
    lbTitulo = lb;
    lbDatos = Datos;

}

void Carrito::sumarSegundo(){
    timeActual++;
}

void Carrito::imprimir(){
    lbDatos->setText("Carga: "+QString::number(cargaNow));
}

Almacen::Almacen(){
    carrito = new Carrito(new QLabel, new QLabel);
    registro = new RegistroAlmacen;
}


Almacen::Almacen(Carrito * _car, RegistroAlmacen *_registro){
    carrito = _car;
    registro = _registro;
}

RegistroAlmacen::RegistroAlmacen(){
    cantMezclaCargada = 0;
    cantChocolateCargado = 0;
}

void RegistroAlmacen::sumarCantMezcla(int cantidad){
    cantMezclaCargada+=cantidad;
}
void RegistroAlmacen::sumarCantChocolate(int cantidad){
    cantChocolateCargado+=cantidad;
}
