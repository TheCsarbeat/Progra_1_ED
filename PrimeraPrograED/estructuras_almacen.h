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

    int chocoTotal;
    int mezclaTotal;

    bool libre;
    int timeActual;


    Carrito(QLabel * Titulo,QLabel * Datos);
    Carrito(int _capacidad, int _duracionTotal, bool _estado,QLabel * Titulo,QLabel * Datos);

    void sumarSegundo();
    void imprimir();


};

struct Almacen{

    Carrito * carrito;

    Almacen();
    Almacen(Carrito * _car);
    void agregarMezclaCarrito();
    void agregarChocolateCarrito();

};
#endif // ESTRUCTURAS_ALMACEN_H
