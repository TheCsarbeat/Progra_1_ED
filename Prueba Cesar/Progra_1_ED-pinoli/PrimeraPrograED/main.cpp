#include "mainwindow.h"
#include "main_struct.h"
#include "main_thread.h"
#include <QApplication>

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    MainWindow w;
    w.show();


    return a.exec();
}
