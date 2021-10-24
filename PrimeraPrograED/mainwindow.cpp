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
        getUIWidgets();
        mainStruct = new MainStruct();

        cargarDatos();

        //Change Desing
        ui->lbStateOnOff->setText("Stop");
        ui->btnOnOff->setStyleSheet("border-width: 1px;border-style: solid;image:url(':/images/power-off.png');");

        ui->btnPausedPlay->setStyleSheet("border-width: 1px;border-style: solid;image:url(':/images/pause.png');");
        ui->btnPausedPlay->setEnabled(true);
        ui->lbStatedPausedResume->setStyleSheet("color:black;");

        mainThread = new thread_main();
        mainThread->__init__(this->mainStruct,arrayProgressBar, arrayCheackBoxOnOff, arrayCheckBoxHorno, ui->centralwidget);
        mainThread->start();
    }else{
        //Cambiar desing
        ui->lbStateOnOff->setText("Start");
        ui->btnOnOff->setStyleSheet("border-width: 1px;border-style: solid;image:url(':/images/power-on.png');");

        mainThread->stop();
        ui->listPlanificador->clear();
        ui->listTiposGalletas->clear();

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
        double tiempoEmpacdo = ui->txtTiempoEmpacado->text().toDouble();        
        int cantEmpacado = ui->txtCantEmpacado->text().toInt();

        int capacidadTransporte = ui->txtCapacidadTransporte->text().toInt();
        double velocidadTransporte = ui->txtVelocidadTransporte->text().toDouble();
        TipoGalleta *tipo = new TipoGalleta(nombre, cantidad, tiempoEmpacdo, cantEmpacado, capacidadTransporte, velocidadTransporte);

        if(!(nombre.isEmpty() && ui->txtCantidadTipoGalleta->text().isEmpty() && ui->txtTiempoEmpacado->text().isEmpty() && ui->txtCantEmpacado->text().isEmpty())){
            if(!this->mainStruct->listaCircularTiposGalletas->exist(tipo)){
                this->mainStruct->listaCircularTiposGalletas->insertar(tipo);
                ui->listTiposGalletas->addItem(tipo->toString());
                ui->txtNombreTipoGalleta->setText("");
                ui->txtCantidadTipoGalleta->setText("");

                ui->txtTiempoEmpacado->setText("");
                ui->txtCantEmpacado->setText("");

                ui->txtCapacidadTransporte->setText("");
                ui->txtVelocidadTransporte->setText("");
                ui->cboPlanificacion->addItem(tipo->toString());
            }
        }
}


