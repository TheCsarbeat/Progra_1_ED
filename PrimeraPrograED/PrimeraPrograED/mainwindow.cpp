#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->contentPanel->setCurrentIndex(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnIniciar_clicked(){


    MainStruct * mainStruct = cargarDatos();

    QLabel * arrayLbMachines[6];
    arrayLbMachines[0] = this->ui->lbMachine1;
    arrayLbMachines[1] = this->ui->lbMachine2;
    arrayLbMachines[2] = this->ui->lbMachine3;

    arrayLbMachines[3] = this->ui->lbDatosMachine1;
    arrayLbMachines[4] = this->ui->lbDatosMachine2;
    arrayLbMachines[5] = this->ui->lbDatosMachine3;

    mainThread = new thread_main();
    mainThread->__init__(mainStruct, this->ui->factoryPanel,this->ui->lbCarro, arrayLbMachines, this->ui->lbCola);
    mainThread->start();

}



void MainWindow::on_btnGotoDatos_clicked(){
     ui->contentPanel->setCurrentIndex(1);
}


void MainWindow::on_btnGotoSimulacion_clicked(){
    ui->contentPanel->setCurrentIndex(0);

}

MainStruct * MainWindow::cargarDatos(){

    //Almacen
    RegistroAlmacen * registro = new RegistroAlmacen();

    Carrito *carro= new Carrito();
    carro->capacidad = ui->txtCapacidadCar->text().toInt();
    carro->duracionTotal = ui->txtDurationCar->text().toInt();

    Almacen * almacenNuevo = new Almacen(carro, registro);

    //Machines
    ArrayMachines *arraymachines = new ArrayMachines();
    arraymachines->array[0]->min = ui->txtMinMezcladora1->text().toInt();
    arraymachines->array[0]->max = ui->txtMaxMecladora1->text().toInt();
    arraymachines->array[0]->duracionSegudos = ui->txtDurationMecladora1->text().toInt();
    arraymachines->array[0]->gramosProcesar =  ui->txtCantProcesarMezcladora1->text().toInt();

    arraymachines->array[1]->min = ui->txtMinMezcladora1->text().toInt();
    arraymachines->array[1]->max = ui->txtMaxMecladora1->text().toInt();
    arraymachines->array[1]->duracionSegudos = ui->txtDurationMecladora1->text().toInt();
    arraymachines->array[1]->gramosProcesar =  ui->txtCantProcesarMezcladora1->text().toInt();

    arraymachines->array[2]->min = ui->txtMinChocolatera->text().toInt();
    arraymachines->array[2]->max = ui->txtMaxChocolatera->text().toInt();
    arraymachines->array[2]->duracionSegudos = ui->txtDurationChocolatera->text().toInt();
    arraymachines->array[2]->gramosProcesar =  ui->txtCantProcesarChocolatera->text().toInt();

    //Main Struct
    MainStruct * mainStruct = new MainStruct(almacenNuevo, arraymachines);
    Ensambladora * nuevaEnsabladora = new Ensambladora();

    mainStruct->ensambladora  = nuevaEnsabladora;



}






