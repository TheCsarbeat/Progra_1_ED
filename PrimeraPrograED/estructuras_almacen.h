#ifndef ESTRUCTURAS_ALMACEN_H
#define ESTRUCTURAS_ALMACEN_H
#include <QDebug>
#include <QString>

struct MateriaPrima{
    QString nombre;
    int cant;
    MateriaPrima();
    MateriaPrima(QString _name, int _cant);
};

struct Carrito{
    int capacidad;
    int duracionTotal;
    int cargaNow;
    bool estado;

    bool libre;
    int timeActual;


    Carrito();
    Carrito(int _capacidad, int _duracionTotal, bool _estado);

    void sumarSegundo();


};

struct RegistroAlmacen{
    int cantMezclaCargada;
    int cantChocolateCargado;

    RegistroAlmacen();

    void sumarCantMezcla();
    void sumarCantChocolate();
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
