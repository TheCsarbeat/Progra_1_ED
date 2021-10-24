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
    double duracionTotal;
    int cargaNow;
    bool estado;
    int chocoTotal;
    int mezclaTotal;
    bool libre;
    double timeActual;
    int idMachine;
    int sleepTime;


    Carrito(QLabel * Titulo,QLabel * Datos);
    Carrito(int _capacidad, double _duracionTotal, bool _estado,QLabel * Titulo,QLabel * Datos);

    void sumarSegundo();
    void imprimir();


};

struct Almacen{

    Carrito * carrito;
    int totalMezcla = 0;
    int totalChocolate = 0;

    Almacen();
    Almacen(Carrito * _car);
    void agregarMezclaCarrito();
    void agregarChocolateCarrito();

};
#endif // ESTRUCTURAS_ALMACEN_H
