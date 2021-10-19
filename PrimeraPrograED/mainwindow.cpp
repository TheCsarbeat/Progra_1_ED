#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVBoxLayout>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
<<<<<<< HEAD
    ui->contentPanel->setCurrentIndex(0);
=======
    design();
    getUIWidgets();


>>>>>>> origin/picherks
}

MainWindow::~MainWindow(){
    delete ui;
}



void MainWindow::on_btnIniciar_clicked(){


    MainStruct * mainStruct = cargarDatos();
<<<<<<< HEAD

    QLabel * arrayLbMachines[6];
    arrayLbMachines[0] = this->ui->lbMachine1;
    arrayLbMachines[1] = this->ui->lbMachine2;
    arrayLbMachines[2] = this->ui->lbMachine3;

    arrayLbMachines[3] = this->ui->lbDatosMachine1;
    arrayLbMachines[4] = this->ui->lbDatosMachine2;
    arrayLbMachines[5] = this->ui->lbDatosMachine3;

    QLabel * arrayLbEnsambladora[4];
    arrayLbEnsambladora[0] = this->ui->lbDatosBanda1;
    arrayLbEnsambladora[1] = this->ui->lbDatosBanda2;
    arrayLbEnsambladora[2] = this->ui->lbDatosEnsambladora;
    arrayLbEnsambladora[3] = this->ui->lbDatosBandaHorno;

    mainThread = new thread_main();
    mainThread->__init__(mainStruct, this->ui->factoryPanel,this->ui->lbCarro, arrayLbMachines, this->ui->lbCola,arrayLbEnsambladora);
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
=======


    mainThread = new thread_main();
    mainThread->__init__(mainStruct, this->ui->factoryPanel,arrayProgressBar, arrayCheackBoxOnOff);
    mainThread->start();
>>>>>>> origin/picherks

}

<<<<<<< HEAD
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

    Receta * recetaCookies = new Receta(5,5);

    Horno * horno = new Horno();

    //Main Struct
    MainStruct * mainStruct = new MainStruct(almacenNuevo, arraymachines,recetaCookies, horno);
    Ensambladora * nuevaEnsabladora = new Ensambladora();

    nuevaEnsabladora->bandas->array[0]->capacidad = 50;
    nuevaEnsabladora->bandas->array[1]->capacidad = 50;
    nuevaEnsabladora->cant = 10;
    nuevaEnsabladora->duracionSegundos = 5;

    mainStruct->ensambladora  = nuevaEnsabladora;
}






=======
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
    arrayProgressBar[1]= new EstructuraProgressBar(ui->progressMachine1, ui->lbProgressMachine1); //progressBar del Machine 1
    arrayProgressBar[2]= new EstructuraProgressBar(ui->progressMachine2, ui->lbProgressMachine2); //progressBar del Machine 2
    arrayProgressBar[3]= new EstructuraProgressBar(ui->progressMachine3, ui->lbProgressMachine3); //progressBar del Chocolatera
    arrayProgressBar[4]= new EstructuraProgressBar(ui->progressAssembler, ui->lbProgressAssembler); //progressBar de Assembler

    //Array Checkbox
    arrayCheackBoxOnOff[0] = this->ui->checkBoxCar;
    arrayCheackBoxOnOff[1] = this->ui->checkBoxMachine1;
    arrayCheackBoxOnOff[2] = this->ui->checkBoxMachine2;
    arrayCheackBoxOnOff[3] = this->ui->checkBoxMachine3;
    arrayCheackBoxOnOff[4] = this->ui->checkBoxAssembler;
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

    arraymachines->array[1]->min = ui->txtMinMezcladora2->text().toInt();
    arraymachines->array[1]->max = ui->txtMaxMecladora2->text().toInt();
    arraymachines->array[1]->duracionSegudos = ui->txttDurationMecladora2->text().toInt();
    arraymachines->array[1]->gramosProcesar =  ui->txtCantProcesarMezcladora2->text().toInt();

    arraymachines->array[2]->min = ui->txtMinChocolatera->text().toInt();
    arraymachines->array[2]->max = ui->txtMaxChocolatera->text().toInt();
    arraymachines->array[2]->duracionSegudos = ui->txtDurationChocolatera->text().toInt();
    arraymachines->array[2]->gramosProcesar =  ui->txtCantProcesarChocolatera->text().toInt();

    //ColaPeticiones
    ColaPeticiones *cola = new ColaPeticiones(ui->lbCola);

    //Assembler
    Ensambladora * nuevaEnsabladora = new Ensambladora(ui->lbNameAssembler, ui->lbDatosAssembler, ui->lbDatosBanda1Mezcla, ui->lbDatosBanda2Chocolate);

    nuevaEnsabladora->cant = ui->txtCantProcesarAssembler->text().toInt();
    nuevaEnsabladora->duracionSegundos = ui->txtDurationAssembler->text().toInt();
    //Bandas
    nuevaEnsabladora->bandas->array[0]->capacidad = ui->txtMaxBanda1Mezcla->text().toInt();
    nuevaEnsabladora->bandas->array[1]->capacidad = ui->txtMaxBanda2Chocolate->text().toInt();



    Receta * recetaCookies = new Receta(5,5);

    Horno * horno = new Horno();


    //Main Struct
    MainStruct * mainStruct = new MainStruct(almacenNuevo, arraymachines,recetaCookies, cola, nuevaEnsabladora,horno);
    return mainStruct;
}









>>>>>>> origin/picherks
