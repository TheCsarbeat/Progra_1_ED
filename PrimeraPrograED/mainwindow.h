#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPalette>
#include <QMessageBox>
#include "qpalette.h"
#include <QDebug>
#include <QString>
#include <QListWidgetItem>
#include "main_thread.h"
#include "main_struct.h"

#include "estructuras_progressbar.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

     thread_main * mainThread;
     MainStruct * mainStruct = new MainStruct();

     ListaCircular * listC = new ListaCircular();
     ListaSimplePlanificaciones *listP = new ListaSimplePlanificaciones();

     QLabel * arrayLbMachines[3];
     QLabel * arrayLbDatosMachines[3];
     QLabel * arrayLbDatosBandejas[6];
     QCheckBox * arrayCheckBoxHornoBandejas[6];

     EstructuraProgressBar * arrayProgressBar[40];
     QCheckBox * arrayCheackBoxOnOff[40];
     QCheckBox * arrayCheckBoxHorno[5];


    ~MainWindow();

     void design();
    void getUIWidgets();
    void cargarDatos();
    void imprimirDatos();
    void loadDataOnPaused();

private slots:
     //Inicio-Parado-Pausado-Play
     void on_btnOnOff_clicked();
     void on_btnPausedPlay_clicked();

     //Navegacion
     void on_btnGoToDatos_clicked();
     void on_btnGoToSimulation_clicked();

     //Planificacion
     void on_btnAgregarTipoGalleta_clicked();
     void on_btnEliminarTipoGalleta_clicked();
     void on_listTiposGalletas_itemClicked(QListWidgetItem *item);

     void on_btnAgregarPlanificacion_clicked();
     void on_btnEliminarPlanificacion_clicked();
     void on_listPlanificador_itemClicked(QListWidgetItem *item);

     void on_pushButton_clicked();

     void on_txtMaxMecladora1_editingFinished();

     void on_txtMinMezcladora1_editingFinished();

     void on_txtCantInspeccionar1_editingFinished();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