void MainWindow::on_btnEliminarTipoGalleta_clicked(){
    QString nombre = ui->txtNombreTipoGalleta->text();
        int cantidad = ui->txtCantidadTipoGalleta->text().toInt();
        double tiempoEmpacdo = ui->txtTiempoEmpacado->text().toDouble();
        int cantEmpacado = ui->txtCantEmpacado->text().toInt();

        TipoGalleta *tipo = new TipoGalleta(nombre, cantidad, tiempoEmpacdo, cantEmpacado);

        if(!(nombre.isEmpty() && ui->txtCantidadTipoGalleta->text().isEmpty() && ui->txtTiempoEmpacado->text().isEmpty() && ui->txtCantEmpacado->text().isEmpty())){

            if(this->mainStruct->listaCircularTiposGalletas->exist(tipo)){

                this->mainStruct->listaCircularTiposGalletas->eliminar(nombre, cantidad);
                ui->listTiposGalletas->clear();
                ui->listTiposGalletas->addItems(this->mainStruct->listaCircularTiposGalletas->toString());
                ui->txtNombreTipoGalleta->setText("");
                ui->txtCantidadTipoGalleta->setText("");
                ui->txtTiempoEmpacado->setText("");
                ui->txtCantEmpacado->setText("");
                ui->txtCapacidadTransporte->setText("");
                ui->txtVelocidadTransporte->setText("");

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
    ui->txtTiempoEmpacado->setText(data.at(2));
    ui->txtCantEmpacado->setText(data.at(3));
}


//--------------------------------------Panificaciones Lista simple
void MainWindow::on_btnAgregarPlanificacion_clicked(){
    if(!(ui->txtCantidadPlanificacion->text().isEmpty() && ui->cboPlanificacion->currentIndex()<0) && ui->lbStateOnOff->text() == "Start"){
            QStringList texto = ui->cboPlanificacion->currentText().split(", ");

            TipoGalleta * tipo = new TipoGalleta(texto.at(0),texto.at(1).toInt(),texto.at(2).toDouble(),texto.at(3).toInt(),texto.at(4).toInt(),texto.at(5).toDouble());

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
        if(!(ui->txtCantidadPlanificacion->text().isEmpty() && texto.isEmpty() && ui->lbStateOnOff->text() == "Start")){

            QStringList texto = ui->cboPlanificacion->currentText().split(", ");

            TipoGalleta * tipo = new TipoGalleta(texto.at(0),texto.at(1).toInt(),texto.at(2).toDouble(),texto.at(3).toInt());
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

    QVBoxLayout * lay1 = new QVBoxLayout();
    lay1->addWidget(ui->lbPaquetesSupervisados);
    ui->scrollAreaContents_2->setLayout(lay1);

    QVBoxLayout * lay2 = new QVBoxLayout();
    lay2->addWidget(ui->lbTransportadores);
    ui->scrollAreaContents_3->setLayout(lay2);

    QVBoxLayout * lay3 = new QVBoxLayout();
    lay3->addWidget(ui->lbTransportadores_2);
    ui->scrollArea_2->setLayout(lay3);

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

    //Array CheckBox Horno
    arrayCheckBoxHornoBandejas[0] = this->ui->checkBoxIconBandeja1;
    arrayCheckBoxHornoBandejas[1] = this->ui->checkBoxIconBandeja2;
    arrayCheckBoxHornoBandejas[2] = this->ui->checkBoxIconBandeja3;
    arrayCheckBoxHornoBandejas[3] = this->ui->checkBoxIconBandeja4;
    arrayCheckBoxHornoBandejas[4] = this->ui->checkBoxIconBandeja5;
    arrayCheckBoxHornoBandejas[5] = this->ui->checkBoxIconBandeja6;

    //Array ProgressBar
    arrayProgressBar[0]= new EstructuraProgressBar(ui->progressCar, ui->lbProgressCar); //progressBar del carro
    arrayProgressBar[1]= new EstructuraProgressBar(ui->progressMachine1, ui->lbProgressMachine1); //progressBar del Machine 1
    arrayProgressBar[2]= new EstructuraProgressBar(ui->progressMachine2, ui->lbProgressMachine2); //progressBar del Machine 2
    arrayProgressBar[3]= new EstructuraProgressBar(ui->progressMachine3, ui->lbProgressMachine3); //progressBar del Chocolatera
    arrayProgressBar[4]= new EstructuraProgressBar(ui->progressAssembler, ui->lbProgressAssembler); //progressBar de Assembler
    arrayProgressBar[5]= new EstructuraProgressBar(ui->progressHorno, ui->lbProgressHorno);
    //
    arrayProgressBar[7]= new EstructuraProgressBar(ui->progressEmpacadora, ui->lbProgressEmpacadora);
    arrayProgressBar[8]= new EstructuraProgressBar(ui->progressEmpacadora, ui->lbProgressEmpacadora);

    //Array Checkbox
    arrayCheackBoxOnOff[0] = this->ui->checkBoxCar;
    arrayCheackBoxOnOff[1] = this->ui->checkBoxMachine1;
    arrayCheackBoxOnOff[2] = this->ui->checkBoxMachine2;
    arrayCheackBoxOnOff[3] = this->ui->checkBoxMachine3;
    arrayCheackBoxOnOff[4] = this->ui->checkBoxAssembler;
    arrayCheackBoxOnOff[5] = this->ui->checkBoxInspector1;
    arrayCheackBoxOnOff[6] = this->ui->checkBoxInspector2;
    arrayCheackBoxOnOff[7] = this->ui->checkBoxEmpacadora;
    arrayCheackBoxOnOff[8] = this->ui->checkBoxTransportadores;

    //Array CheckBox Horno
    arrayCheckBoxHorno[0] = this->ui->checkBoxHorno;
    arrayCheckBoxHorno[1] = this->ui->checkBoxBandeja3;
    arrayCheckBoxHorno[2] = this->ui->checkBoxBandeja4;
    arrayCheckBoxHorno[3] = this->ui->checkBoxBandeja5;
    arrayCheckBoxHorno[4] = this->ui->checkBoxBandeja6;

}
void MainWindow::cargarDatos(){

    //Base de lista circular                                nombre, cantGalletas, tiempoEmpacdo, cantEmpacado estos dos últimos por el tipo completo.

    listC->insertar("Caja",50, 6.3, 3,6,10.0);
    listC->insertar("Paquete",20,5.2,4,6,5.1);
    listC->insertar("Tubo",16, 5.6,2,10,5.0);
    listC->insertar("Bolsa",2,2.4,6,12,8.0);

    ui->listPlanificador->clear();
    ui->listPlanificador->addItems(listP->toString());

    ui->listTiposGalletas->clear();
    ui->listTiposGalletas->addItems(listC->toString());

    //Plafinicación
    ui->cboPlanificacion->clear();
    QStringList tiposPlanificacion = listC->toString();
    for (int i =0; i<tiposPlanificacion.length(); i++) {
        ui->cboPlanificacion->addItem(tiposPlanificacion.at(i));
    }


    //Almacen
    Carrito *carro= new Carrito(this->ui->lbCarro, this->ui->lbDatosCar);

    carro->capacidad = ui->txtCapacidadCar->text().toInt();
    carro->duracionTotal = ui->txtDurationCar->text().toDouble();

    Almacen * almacenNuevo = new Almacen(carro);

    //Machines
    ArrayMachines *arraymachines = new ArrayMachines(arrayLbMachines,arrayLbDatosMachines);
    arraymachines->array[0]->min = ui->txtMinMezcladora1->text().toInt();
    arraymachines->array[0]->max = ui->txtMaxMecladora1->text().toInt();
    arraymachines->array[0]->duracionSegudos = ui->txtDurationMecladora1->text().toDouble();
    arraymachines->array[0]->gramosProcesar =  ui->txtCantProcesarMezcladora1->text().toInt();

    arraymachines->array[1]->min = ui->txtMinMezcladora2->text().toInt();
    arraymachines->array[1]->max = ui->txtMaxMecladora2->text().toInt();
    arraymachines->array[1]->duracionSegudos = ui->txttDurationMecladora2->text().toDouble();
    arraymachines->array[1]->gramosProcesar =  ui->txtCantProcesarMezcladora2->text().toInt();

    arraymachines->array[2]->min = ui->txtMinChocolatera->text().toInt();
    arraymachines->array[2]->max = ui->txtMaxChocolatera->text().toInt();
    arraymachines->array[2]->duracionSegudos = ui->txtDurationChocolatera->text().toDouble();
    arraymachines->array[2]->gramosProcesar =  ui->txtCantProcesarChocolatera->text().toInt();

    //ColaPeticiones
    ColaPeticiones *cola = new ColaPeticiones(ui->lbCola);

    //Assembler
    Ensambladora * nuevaEnsabladora = new Ensambladora(ui->lbNameAssembler, ui->lbDatosAssembler, ui->lbDatosBanda1Mezcla, ui->lbDatosBanda2Chocolate);

    nuevaEnsabladora->cant = ui->txtCantProcesarAssembler->text().toInt();
    nuevaEnsabladora->duracionSegundos = ui->txtDurationAssembler->text().toDouble();
    //Bandas
    nuevaEnsabladora->bandas->array[0]->capacidad = ui->txtMaxBanda1Mezcla->text().toInt();
    nuevaEnsabladora->bandas->array[1]->capacidad = ui->txtMaxBanda2Chocolate->text().toInt();



    Receta * recetaCookies = new Receta(ui->txtCantMezclaReceta->text().toInt(),ui->txtCantChocolateReceta->text().toInt());

    Inspectores * inspectores = new Inspectores(this->ui->lbDatosBandaEmpacadora1, this->ui->lbDatosBandaEmpacadora2);

    //Bandas Inspectores
    inspectores->arrayBandas->array[0]->capacidad = ui->txtCapacidadBandaEmpacadora1->text().toInt();
    inspectores->arrayBandas->array[1]->capacidad = ui->txtCapacidadBandaEmpacadora2->text().toInt();

    //Inspectores
    inspectores->arrayInspectores->array[0]->capacidad = ui->txtCantInspeccionar1->text().toInt();
    inspectores->arrayInspectores->array[0]->lbDatos = this->ui->lbDatosInspector1;
    inspectores->arrayInspectores->array[0]->tiempo = ui->txtTiempoInspector1->text().toInt();
    inspectores->arrayInspectores->array[0]->rate = ui->txtProbabilidadInspector1->text().toInt();
    inspectores->arrayInspectores->array[0]->lbTitle = ui->lbNameInspector1;

    inspectores->arrayInspectores->array[1]->capacidad = ui->txtCantInspeccionar2->text().toInt();;
    inspectores->arrayInspectores->array[1]->lbDatos = this->ui->lbDatosInspector2;
    inspectores->arrayInspectores->array[1]->tiempo = ui->txtTiempoInspector2->text().toInt();
    inspectores->arrayInspectores->array[1]->rate = ui->txtProbabilidadInspector2->text().toInt();;
    inspectores->arrayInspectores->array[1]->lbTitle = ui->lbNameInspector2;

    //------------Horno
    Horno * horno = new Horno(ui->lbDatosBandaHorno, 5, 3, 10,ui->lbDatosHorno,arrayLbDatosBandejas, arrayCheckBoxHornoBandejas);

    horno->banda->capacidad = ui->txtCapacidadBandaHorno->text().toInt();
    horno->cantidadRellenado = ui->txtCantRellenado->text().toInt();
    horno->tiempoHorneado = ui->txtTiempoHorneado->text().toInt();
    horno->tiempoRellenado = ui->txtTiempoRellenado->text().toInt();

        //Bandejas
        horno->bandejas->array[0]->capacidad = ui->txtMaxBandeja->text().toInt();
        horno->bandejas->array[1]->capacidad = ui->txtMaxBandeja_2->text().toInt();
        horno->bandejas->array[2]->capacidad = ui->txtMaxBandeja_3->text().toInt();
        horno->bandejas->array[3]->capacidad = ui->txtMaxBandeja_4->text().toInt();
        horno->bandejas->array[4]->capacidad = ui->txtMaxBandeja_5->text().toInt();
        horno->bandejas->array[5]->capacidad = ui->txtMaxBandeja_6->text().toInt();

    //Empacadora
    Empacadora *nuevaEmpacadora = new Empacadora(listP, ui->lbNameEmpacadora, ui->lbDatosEmpacadora,ui->lbBandaEmpacadoraSupervisada, ui->lbPaquetesSupervisados);
    nuevaEmpacadora->banda->capacidad = ui->txtCapacidadBandaCalidad_3->text().toInt();
    nuevaEmpacadora->banda->cantNow = 0;

    //Transportadores
    ArrayTransportadores * arrayTransportadores = new ArrayTransportadores(listP, ui->lbTransportadores_2, ui->lbTransportadores);

    //Main Struct
    mainStruct = new MainStruct(almacenNuevo, arraymachines,recetaCookies, cola, nuevaEnsabladora,horno,inspectores, listC, listP, nuevaEmpacadora,arrayTransportadores);
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

    this->mainStruct->inspectores->imprimir();
    //Empacadora
    this->mainStruct->empacadora->banda->imprimir();
    this->mainStruct->empacadora->imprimir();


}

void MainWindow::loadDataOnPaused(){

    //Lista simple planificaciones
    for (int i = 0; i<ui->listPlanificador->count(); i++ ) {
        QStringList data = ui->listPlanificador->item(i)->text().split(" | ");
        QStringList texto = data.at(0).split(", ");

        TipoGalleta * tipo = new TipoGalleta(texto.at(0),texto.at(1).toInt(),texto.at(2).toDouble(),texto.at(3).toInt(),texto.at(4).toInt(),texto.at(5).toDouble());
        int cantidad = data.at(1).toInt();
        Planificacion * planificacion = new Planificacion(tipo, cantidad);
        listP->insertarAlInicio(planificacion);
    }

    //Receta
    mainStruct->receta->cantChocolate = ui->txtCantMezclaReceta->text().toInt();
    mainStruct->receta->cantMezcla = ui->txtCantChocolateReceta->text().toInt();

    //----------Almacen
    mainStruct->almacen->carrito->capacidad = ui->txtCapacidadCar->text().toInt();
    mainStruct->almacen->carrito->duracionTotal = ui->txtDurationCar->text().toDouble();

    //-----------Machines
    mainStruct->arrayMachine->array[0]->min = ui->txtMinMezcladora1->text().toInt();
    mainStruct->arrayMachine->array[0]->max = ui->txtMaxMecladora1->text().toInt();
    mainStruct->arrayMachine->array[0]->duracionSegudos = ui->txtDurationMecladora1->text().toDouble();
    mainStruct->arrayMachine->array[0]->gramosProcesar =  ui->txtCantProcesarMezcladora1->text().toInt();

    mainStruct->arrayMachine->array[1]->min = ui->txtMinMezcladora2->text().toInt();
    mainStruct->arrayMachine->array[1]->max = ui->txtMaxMecladora2->text().toInt();
    mainStruct->arrayMachine->array[1]->duracionSegudos = ui->txttDurationMecladora2->text().toDouble();
    mainStruct->arrayMachine->array[1]->gramosProcesar =  ui->txtCantProcesarMezcladora2->text().toInt();

    mainStruct->arrayMachine->array[2]->min = ui->txtMinChocolatera->text().toInt();
    mainStruct->arrayMachine->array[2]->max = ui->txtMaxChocolatera->text().toInt();
    mainStruct->arrayMachine->array[2]->duracionSegudos = ui->txtDurationChocolatera->text().toDouble();
    mainStruct->arrayMachine->array[2]->gramosProcesar =  ui->txtCantProcesarChocolatera->text().toInt();

    //--------------Ensambladora
    mainStruct->ensambladora->cant = ui->txtCantProcesarAssembler->text().toInt();
    mainStruct->ensambladora->duracionSegundos = ui->txtDurationAssembler->text().toDouble();

        //Bandas
        mainStruct->ensambladora->bandas->array[0]->capacidad = ui->txtMaxBanda1Mezcla->text().toInt();
        mainStruct->ensambladora->bandas->array[1]->capacidad = ui->txtMaxBanda2Chocolate->text().toInt();

    //------------Horno
    mainStruct->horno->cantidadRellenado = ui->txtCantRellenado->text().toInt();
    mainStruct->horno->tiempoHorneado = ui->txtTiempoHorneado->text().toInt();
    mainStruct->horno->tiempoRellenado = ui->txtTiempoRellenado->text().toInt();
    mainStruct->horno->banda->capacidad = ui->txtCapacidadBandaHorno->text().toInt();

        //Bandejas
        mainStruct->horno->bandejas->array[0]->capacidad = ui->txtMaxBandeja->text().toInt();
        mainStruct->horno->bandejas->array[1]->capacidad = ui->txtMaxBandeja_2->text().toInt();
        mainStruct->horno->bandejas->array[2]->capacidad = ui->txtMaxBandeja_3->text().toInt();
        mainStruct->horno->bandejas->array[3]->capacidad = ui->txtMaxBandeja_4->text().toInt();
        mainStruct->horno->bandejas->array[4]->capacidad = ui->txtMaxBandeja_5->text().toInt();
        mainStruct->horno->bandejas->array[5]->capacidad = ui->txtMaxBandeja_6->text().toInt();

    //Inspectores
    mainStruct->inspectores->arrayInspectores->array[0]->capacidad = ui->txtCantInspeccionar1->text().toInt();
    mainStruct->inspectores->arrayInspectores->array[0]->rate = ui->txtProbabilidadInspector1->text().toInt();
    mainStruct->inspectores->arrayInspectores->array[0]->tiempo = ui->txtTiempoInspector1->text().toInt();

    mainStruct->inspectores->arrayInspectores->array[1]->capacidad = ui->txtCantInspeccionar2->text().toInt();
    mainStruct->inspectores->arrayInspectores->array[1]->rate = ui->txtProbabilidadInspector2->text().toInt();
    mainStruct->inspectores->arrayInspectores->array[1]->tiempo = ui->txtTiempoInspector2->text().toInt();

        //Bandas Inspectores
        mainStruct->inspectores->arrayBandas->array[0]->capacidad = ui->txtCapacidadBandaEmpacadora1->text().toInt();
        mainStruct->inspectores->arrayBandas->array[1]->capacidad = ui->txtCapacidadBandaEmpacadora2->text().toInt();

    //empacadora
    mainStruct->empacadora->banda->capacidad = ui->txtCapacidadBandaCalidad_3->text().toInt();

    imprimirDatos();
}

void MainWindow::on_pushButton_clicked()
{
    mainStruct->listaPlanificaciones->calcularProbalidad();
    mainStruct->listaPlanificaciones->imprimir();
}



void MainWindow::on_txtMaxMecladora1_editingFinished()
{
    if(mainStruct->arrayMachine->array[0]->cantNow > ui->txtMaxMecladora1->text().toInt() || ui->txtMaxMecladora1->text().toInt() < mainStruct->arrayMachine->array[0]->min){
        QMessageBox msgBox;
        msgBox.setText("La modificación no se puede realizar");
        msgBox.exec();
        ui->txtMaxMecladora1->setText(QString::number(mainStruct->arrayMachine->array[0]->max));
    }

}


void MainWindow::on_txtMinMezcladora1_editingFinished()
{
 if(ui->txtMinMezcladora1->text().toInt() > mainStruct->arrayMachine->array[0]->max){
        QMessageBox msgBox;
        msgBox.setText("La modificación no se puede realizar");
        msgBox.exec();
        ui->txtMinMezcladora1->setText(QString::number(mainStruct->arrayMachine->array[0]->min));
    }
}


void MainWindow::on_txtCantInspeccionar1_editingFinished()
{
    if(ui->txtCantInspeccionar1->text().toInt() < mainStruct->inspectores->arrayInspectores->array[0]->actualGalletas){
        QMessageBox msgBox;
        msgBox.setText("La modificación no se puede realizar");
        msgBox.exec();
        ui->txtCantInspeccionar1->setText(QString::number(mainStruct->inspectores->arrayInspectores->array[0]->actualGalletas));
    }
}


void MainWindow::on_txtCantInspeccionar2_editingFinished()
{
    if(ui->txtCantInspeccionar2->text().toInt() < mainStruct->inspectores->arrayInspectores->array[1]->actualGalletas){
        QMessageBox msgBox;
        msgBox.setText("La modificación no se puede realizar");
        msgBox.exec();
        ui->txtCantInspeccionar2->setText(QString::number(mainStruct->inspectores->arrayInspectores->array[1]->actualGalletas));
    }
}


void MainWindow::on_txtCantProcesarMezcladora1_editingFinished()
{
    if(ui->txtCantProcesarMezcladora1->text().toInt() > mainStruct->arrayMachine->array[0]->min){
        QMessageBox msgBox;
        msgBox.setText("La cantidad a procesar no puede ser mayor a min");
        msgBox.exec();
        ui->txtCantProcesarMezcladora1->setText(QString::number(mainStruct->arrayMachine->array[0]->gramosProcesar));
    }
}


void MainWindow::on_txtCantProcesarMezcladora2_editingFinished()
{
    if(ui->txtCantProcesarMezcladora2->text().toInt() > mainStruct->arrayMachine->array[1]->min){
        QMessageBox msgBox;
        msgBox.setText("La cantidad a procesar no puede ser mayor a min");
        msgBox.exec();
        ui->txtCantProcesarMezcladora2->setText(QString::number(mainStruct->arrayMachine->array[1]->gramosProcesar));
    }
}


void MainWindow::on_txtCantProcesarChocolatera_editingFinished()
{
    if(ui->txtCantProcesarChocolatera->text().toInt() > mainStruct->arrayMachine->array[2]->min){
        QMessageBox msgBox;
        msgBox.setText("La cantidad a procesar no puede ser mayor a min");
        msgBox.exec();
        ui->txtCantProcesarChocolatera->setText(QString::number(mainStruct->arrayMachine->array[2]->gramosProcesar));
    }
}


void MainWindow::on_txtMaxChocolatera_editingFinished()
{
    if(ui->txtMaxChocolatera->text().toInt() < mainStruct->arrayMachine->array[2]->min){
        QMessageBox msgBox;
        msgBox.setText("No valido");
        msgBox.exec();
        ui->txtMaxChocolatera->setText(QString::number(mainStruct->arrayMachine->array[2]->max));
    }
}


void MainWindow::on_txtMaxBanda2Chocolate_editingFinished()
{
    if(ui->txtMaxBanda2Chocolate->text().toInt() < mainStruct->ensambladora->bandas->array[1]->cantNow){
        QMessageBox msgBox;
        msgBox.setText("No valido");
        msgBox.exec();
        ui->txtMaxBanda2Chocolate->setText(QString::number(mainStruct->ensambladora->bandas->array[1]->capacidad));
    }
}


void MainWindow::on_txtMaxBanda1Mezcla_editingFinished()
{
    if(ui->txtMaxBanda1Mezcla->text().toInt() < mainStruct->ensambladora->bandas->array[0]->cantNow){
        QMessageBox msgBox;
        msgBox.setText("No valido");
        msgBox.exec();
        ui->txtMaxBanda1Mezcla->setText(QString::number(mainStruct->ensambladora->bandas->array[0]->capacidad));
    }
}


void MainWindow::on_txtCapacidadBandaEmpacadora1_editingFinished()
{
    if(ui->txtCapacidadBandaEmpacadora1->text().toInt() < mainStruct->inspectores->arrayBandas->array[0]->cantNow){
        QMessageBox msgBox;
        msgBox.setText("No valido");
        msgBox.exec();
        ui->txtCapacidadBandaEmpacadora1->setText(QString::number(mainStruct->inspectores->arrayBandas->array[0]->capacidad));
    }
}


void MainWindow::on_txtCapacidadBandaEmpacadora2_editingFinished()
{
    if(ui->txtCapacidadBandaEmpacadora2->text().toInt() < mainStruct->inspectores->arrayBandas->array[1]->cantNow){
        QMessageBox msgBox;
        msgBox.setText("No valido");
        msgBox.exec();
        ui->txtCapacidadBandaEmpacadora2->setText(QString::number(mainStruct->inspectores->arrayBandas->array[1]->capacidad));
    }
}


void MainWindow::on_txtCapacidadBandaCalidad_3_editingFinished()
{
    if(ui->txtCapacidadBandaCalidad_3->text().toInt() < mainStruct->empacadora->banda->cantNow){
        QMessageBox msgBox;
        msgBox.setText("No valido");
        msgBox.exec();
        ui->txtCapacidadBandaCalidad_3->setText(QString::number(mainStruct->empacadora->banda->capacidad));
    }
}

