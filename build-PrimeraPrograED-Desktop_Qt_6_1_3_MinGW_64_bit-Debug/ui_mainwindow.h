/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QFrame *panelMain;
    QLabel *lbMachine1;
    QLabel *lbCarro;
    QLabel *lbMachine3;
    QLabel *lbMachine2;
    QPushButton *btnIniciar;
    QLineEdit *lineEdit;
    QLabel *lbCola;
    QLabel *lbDatosMachine2;
    QLabel *lbDatosMachine1;
    QLabel *lbDatosMachine3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        panelMain = new QFrame(centralwidget);
        panelMain->setObjectName(QString::fromUtf8("panelMain"));
        panelMain->setGeometry(QRect(0, -10, 801, 571));
        panelMain->setFrameShape(QFrame::StyledPanel);
        panelMain->setFrameShadow(QFrame::Raised);
        lbMachine1 = new QLabel(panelMain);
        lbMachine1->setObjectName(QString::fromUtf8("lbMachine1"));
        lbMachine1->setGeometry(QRect(60, 120, 301, 91));
        lbCarro = new QLabel(panelMain);
        lbCarro->setObjectName(QString::fromUtf8("lbCarro"));
        lbCarro->setGeometry(QRect(60, 40, 371, 101));
        lbMachine3 = new QLabel(panelMain);
        lbMachine3->setObjectName(QString::fromUtf8("lbMachine3"));
        lbMachine3->setGeometry(QRect(50, 410, 421, 71));
        lbMachine2 = new QLabel(panelMain);
        lbMachine2->setObjectName(QString::fromUtf8("lbMachine2"));
        lbMachine2->setGeometry(QRect(60, 280, 341, 71));
        btnIniciar = new QPushButton(panelMain);
        btnIniciar->setObjectName(QString::fromUtf8("btnIniciar"));
        btnIniciar->setGeometry(QRect(650, 350, 75, 23));
        lineEdit = new QLineEdit(panelMain);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(370, 490, 113, 20));
        lbCola = new QLabel(panelMain);
        lbCola->setObjectName(QString::fromUtf8("lbCola"));
        lbCola->setGeometry(QRect(470, 40, 311, 251));
        lbDatosMachine2 = new QLabel(panelMain);
        lbDatosMachine2->setObjectName(QString::fromUtf8("lbDatosMachine2"));
        lbDatosMachine2->setGeometry(QRect(60, 340, 311, 81));
        lbDatosMachine1 = new QLabel(panelMain);
        lbDatosMachine1->setObjectName(QString::fromUtf8("lbDatosMachine1"));
        lbDatosMachine1->setGeometry(QRect(60, 200, 311, 81));
        lbDatosMachine3 = new QLabel(panelMain);
        lbDatosMachine3->setObjectName(QString::fromUtf8("lbDatosMachine3"));
        lbDatosMachine3->setGeometry(QRect(60, 470, 311, 81));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        lbMachine1->setText(QCoreApplication::translate("MainWindow", "Mezcladora 1", nullptr));
        lbCarro->setText(QCoreApplication::translate("MainWindow", "Carro", nullptr));
        lbMachine3->setText(QCoreApplication::translate("MainWindow", "Chocolatera", nullptr));
        lbMachine2->setText(QCoreApplication::translate("MainWindow", "Mezcladora 2", nullptr));
        btnIniciar->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        lbCola->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        lbDatosMachine2->setText(QCoreApplication::translate("MainWindow", "datos", nullptr));
        lbDatosMachine1->setText(QCoreApplication::translate("MainWindow", "datos", nullptr));
        lbDatosMachine3->setText(QCoreApplication::translate("MainWindow", "datos", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
