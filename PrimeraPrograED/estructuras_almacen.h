#ifndef ESTRUCTURAS_ALMACEN_H
#define ESTRUCTURAS_ALMACEN_H
#include <QDebug>
#include <QString>
#include <QLabel>

struct MateriaPrima{
    QString nombre;
    int cant;
    MateriaPrima();
    MateriaPrima(QString _name, int _cant);
};

struct Carrito{
    QLabel * lbTitulo;
    QLabel * lbDatos;
    int capacidad;
    int duracionTotal;
    int cargaNow;
    bool estado;

    bool libre;
    int timeActual;


    Carrito(QLabel * Titulo,QLabel * Datos);
    Carrito(int _capacidad, int _duracionTotal, bool _estado,QLabel * Titulo,QLabel * Datos);

    void sumarSegundo();
    void imprimir();


};

struct RegistroAlmacen{
    int cantMezclaCargada;
    int cantChocolateCargado;

    RegistroAlmacen();

    void sumarCantMezcla(int);
    void sumarCantChocolate(int);
};

struct Almacen{

    Carrito * carrito;
    RegistroAlmacen * registro;

    Almacen();
    Almacen(Carrito * _car, RegistroAlmacen *_registro);
    void agregarMezclaCarrito();
    void agregarChocolateCarrito();

};
#endif // ESTRUCTURAS_ALMACEN_H
