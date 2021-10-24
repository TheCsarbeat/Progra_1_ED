#import "estructuras_transportadores.h"

void ListaTransportadores::insertar(Transportador * transportador){
            if (primerNodo == NULL)
            {
                ultimoNodo = primerNodo = new NodoTransportador(transportador);
            }
            else
            {
                NodoTransportador *nuevo = new NodoTransportador(transportador);
                nuevo->siguiente = primerNodo;
                primerNodo = nuevo;
            }
            largo++;
}

NodoTransportador * ListaTransportadores::buscar(QString name){
    if(primerNodo != NULL){
        NodoTransportador * tmp = primerNodo;
        do{
            if(tmp->transportador->tipoPaquete->nombre == name){
                return tmp;
            }
            tmp = tmp->siguiente;
        }while(tmp!=NULL);
    }

    return NULL;
}
