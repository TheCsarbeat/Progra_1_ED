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

     //Variables de interfaz gráfica
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


    thread_main * mainThread = new thread_main();
    mainThread->__init__(mainStruct, getMainWindow());

    QObject::connect(mainThread, SIGNAL(enviarTexto(QString)), this, SLOT(setLabel(QString)));

    mainThread->start();
}

QMainWindow* MainWindow::getMainWindow(){
    foreach (QWidget *w, qApp->topLevelWidgets())
            if (QMainWindow* mainWin = qobject_cast<QMainWindow*>(w))
                return mainWin;
        return nullptr;
}

void MainWindow::setLabel(const QString &name){
    ui->lineEdit->setText(name);
}

