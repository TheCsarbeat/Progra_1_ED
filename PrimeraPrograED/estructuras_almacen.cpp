#include "estructuras_almacen.h"

MateriaPrima::MateriaPrima(){
    nombre = "";
    cant = 0;
}
MateriaPrima::MateriaPrima(QString _name, int _cant){
    nombre = _name;
    cant = _cant;
}

Carrito::Carrito(){
    capacidad = 0;
    duracionTotal = 0;
    estado = false;
    timeActual = 0;
    libre = false;
}

Carrito::Carrito(int _capacidad, int _duracionTotal, bool _estado){
    capacidad = _capacidad;
    duracionTotal = _duracionTotal;
    estado = _estado;

    timeActual = 0;
    libre = false;

}

void Carrito::sumarSegundo(){
    timeActual++;
}

Almacen::Almacen(){
    carrito = new Carrito();
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
