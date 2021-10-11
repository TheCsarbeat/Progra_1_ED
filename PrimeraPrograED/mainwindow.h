#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


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
    Ui::MainWindow *ui;

     thread_main * mainThread;
     Main_Struct * mainStruct;

    ~MainWindow();

private slots:
    void on_btnIniciar_clicked();
    QMainWindow* getMainWindow();

public slots:
    void setLabel(const QString &name);

};
#endif // MAINWINDOW_H
