#include "estructuras_mezcladoras.h"
Machine::Machine(QLabel * titulo , QLabel * datos){
    id = 0;
    nombre = "";
    max = 0;
    min = 0;
    cantNow = 0;
    gramosProcesar = 0;
    duracionSegudos = 0;
    tiempoActual = 0;
    state = true;
    flagEncolado = false;
    flagProcesando = false;
    lbTitulo = titulo;
    lbDatos = datos;
    totalMezclado = 0;
    aviableEncolar = true;


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
    if(tiempoActual==0){
        double num = duracionSegudos- (int)duracionSegudos;

        tiempoActual = num;
        sleepTime = num*1000;
        if(num==0){
            tiempoActual ++;
            sleepTime =1000;
        }
    }else{
        tiempoActual ++;
        sleepTime =1000;
    }
}

void Machine::imprimirDatos(){
    lbDatos->setText("Cant actual: "+QString::number(cantNow)
                     +"\n Min: "+QString::number(min)
                     +"\n Max: "+QString::number(max)
                     +"\n Total mezclado: "+QString::number(totalMezclado));
}

ArrayMachines::ArrayMachines(){
    array[0] = new Machine(new QLabel, new QLabel);
    array[0]->id = 0;
    array[0]->nombre = "Mezcladora 1";

    array[1] = new Machine(new QLabel, new QLabel);
    array[1]->id = 1;
    array[1]->nombre = "Mezcladora 2";

    array[2] = new Machine(new QLabel, new QLabel);
    array[2]->id = 2;
    array[2]->nombre = "Chocolatera";
}

ArrayMachines::ArrayMachines(QLabel * lbTitulos[3], QLabel * lbDatos[3]){
    array[0] = new Machine(lbTitulos[0], lbDatos[0]);
    array[0]->id = 0;
    array[0]->nombre = "Mezcladora 1";

    array[1] = new Machine(lbTitulos[1], lbDatos[1]);
    array[1]->id = 1;
    array[1]->nombre = "Mezcladora 2";

    array[2] = new Machine(lbTitulos[2], lbDatos[2]);
    array[2]->id = 2;
    array[2]->nombre = "Chocolatera";
}



