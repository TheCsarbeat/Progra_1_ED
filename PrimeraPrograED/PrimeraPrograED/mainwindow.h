#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPalette>
#include "qpalette.h"
#include <QDebug>
#include <QString>

#include "main_thread.h"
#include "main_struct.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

     thread_main * mainThread;
     MainStruct * mainStruct;

    ~MainWindow();

     void design();
     MainStruct * cargarDatos();

private slots:
    void on_btnIniciar_clicked();

    void on_btnGotoSimulacion_clicked();

    void on_btnGotoDatos_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
