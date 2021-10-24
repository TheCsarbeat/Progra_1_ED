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
    mezclaTotal = 0;
    chocoTotal = 0;
    idMachine = -1;
}

Carrito::Carrito(int _capacidad, double _duracionTotal, bool _estado, QLabel *lb,QLabel * Datos){
    capacidad = _capacidad;
    duracionTotal = _duracionTotal;
    estado = _estado;    
    timeActual = 0;
    libre = false;
    lbTitulo = lb;
    lbDatos = Datos;
    mezclaTotal = 0;
    chocoTotal = 0;
    idMachine=-1;

}

void Carrito::sumarSegundo(){
    if(timeActual==0){
        double num = duracionTotal- (int)duracionTotal;

        timeActual = num;
        sleepTime = num*1000;
        if(num==0){
            timeActual ++;
            sleepTime =1000;
        }
    }else{
        timeActual ++;
        sleepTime =1000;
    }

}

void Carrito::imprimir(){
    lbDatos->setText("Carga: "+QString::number(cargaNow)
                     +"\nChocolate entregado: "+QString::number(chocoTotal)
                     +"\nMezcla entregada: "+QString::number(mezclaTotal));
    lbDatos->update();
}

Almacen::Almacen(){
    carrito = new Carrito(new QLabel, new QLabel);
}


Almacen::Almacen(Carrito * _car){
    carrito = _car;
}
