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
    cargarDatos();


}

MainWindow::~MainWindow(){
    delete ui;
}

//---------------------------------------------Inicio and Stop
void MainWindow::on_btnOnOff_clicked(){
    if(ui->lbStateOnOff->text() == "Start"){
        //Change Desing
        ui->lbStateOnOff->setText("Stop");
        ui->btnOnOff->setStyleSheet("border-width: 1px;border-style: solid;image:url(':/images/power-off.png');");

        ui->btnPausedPlay->setStyleSheet("border-width: 1px;border-style: solid;image:url(':/images/pause.png');");
        ui->btnPausedPlay->setEnabled(true);
        ui->lbStatedPausedResume->setStyleSheet("color:black;");

        mainThread = new thread_main();
        mainThread->__init__(this->mainStruct,arrayProgressBar, arrayCheackBoxOnOff);
        mainThread->start();
    }else{
        //Cambiar desing
        ui->lbStateOnOff->setText("Start");
        ui->btnOnOff->setStyleSheet("border-width: 1px;border-style: solid;image:url(':/images/power-on.png');");

        mainThread->stop();
        mainStruct = new MainStruct();
        getUIWidgets();
        cargarDatos();

        ui->btnPausedPlay->setStyleSheet("border-width: 1px;border-style: solid;image:url(':/images/pause-unavailable.png');");
        ui->btnPausedPlay->setEnabled(false);
        ui->lbStatedPausedResume->setStyleSheet("color:gray;");
        ui->lbStatedPausedResume->setText("Pause");
    }
}
void MainWindow::on_btnPausedPlay_clicked(){
    if(ui->lbStatedPausedResume->text() == "Pause"){
            //Change Desing
            ui->lbStatedPausedResume->setText("Resume");
            ui->btnPausedPlay->setStyleSheet("border-width: 1px;border-style: solid;image:url(':/images/play.png');");

            mainThread->pause();
        }else{
            //Cambiar desing
            ui->lbStatedPausedResume->setText("Pause");
            ui->btnPausedPlay->setStyleSheet("border-width: 1px;border-style: solid;image:url(':/images/pause.png');");
            mainThread->resume();
        }
}

//--------------------------------------Navegacion
void MainWindow::on_btnGoToDatos_clicked(){
    if(ui->lbStatedPausedResume->text()== "Resume" || ui->lbStateOnOff->text() == "Start"){
             ui->contentPanel->setCurrentIndex(1);
         }
}
void MainWindow::on_btnGoToSimulation_clicked(){
    ui->contentPanel->setCurrentIndex(0);
    loadDataOnPaused();
}

//--------------------------------------Tipos de galletas Lista Circular
void MainWindow::on_btnAgregarTipoGalleta_clicked(){
    QString nombre = ui->txtNombreTipoGalleta->text();
        int cantidad = ui->txtCantidadTipoGalleta->text().toInt();

        TipoGalleta *tipo = new TipoGalleta(nombre, cantidad);

        if(!(nombre.isEmpty() && ui->txtCantidadTipoGalleta->text().isEmpty())){
            if(!this->mainStruct->listaCircularTiposGalletas->exist(tipo)){
                this->mainStruct->listaCircularTiposGalletas->insertar(tipo);
                ui->listTiposGalletas->addItem(tipo->toString());
                ui->txtNombreTipoGalleta->setText("");
                ui->txtCantidadTipoGalleta->setText("");

                ui->cboPlanificacion->addItem(tipo->toString());
            }
        }
}


void MainWindow::on_btnEliminarTipoGalleta_clicked(){
    QString nombre = ui->txtNombreTipoGalleta->text();
        int cantidad = ui->txtCantidadTipoGalleta->text().toInt();

        TipoGalleta *tipo = new TipoGalleta(nombre, cantidad);

        if(!(nombre.isEmpty() && ui->txtCantidadTipoGalleta->text().isEmpty())){
            qDebug()<<"ENTRE";
            if(this->mainStruct->listaCircularTiposGalletas->exist(tipo)){
                qDebug()<<"ENTdsfsdfRE";
                this->mainStruct->listaCircularTiposGalletas->eliminar(nombre, cantidad);
                ui->listTiposGalletas->clear();
                ui->listTiposGalletas->addItems(this->mainStruct->listaCircularTiposGalletas->toString());
                ui->txtNombreTipoGalleta->setText("");
                ui->txtCantidadTipoGalleta->setText("");

                //Plafinicación
                ui->cboPlanificacion->clear();
                QStringList tiposPlanificacion = this->mainStruct->listaCircularTiposGalletas->toString();
                for (int i =0; i<tiposPlanificacion.length(); i++) {
                    ui->cboPlanificacion->addItem(tiposPlanificacion.at(i));
                }
            }
        }
}


