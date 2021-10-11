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
    QLabel *lbRegistroMezcla0;
    QLabel *lbRegistroMezcla;
    QLabel *lbRegistroChoco0;
    QLabel *lbRegistroChoco;
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
        panelMain->setGeometry(QRect(0, 0, 801, 571));
        panelMain->setFrameShape(QFrame::StyledPanel);
        panelMain->setFrameShadow(QFrame::Raised);
        lbMachine1 = new QLabel(panelMain);
        lbMachine1->setObjectName(QString::fromUtf8("lbMachine1"));
        lbMachine1->setGeometry(QRect(60, 180, 301, 91));
        lbCarro = new QLabel(panelMain);
        lbCarro->setObjectName(QString::fromUtf8("lbCarro"));
        lbCarro->setGeometry(QRect(60, 40, 371, 101));
        lbMachine3 = new QLabel(panelMain);
        lbMachine3->setObjectName(QString::fromUtf8("lbMachine3"));
        lbMachine3->setGeometry(QRect(60, 360, 421, 71));
        lbMachine2 = new QLabel(panelMain);
        lbMachine2->setObjectName(QString::fromUtf8("lbMachine2"));
        lbMachine2->setGeometry(QRect(60, 280, 341, 71));
        btnIniciar = new QPushButton(panelMain);
        btnIniciar->setObjectName(QString::fromUtf8("btnIniciar"));
        btnIniciar->setGeometry(QRect(650, 350, 75, 23));
        lineEdit = new QLineEdit(panelMain);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(400, 390, 113, 20));
        lbCola = new QLabel(panelMain);
        lbCola->setObjectName(QString::fromUtf8("lbCola"));
        lbCola->setGeometry(QRect(470, 40, 311, 251));
        lbRegistroMezcla0 = new QLabel(panelMain);
        lbRegistroMezcla0->setObjectName(QString::fromUtf8("lbRegistroMezcla0"));
        lbRegistroMezcla0->setGeometry(QRect(60, 500, 71, 31));
        lbRegistroMezcla = new QLabel(panelMain);
        lbRegistroMezcla->setObjectName(QString::fromUtf8("lbRegistroMezcla"));
        lbRegistroMezcla->setGeometry(QRect(130, 500, 81, 31));
        lbRegistroChoco0 = new QLabel(panelMain);
        lbRegistroChoco0->setObjectName(QString::fromUtf8("lbRegistroChoco0"));
        lbRegistroChoco0->setGeometry(QRect(260, 500, 91, 31));
        lbRegistroChoco = new QLabel(panelMain);
        lbRegistroChoco->setObjectName(QString::fromUtf8("lbRegistroChoco"));
        lbRegistroChoco->setGeometry(QRect(350, 500, 61, 31));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 20));
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
        lbMachine1->setText(QCoreApplication::translate("MainWindow", "Carro", nullptr));
        lbCarro->setText(QCoreApplication::translate("MainWindow", "Carro", nullptr));
        lbMachine3->setText(QCoreApplication::translate("MainWindow", "Carro", nullptr));
        lbMachine2->setText(QCoreApplication::translate("MainWindow", "Carro", nullptr));
        btnIniciar->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        lbCola->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        lbRegistroMezcla0->setText(QCoreApplication::translate("MainWindow", "Total Mezcla: ", nullptr));
        lbRegistroMezcla->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        lbRegistroChoco0->setText(QCoreApplication::translate("MainWindow", "Total Chocolate: ", nullptr));
        lbRegistroChoco->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
