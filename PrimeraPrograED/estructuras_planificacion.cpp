#include "estructuras_planificacion.h"

void ListaCircular::insertar(QString name, int cant){
    if (primerNodo == NULL){
        primerNodo = new NodoTipoGalleta(new TipoGalleta(name, cant));
        primerNodo->siguiente= primerNodo;
        primerNodo->anterior = primerNodo;
    }else{
        NodoTipoGalleta * nuevo = new NodoTipoGalleta(new TipoGalleta(name, cant));
        nuevo->siguiente = primerNodo;
        nuevo->anterior = primerNodo->anterior;
        primerNodo->anterior->siguiente = nuevo;
        primerNodo->anterior = nuevo;
    }
}


void ListaCircular::imprimir(){
    if (primerNodo != NULL){
        NodoTipoGalleta * tmp = primerNodo;
        do{
            tmp->tipo->imprimir();
            tmp = tmp->siguiente;
        }while(tmp!=primerNodo);
        qDebug() << "\n";
    }
}

NodoTipoGalleta * ListaCircular::buscar(QString name, int cant){
    if (primerNodo != NULL){
        NodoTipoGalleta * tmp = primerNodo;
        do{
            if (tmp->tipo->nombre == name && tmp->tipo->cantGalletas == cant )
                return tmp;
            tmp = tmp->siguiente;
        }while(tmp!=primerNodo);

    }
    return NULL;
}

NodoTipoGalleta * ListaCircular::eliminar(QString name, int cant){
    NodoTipoGalleta * eliminado = buscar(name, cant);

        if (eliminado != NULL){ // s� lo encontr�
            if (primerNodo->siguiente == primerNodo) // solo un elemento
                primerNodo = eliminado->siguiente = eliminado->anterior = NULL;
            else{
                if (eliminado == primerNodo)
                    primerNodo = primerNodo->siguiente;

                NodoTipoGalleta * tmp = eliminado->anterior;
                tmp->siguiente = tmp->siguiente->siguiente;
                tmp->siguiente->anterior = tmp;
                eliminado->siguiente = eliminado->anterior = NULL;
            }
        }
        return eliminado;
}


//Planificaciones
void Planificacion::imprimir(){
         tipoGalleta->imprimir();
         qDebug()<< " Cantidad de tipos: "<<cantTipos<<"\n";
    }

bool ListaSimplePlanificaciones::isEmpty(){
    return primerNodo == NULL;
}


void ListaSimplePlanificaciones::insertarAlInicio(Planificacion * _planificacion){
    if (isEmpty()){
        primerNodo = new NodoPlanificacion(_planificacion);
    }
    else{
        NodoPlanificacion * nuevo = new NodoPlanificacion(_planificacion);
        nuevo->siguiente = primerNodo;
        primerNodo = nuevo;
    }
    largo++; //incremento porque se agreg� un elemento m�s
}

void ListaSimplePlanificaciones::imprimir(){
    NodoPlanificacion * tmp = primerNodo;
    while (tmp != NULL){
        tmp->planificacion->imprimir();
        tmp = tmp->siguiente; // avanza, evita que se encicle
    }
    qDebug() << "\n";
}




int ListaSimplePlanificaciones::getLargo(){
    return largo;
}


NodoPlanificacion* ListaSimplePlanificaciones::borrarAlInicio(){
    if (!isEmpty()){
        NodoPlanificacion * borrado = primerNodo;
        primerNodo = primerNodo->siguiente;
        borrado->siguiente = NULL;
        largo--;
        return borrado;
    }
    return NULL;
}

