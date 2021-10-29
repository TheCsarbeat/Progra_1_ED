#include "mainwindow.h"

#include <QApplication>
#include <QDebug>
#include <QtCore>
class OperationThread: public QThread{
public:
    int id;
    int * value;
    int sleepTime;
    QMutex * mutex;

    void __init__(int id, int *value, int sleepTime, QMutex *mutex){
        this->id = id;
        this->value = value;
        this->sleepTime = sleepTime;
        this->mutex = mutex;
    }
    void run(){
        mutex->lock();
        *this->value *= 10;
        qDebug()<<"Hilo: "<<this->id<<"El valor es de "<<*this->value;
        sleep(this->sleepTime);
        *this->value += 4;
        qDebug()<<"Hilo: "<<this->id<<"El valor es de "<<*this->value;
        mutex->unlock();
    }
};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    int variable = 4;
    qDebug()<<"Hola mundo";
    QMutex mutex;
    OperationThread *hilo1 = new OperationThread();
    hilo1->__init__(1, &variable,5, &mutex);
    hilo1->start();

    OperationThread *hilo2 = new OperationThread();
    hilo2->__init__(2, &variable,1, &mutex);
    hilo2->start();

    return a.exec();
}