void MainWindow::on_listTiposGalletas_itemClicked(QListWidgetItem *item){
    QStringList data = item->text().split(", ");
    ui->txtNombreTipoGalleta->setText(data.at(0));
    ui->txtCantidadTipoGalleta->setText(data.at(1));
}


//--------------------------------------Panificaciones Lista simple
void MainWindow::on_btnAgregarPlanificacion_clicked(){
    if(!(ui->txtCantidadPlanificacion->text().isEmpty() && ui->cboPlanificacion->currentIndex()<0)){
            QString texto = ui->cboPlanificacion->currentText();
            TipoGalleta * tipo = new TipoGalleta(texto.split(", ").at(0),texto.split(", ").at(1).toInt());

            int cantidad = ui->txtCantidadPlanificacion->text().toInt();

            Planificacion * planificacion = new Planificacion(tipo, cantidad);
            this->mainStruct->listaPlanificaciones->insertarAlInicio(planificacion);
            ui->listPlanificador->clear();
            ui->listPlanificador->addItems(this->mainStruct->listaPlanificaciones->toString());
            ui->cboPlanificacion->setCurrentIndex(-1);
            ui->txtCantidadPlanificacion->setText("");
        }
}


void MainWindow::on_btnEliminarPlanificacion_clicked(){
    QString texto = ui->cboPlanificacion->currentText();
        if(!(ui->txtCantidadPlanificacion->text().isEmpty() && texto.isEmpty())){

            TipoGalleta * tipo = new TipoGalleta(texto.split(", ").at(0),texto.split(", ").at(1).toInt());
            int cantidad = ui->txtCantidadPlanificacion->text().toInt();
            this->mainStruct->listaPlanificaciones->borrar(tipo->toString(), cantidad);

            ui->cboPlanificacion->setCurrentIndex(-1);
            ui->txtCantidadPlanificacion->setText("");

            ui->listPlanificador->clear();
            ui->listPlanificador->addItems(this->mainStruct->listaPlanificaciones->toString());
        }
}


void MainWindow::on_listPlanificador_itemClicked(QListWidgetItem *item){
    QStringList data = item->text().split(" | ");
        ui->txtCantidadPlanificacion->setText(data.at(1));
        ui->cboPlanificacion->setCurrentText(data.at(0));
}



