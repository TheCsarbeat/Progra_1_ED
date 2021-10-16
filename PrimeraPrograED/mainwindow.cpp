#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnIniciar_clicked(){


    RegistroAlmacen * registro = new RegistroAlmacen();
    Carrito *carro= new Carrito();

     //Varaibels de interfaz gr[afica
    carro->capacidad = 10;
    carro->duracionTotal = 5;


    Almacen * almacenNuevo = new Almacen(carro, registro);
    almacenNuevo->registro = new RegistroAlmacen();

    ArrayMachines *arraymachines = new ArrayMachines();
    Main_Struct * mainStruct = new Main_Struct(almacenNuevo, arraymachines);


    Ensambladora * nuevaEnsabladora = new Ensambladora();

    mainStruct->ensambladora  = nuevaEnsabladora;
    int varibleCEsar = 20;

    mainStruct->arrayMachine->array[0]->min = varibleCEsar;
    mainStruct->arrayMachine->array[0]->max = 30;
    mainStruct->arrayMachine->array[0]->duracionSegudos = 20;
    mainStruct->arrayMachine->array[0]->gramosProcesar = 20;

    mainStruct->arrayMachine->array[1]->min = 15;
    mainStruct->arrayMachine->array[1]->max = 40;
    mainStruct->arrayMachine->array[1]->cantNow = 25;
    mainStruct->arrayMachine->array[1]->duracionSegudos =10;
    mainStruct->arrayMachine->array[1]->gramosProcesar = 5;

    mainStruct->arrayMachine->array[2]->min = 25;
    mainStruct->arrayMachine->array[2]->max = 50;
    mainStruct->arrayMachine->array[2]->duracionSegudos = 5;
    mainStruct->arrayMachine->array[2]->gramosProcesar = 10;

    QLabel * arrayLbMachines[6];
    arrayLbMachines[0] = this->ui->lbMachine1;
    arrayLbMachines[1] = this->ui->lbMachine2;
    arrayLbMachines[2] = this->ui->lbMachine3;

    arrayLbMachines[3] = this->ui->lbDatosMachine1;
    arrayLbMachines[4] = this->ui->lbDatosMachine2;
    arrayLbMachines[5] = this->ui->lbDatosMachine3;

    mainThread = new thread_main();
    mainThread->__init__(mainStruct, this->ui->panelMain,this->ui->lbCarro, arrayLbMachines, this->ui->lbCola);
    mainThread->start();

}

