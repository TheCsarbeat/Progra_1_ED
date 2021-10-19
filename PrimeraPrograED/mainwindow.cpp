#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVBoxLayout>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    design();
    getUIWidgets();


}

MainWindow::~MainWindow(){
    delete ui;
}



void MainWindow::on_btnIniciar_clicked(){


    MainStruct * mainStruct = cargarDatos();


    mainThread = new thread_main();
    mainThread->__init__(mainStruct, this->ui->factoryPanel,arrayProgressBar, arrayCheackBoxOnOff);
    mainThread->start();

}

void MainWindow::design(){
    QVBoxLayout * lay = new QVBoxLayout();
    lay->addWidget(ui->lbCola);
    ui->scrollAreaContents->setLayout(lay);
    ui->contentPanel->setCurrentIndex(0);
}

void MainWindow::getUIWidgets(){

    //Array datos Machines
    arrayLbMachines[0] = this->ui->lbMachine1;
    arrayLbMachines[1] = this->ui->lbMachine2;
    arrayLbMachines[2] = this->ui->lbMachine3;

    arrayLbDatosMachines[0] = this->ui->lbDatosMachine1;
    arrayLbDatosMachines[1] = this->ui->lbDatosMachine2;
    arrayLbDatosMachines[2] = this->ui->lbDatosMachine3;

    //Array ProgressBar
    arrayProgressBar[0]= new EstructuraProgressBar(ui->progressCar, ui->lbProgressCar); //progressBar del carro
    arrayProgressBar[1]= new EstructuraProgressBar(ui->progressMachine1, ui->lbProgressMachine1); //progressBar del carro
    arrayProgressBar[2]= new EstructuraProgressBar(ui->progressMachine2, ui->lbProgressMachine2); //progressBar del carro
    arrayProgressBar[3]= new EstructuraProgressBar(ui->progressMachine3, ui->lbProgressMachine3); //progressBar del carro

    //Array Checkbox
    arrayCheackBoxOnOff[0] = this->ui->checkBoxCar;
    arrayCheackBoxOnOff[1] = this->ui->checkBoxMachine1;
    arrayCheackBoxOnOff[2] = this->ui->checkBoxMachine2;
    arrayCheackBoxOnOff[3] = this->ui->checkBoxMachine3;
}

void MainWindow::on_btnGotoDatos_clicked(){
     ui->contentPanel->setCurrentIndex(1);
}


void MainWindow::on_btnGoToSimulation_clicked(){
    ui->contentPanel->setCurrentIndex(0);

}

MainStruct * MainWindow::cargarDatos(){

    //Almacen
    RegistroAlmacen * registro = new RegistroAlmacen();

    Carrito *carro= new Carrito(this->ui->lbCarro, this->ui->lbDatosCar);
    carro->capacidad = ui->txtCapacidadCar->text().toInt();
    carro->duracionTotal = ui->txtDurationCar->text().toInt();

    Almacen * almacenNuevo = new Almacen(carro, registro);

    //Machines
    ArrayMachines *arraymachines = new ArrayMachines(arrayLbMachines,arrayLbDatosMachines);
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

    //ColaPeticiones
    ColaPeticiones *cola = new ColaPeticiones(ui->lbCola);

    Receta * recetaCookies = new Receta(5,5);

    //Main Struct
    MainStruct * mainStruct = new MainStruct(almacenNuevo, arraymachines,recetaCookies, cola);
    Ensambladora * nuevaEnsabladora = new Ensambladora();

    mainStruct->ensambladora  = nuevaEnsabladora;
}