//--------------------------------------Funciones Utiles
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

    //Array datos bandejas
    arrayLbDatosBandejas[0] = this->ui->lbDatosBandeja1;
    arrayLbDatosBandejas[1] = this->ui->lbDatosBandeja2;
    arrayLbDatosBandejas[2] = this->ui->lbDatosBandeja3;
    arrayLbDatosBandejas[3] = this->ui->lbDatosBandeja4;
    arrayLbDatosBandejas[4] = this->ui->lbDatosBandeja5;
    arrayLbDatosBandejas[5] = this->ui->lbDatosBandeja6;

    //Array ProgressBar
    arrayProgressBar[0]= new EstructuraProgressBar(ui->progressCar, ui->lbProgressCar); //progressBar del carro
    arrayProgressBar[1]= new EstructuraProgressBar(ui->progressMachine1, ui->lbProgressMachine1); //progressBar del Machine 1
    arrayProgressBar[2]= new EstructuraProgressBar(ui->progressMachine2, ui->lbProgressMachine2); //progressBar del Machine 2
    arrayProgressBar[3]= new EstructuraProgressBar(ui->progressMachine3, ui->lbProgressMachine3); //progressBar del Chocolatera
    arrayProgressBar[4]= new EstructuraProgressBar(ui->progressAssembler, ui->lbProgressAssembler); //progressBar de Assembler
    arrayProgressBar[5]= new EstructuraProgressBar(ui->progressHorno, ui->lbProgressHorno);

    //Array Checkbox
    arrayCheackBoxOnOff[0] = this->ui->checkBoxCar;
    arrayCheackBoxOnOff[1] = this->ui->checkBoxMachine1;
    arrayCheackBoxOnOff[2] = this->ui->checkBoxMachine2;
    arrayCheackBoxOnOff[3] = this->ui->checkBoxMachine3;
    arrayCheackBoxOnOff[4] = this->ui->checkBoxAssembler;
    arrayCheackBoxOnOff[5] = this->ui->checkBoxHorno;


}
void MainWindow::cargarDatos(){

    //Almacen
    Carrito *carro= new Carrito(this->ui->lbCarro, this->ui->lbDatosCar);

    carro->capacidad = ui->txtCapacidadCar->text().toInt();
    carro->duracionTotal = ui->txtDurationCar->text().toInt();

    Almacen * almacenNuevo = new Almacen(carro);

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



    Receta * recetaCookies = new Receta(ui->txtCantMezclaReceta->text().toInt(),ui->txtCantChocolateReceta->text().toInt());

    Horno * horno = new Horno(ui->lbDatosBandaHorno, 90, 5, 3,10,ui->lbDatosHorno,arrayLbDatosBandejas);
    //------------Horno

    horno->banda->capacidad = ui->txtCapacidadBandaHorno->text().toInt();
    horno->cantidadRellenado = ui->txtCantRellenado->text().toInt();
    horno->capacidad = ui->txtCapacidadHorno->text().toInt();
    horno->tiempoHorneado = ui->txtTiempoHorneado->text().toInt();
    horno->tiempoRellenado = ui->txtTiempoRellenado->text().toInt();

        //Bandejas
        horno->bandejas->array[0]->capacidad = ui->txtMaxBandeja->text().toInt();
        horno->bandejas->array[1]->capacidad = ui->txtMaxBandeja_2->text().toInt();
        horno->bandejas->array[2]->capacidad = ui->txtMaxBandeja_3->text().toInt();
        horno->bandejas->array[3]->capacidad = ui->txtMaxBandeja_4->text().toInt();
        horno->bandejas->array[4]->capacidad = ui->txtMaxBandeja_5->text().toInt();
        horno->bandejas->array[5]->capacidad = ui->txtMaxBandeja_6->text().toInt();


    //Main Struct
    mainStruct = new MainStruct(almacenNuevo, arraymachines,recetaCookies, cola, nuevaEnsabladora,horno);

    //Base de lista circular
    this->mainStruct->listaCircularTiposGalletas->insertar("Caja",50);
    this->mainStruct->listaCircularTiposGalletas->insertar("Paquetote",25);
    this->mainStruct->listaCircularTiposGalletas->insertar("Paquete",10);
    this->mainStruct->listaCircularTiposGalletas->insertar("Tubo",16);
    this->mainStruct->listaCircularTiposGalletas->insertar("Bolsitica",2);
    this->mainStruct->listaCircularTiposGalletas->insertar("Bolsita",4);
    this->mainStruct->listaCircularTiposGalletas->insertar("Bolsa",8);
    this->mainStruct->listaCircularTiposGalletas->insertar("Bolsota",16);
    this->mainStruct->listaCircularTiposGalletas->insertar("Bolsatota",32);
    ui->listTiposGalletas->addItems(this->mainStruct->listaCircularTiposGalletas->toString());

    //Plafinicación
    ui->cboPlanificacion->clear();
    QStringList tiposPlanificacion = this->mainStruct->listaCircularTiposGalletas->toString();
    for (int i =0; i<tiposPlanificacion.length(); i++) {
        ui->cboPlanificacion->addItem(tiposPlanificacion.at(i));
    }

    imprimirDatos();
}

void MainWindow::imprimirDatos(){
    //----------------ImprimirDatos---------------------------

    this->mainStruct->almacen->carrito->imprimir();
    this->mainStruct->colaPeticiones->imprimir();

    for(int i = 0; i<3; i++){
        this->mainStruct->arrayMachine->array[i]->imprimirDatos();
    }

    for(int i= 0; i<2; i++){
        this->mainStruct->ensambladora->bandas->array[i]->imprimir();
    }
    this->mainStruct->ensambladora->imprimir();

    this->mainStruct->horno->banda->imprimir();

    this->mainStruct->horno->imprimir();
    for(int i= 0; i<6; i++){
        this->mainStruct->horno->bandejas->array[i]->imprimir();
    }
}

