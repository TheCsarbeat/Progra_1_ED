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

void ListaCircular::insertar(TipoGalleta *tipo){

    if(!exist(tipo)){
        if (primerNodo == NULL){
            primerNodo = new NodoTipoGalleta(tipo);
            primerNodo->siguiente= primerNodo;
            primerNodo->anterior = primerNodo;
        }else{
            NodoTipoGalleta * nuevo = new NodoTipoGalleta(tipo);
            nuevo->siguiente = primerNodo;
            nuevo->anterior = primerNodo->anterior;
            primerNodo->anterior->siguiente = nuevo;
            primerNodo->anterior = nuevo;
        }
    }
}

bool ListaCircular::exist(TipoGalleta *tipo){
    QString name = tipo->nombre;
    int cant = tipo->cantGalletas;
    qDebug()<<"Nombre: "+name;
    qDebug()<<"Cantidad: "+QString::number(cant);

    if (primerNodo != NULL){
        NodoTipoGalleta * tmp = primerNodo;
        do{
            qDebug()<<"\n\n\n";
            qDebug()<<"Nombre: "+tmp->tipo->nombre;
            qDebug()<<"Cantidad: "+QString::number(tmp->tipo->cantGalletas);
            if (tmp->tipo->nombre == name && tmp->tipo->cantGalletas == cant ){
                return true;
            }
            tmp = tmp->siguiente;
        }while(tmp!=primerNodo);

    }

    return false;
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

QStringList  ListaCircular::toString(){
    QStringList list;
    if (primerNodo != NULL){
        NodoTipoGalleta * tmp = primerNodo;
        do{
            QString tipo = "";
            tipo=tmp->tipo->nombre+ ", "+QString::number(tmp->tipo->cantGalletas);
            list.append(tipo);
            tmp = tmp->siguiente;
        }while(tmp!=primerNodo);
    }
    return list;
}

NodoTipoGalleta * ListaCircular::buscar(QString name, int cant){
    if (primerNodo != NULL){
        NodoTipoGalleta * tmp = primerNodo;
        do{
            if (tmp->tipo->nombre == name && tmp->tipo->cantGalletas == cant ){
                return tmp;
            }
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
void ListaSimplePlanificaciones::borrar(QString tipoGalleta, int cant){
    if(!isEmpty()){
            NodoPlanificacion * temp = primerNodo;
            if (temp->planificacion->tipoGalleta->toString() == tipoGalleta && cant == temp->planificacion->cantTipos ){
               borrarAlInicio();
            }
            NodoPlanificacion * temp2 = temp;
            temp = temp->siguiente;
            while(temp != NULL){
                if (temp->planificacion->tipoGalleta->toString() == tipoGalleta && cant == temp->planificacion->cantTipos){

                    temp2->siguiente = temp->siguiente;
                    temp->siguiente = NULL;
                    largo--;
                    break;
                }
                temp2 = temp;
                temp = temp->siguiente;
            }
    }
}

QStringList ListaSimplePlanificaciones::toString(){
    QStringList list;
    if (primerNodo != NULL){
        NodoPlanificacion * temp = primerNodo;
        do{
            list.append(temp->planificacion->toString());
            temp = temp->siguiente;
        }while(temp!=NULL);
    }

    return list;
}

NodoPlanificacion* ListaSimplePlanificaciones::buscar(int index){
    if(!isEmpty()){
        NodoPlanificacion * temp = primerNodo;
        int i = 0;
        while(temp != ultimoNodo){
            if (index == i)
                return temp;
            ++i;
            temp = temp->siguiente;
        }
    }
    return NULL;
}
