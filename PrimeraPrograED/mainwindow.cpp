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
    carro->duracionTotal = 10;

    Almacen * almacenNuevo = new Almacen(carro, registro);

    ArrayMachines *arraymachines = new ArrayMachines();
    Main_Struct * mainStruct = new Main_Struct(almacenNuevo, arraymachines);

    ColaPeticiones * colaPeticiones = new ColaPeticiones();

    int varibleCEsar = 20;

    mainStruct->arrayMachine->array[0]->min = varibleCEsar;
    mainStruct->arrayMachine->array[1]->min = 15;
    mainStruct->arrayMachine->array[2]->min = 25;


    mainThread = new thread_main();
    mainThread->__init__(mainStruct, this->ui->panelMain,this->ui->lbCarro);
    mainThread->start();

}