void MainWindow::loadDataOnPaused(){

    //Receta
    mainStruct->receta->cantChocolate = ui->txtCantMezclaReceta->text().toInt();
    mainStruct->receta->cantMezcla = ui->txtCantChocolateReceta->text().toInt();

    //----------Almacen
    mainStruct->almacen->carrito->capacidad = ui->txtCapacidadCar->text().toInt();
    mainStruct->almacen->carrito->duracionTotal = ui->txtDurationCar->text().toInt();

    //-----------Machines
    mainStruct->arrayMachine->array[0]->min = ui->txtMinMezcladora1->text().toInt();
    mainStruct->arrayMachine->array[0]->max = ui->txtMaxMecladora1->text().toInt();
    mainStruct->arrayMachine->array[0]->duracionSegudos = ui->txtDurationMecladora1->text().toInt();
    mainStruct->arrayMachine->array[0]->gramosProcesar =  ui->txtCantProcesarMezcladora1->text().toInt();

    mainStruct->arrayMachine->array[1]->min = ui->txtMinMezcladora2->text().toInt();
    mainStruct->arrayMachine->array[1]->max = ui->txtMaxMecladora2->text().toInt();
    mainStruct->arrayMachine->array[1]->duracionSegudos = ui->txttDurationMecladora2->text().toInt();
    mainStruct->arrayMachine->array[1]->gramosProcesar =  ui->txtCantProcesarMezcladora2->text().toInt();

    mainStruct->arrayMachine->array[2]->min = ui->txtMinChocolatera->text().toInt();
    mainStruct->arrayMachine->array[2]->max = ui->txtMaxChocolatera->text().toInt();
    mainStruct->arrayMachine->array[2]->duracionSegudos = ui->txtDurationChocolatera->text().toInt();
    mainStruct->arrayMachine->array[2]->gramosProcesar =  ui->txtCantProcesarChocolatera->text().toInt();

    //--------------Ensambladora
    mainStruct->ensambladora->cant = ui->txtCantProcesarAssembler->text().toInt();
    mainStruct->ensambladora->duracionSegundos = ui->txtDurationAssembler->text().toInt();

        //Bandas
        mainStruct->ensambladora->bandas->array[0]->capacidad = ui->txtMaxBanda1Mezcla->text().toInt();
        mainStruct->ensambladora->bandas->array[1]->capacidad = ui->txtMaxBanda2Chocolate->text().toInt();

    //------------Horno
    mainStruct->horno->cantidadRellenado = ui->txtCantRellenado->text().toInt();
    mainStruct->horno->capacidad = ui->txtCapacidadHorno->text().toInt();
    mainStruct->horno->tiempoHorneado = ui->txtTiempoHorneado->text().toInt();
    mainStruct->horno->tiempoRellenado = ui->txtTiempoRellenado->text().toInt();

        //Bandejas
        mainStruct->horno->bandejas->array[0]->capacidad = ui->txtMaxBandeja->text().toInt();
        mainStruct->horno->bandejas->array[1]->capacidad = ui->txtMaxBandeja_2->text().toInt();
        mainStruct->horno->bandejas->array[2]->capacidad = ui->txtMaxBandeja_3->text().toInt();
        mainStruct->horno->bandejas->array[3]->capacidad = ui->txtMaxBandeja_4->text().toInt();
        mainStruct->horno->bandejas->array[4]->capacidad = ui->txtMaxBandeja_5->text().toInt();
        mainStruct->horno->bandejas->array[5]->capacidad = ui->txtMaxBandeja_6->text().toInt();


    imprimirDatos();
}

void MainWindow::on_checkBoxBandeja3_clicked()
{
    if(mainStruct->horno->bandejas->array[2]->active){
        mainStruct->horno->bandejas->array[2]->active = false;
    }else{
        mainStruct->horno->bandejas->array[2]->active = true;
    }
}


void MainWindow::on_checkBoxBandeja4_clicked()
{
    if(mainStruct->horno->bandejas->array[3]->active){
        mainStruct->horno->bandejas->array[3]->active = false;
    }else{
        mainStruct->horno->bandejas->array[3]->active = true;
    }
}


void MainWindow::on_checkBoxBandeja5_clicked()
{
    if(mainStruct->horno->bandejas->array[4]->active){
        mainStruct->horno->bandejas->array[4]->active = false;
    }else{
        mainStruct->horno->bandejas->array[4]->active = true;
    }
}


void MainWindow::on_checkBoxBandeja6_clicked()
{
    if(mainStruct->horno->bandejas->array[5]->active){
        mainStruct->horno->bandejas->array[5]->active = false;
    }else{
        mainStruct->horno->bandejas->array[5]->active = true;
    }
}

