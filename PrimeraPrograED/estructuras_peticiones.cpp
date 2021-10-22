#include "estructuras_peticiones.h"
bool ColaPeticiones::vacia (void){
     if (frente == NULL)
        return true;
     else
         return false;
}

void ColaPeticiones::encolar(QString _nombreMachine, int _cant, int id){
    if (vacia())
         frente = new NodoPeticion(new Peticion(_nombreMachine, _cant, id));
      else{
            // referencia al primero para recorrer la lista
            NodoPeticion* actual = frente;
            // recorre la lista hasta llegar al penultimo nodo
            while (actual->siguiente != NULL)
                          actual = actual->siguiente;

            // Crea nuevo nodo, lo apunta con uN
            NodoPeticion* nuevo = new NodoPeticion(new Peticion(_nombreMachine, _cant, id));
            //le quita el enlace al que era ultimo
            actual->siguiente = nuevo;
        }
}

NodoPeticion* ColaPeticiones::desencolar(void){
      // si no hay elementos, no borra nada, retorna null
      if (vacia()){
         return NULL;
      }else{
          NodoPeticion* borrado = frente;
          frente = frente->siguiente;
          borrado->siguiente = NULL;
          return borrado;
      }
}

NodoPeticion* ColaPeticiones::verFrente(){
      return frente;
}

NodoPeticion* ColaPeticiones::verUltimo(){

    NodoPeticion * temp = frente;
    if(vacia())return frente;
    while(temp->siguiente!=NULL)
        temp = temp->siguiente;
    //temp->peticion->toString();
    return temp;
}


void ColaPeticiones::imprimir(){

    lbTitulo->setText(toString());

}

QString ColaPeticiones::toString(){
    NodoPeticion * temp = frente;
    QString respuesta = "------COLA DE PETICIONES------";

    while(temp!=NULL){
        respuesta += temp->toString();
        temp = temp->siguiente;
    }
    respuesta+="\n-----------------------------------";
    return respuesta;

}

int ColaPeticiones::getPeticionMachine(int id){
    NodoPeticion * temp = frente;
    int respuesta = 0;

    while(temp!=NULL){
        if(temp->peticion->idMachine == id){
            respuesta += temp->peticion->cant;
        }
        temp = temp->siguiente;
    }
    return respuesta;

}

