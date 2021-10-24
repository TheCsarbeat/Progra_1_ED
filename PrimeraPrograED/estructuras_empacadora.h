#ifndef ESTRUCTURAS_EMPACADORA_H
#define ESTRUCTURAS_EMPACADORA_H

#include "estructuras_ensambladora.h"
#include "estructuras_planificacion.h"
struct PeticionEmpacadora{
    double  tiempoDuracion;
    int  cantEmpacado ;
    int cantPaquetesPorEmpacar;
    int totalPaquetesEmpacados;
    int cantGalletasPorPaquete;
    QString nombre;
    int id = 0;
    int probabilidad;
    int sumaProbabilidades = 0;


    PeticionEmpacadora(){
        tiempoDuracion =0;
        cantEmpacado =0 ;
        cantPaquetesPorEmpacar = 0;
        nombre ="" ;
        id = 0;
        probabilidad = 0;
        sumaProbabilidades = 0;
        totalPaquetesEmpacados=0;
    }

    PeticionEmpacadora(double t, int cantE, int cantP, QString name){
        tiempoDuracion = t;
        cantEmpacado = cantE;
        cantPaquetesPorEmpacar = cantP;
        nombre = name;
        id = 0;
        probabilidad = 0;
        sumaProbabilidades = 0;
        totalPaquetesEmpacados=0;
    }

};

struct ArrayPeticionEmpacadaora{
    PeticionEmpacadora *p;

    ArrayPeticionEmpacadaora(){
        p=NULL;
    }

    void crear(int len,PeticionEmpacadora* miArray[]){
        /*for(int i = 0; i< len; i++){
           qDebug()<<"-------------------------desde crear";
           qDebug()<<"Nombre: "<<miArray[i]->nombre;
           qDebug()<<"tiempoDuracion: "<<miArray[i]->tiempoDuracion;
           qDebug()<<"cantEmpacado: "<<miArray[i]->cantEmpacado;
           qDebug()<<"cantPaquetes: "<<miArray[i]->cantPaquetes;
           qDebug()<<"probabilidad: "<<miArray[i]->probabilidad;
        }*/
        PeticionEmpacadora *temporal = new PeticionEmpacadora();

        for (int i = 0;i < len; i++){
            for (int j = 0; j< len-1; j++){
                if (miArray[j]->probabilidad > miArray[j+1]->probabilidad){ // Ordena el array de mayor a menor, cambiar el "<" a ">" para ordenar de menor a mayor
                    *temporal = *miArray[j];
                    *miArray[j] = *miArray[j+1];
                    *miArray[j+1] = *temporal;
                }
            }
        }
    }
};

struct Empacadora{
    Banda * banda;
    QLabel * lbDatos;
    QLabel * lbtitulo;
    QLabel * lbDatosBanda;
    QLabel * lbPedidosEmpacado;

    double duracionTotal;
    double timeNow;
    bool state;
    bool flagProcesando;
    int sleepTime;

    int len;
    int cantTiposEmpacandoActual;
    int cantGalletasAEmpacar;
    ListaSimplePlanificaciones * lista;
    ArrayPeticionEmpacadaora * arrayP;
    PeticionEmpacadora *p[200];

    Empacadora(){
        banda = new Banda();
        lista = new ListaSimplePlanificaciones();
        state = true;
        timeNow = 0.0;
    }
    Empacadora( ListaSimplePlanificaciones * _lista, QLabel * titulo, QLabel *datos, QLabel * lbDatosB, QLabel * pedidos){
        lista = _lista;
        banda = new Banda("Banda Supervisadas",lbDatosB);
        lbtitulo = titulo;
        lbDatos = datos;
        lbPedidosEmpacado = pedidos;
        lista = _lista;
        state = true;
        timeNow = 0.0;
        cantTiposEmpacandoActual =0;

        QStringList listaPlanificaciones = lista->toStringParaEmpacadora();
        len = listaPlanificaciones.length();

        for(int i = 0; i< len; i++){
            p[i] = new PeticionEmpacadora();
            p[i]->probabilidad = listaPlanificaciones.at(i).split(" | ").at(2).toInt();
            p[i]->tiempoDuracion = listaPlanificaciones.at(i).split(" | ").at(0).toDouble();
            p[i]->cantEmpacado = listaPlanificaciones.at(i).split(" | ").at(1).toInt(); // Estos son los paquetes que empaca
            p[i]->cantPaquetesPorEmpacar = listaPlanificaciones.at(i).split(" | ").at(3).toInt(); // Estos son los paquetes por empacar
            p[i]->nombre = listaPlanificaciones.at(i).split(" | ").at(4);
            p[i]->cantGalletasPorPaquete =listaPlanificaciones.at(i).split(" | ").at(5).toInt();

        }

        arrayP->crear(len, p);

        /*for(int i = 0; i< len; i++){
           qDebug()<<"-------------------------ff";
           qDebug()<<"Nombre: "<<p[i]->nombre;
           qDebug()<<"tiempoDuracion: "<<p[i]->tiempoDuracion;
           qDebug()<<"cantEmpacado: "<<p[i]->cantEmpacado;
           qDebug()<<"cantPaquetes: "<<p[i]->cantPaquetes;
           qDebug()<<"probabilidad: "<<p[i]->probabilidad;
        }*/


    }

    void sumarSegundo(double tiempoDuracion){
        if(timeNow==0){
            double num = tiempoDuracion- (int)tiempoDuracion;

            timeNow = num;
            sleepTime = num*1000;
            if(num==0){
                timeNow ++;
                sleepTime =1000;
            }
        }else{
            timeNow ++;
            sleepTime =1000;
        }

    }

    void imprimir(){
        QString resultado = "";
        for(int i = 0; i< len; i++){
           resultado +="\nNombre: "+p[i]->nombre;
           resultado +="\nTotal Empacados: "+ QString::number(p[i]->totalPaquetesEmpacados);
           resultado +="\nPor Empacar: "+ QString::number(p[i]->cantPaquetesPorEmpacar);
           resultado +="\nCant Por Tipo paquete EMP: "+ QString::number(p[i]->cantEmpacado);
           resultado +="\nGalletas Por Paquete: "+ QString::number(p[i]->cantGalletasPorPaquete);
           resultado +="\nProbabilidad de empaque: "+ QString::number(p[i]->probabilidad)+" %";

           resultado +="\n---------------";
        }
        lbPedidosEmpacado->setText(resultado);
    }

};

#endif // ESTRUCTURAS_EMPACADORA_H
