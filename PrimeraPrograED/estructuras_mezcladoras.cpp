#include "estructuras_mezcladoras.h"
Machine::Machine(){
    id = 0;
    nombre = "";
    max = 0;
    min = 0;
    cantNow = 0;
    gramosProcesar = 0;
    duracionSegudos = 0;
    tiempoActual = 0;
    state = false;
    flagEncolado = false;
    flagProcesando = false;

}
void Machine::setMax(int _max){
    max = _max;
}
void Machine::setMin(int _min){
    min = _min;
}
void Machine::setCantNow(int _cantNow){
    cantNow = _cantNow;
}
void Machine::setState(bool _state){
    state = _state;
}

void Machine::procesar(){
    tiempoActual++;
}

ArrayMachines::ArrayMachines(){
    array[0] = new Machine();
    array[0]->id = 0;
    array[0]->nombre = "Mezcladora 1";

    array[1] = new Machine();
    array[1]->id = 1;
    array[1]->nombre = "Mezcladora 2";

    array[2] = new Machine();
    array[2]->id = 2;
    array[2]->nombre = "Chocolatera";
}

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

void ColaPeticiones::imprimir(){
    NodoPeticion * temp = frente;
    qDebug()<<"------COLA DE PETICIONES------";
    while(temp!=NULL){

        temp->imprimir();

        temp = temp->siguiente;
    }
    qDebug()<<"--------------------------------";

}

QString ColaPeticiones::toString(){
    NodoPeticion * temp = frente;
    QString respuesta = "------COLA DE PETICIONES------";
    while(temp!=NULL){
        respuesta += temp->toString();

        temp = temp->siguiente;
    }
    respuesta+="\n--------------------------------";
    return respuesta;

}

