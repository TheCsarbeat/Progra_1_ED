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
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *contentPanel;
    QWidget *factoryPage;
    QFrame *factoryPanel;
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
    QPushButton *btnGotoDatos;
    QWidget *dataPage;
    QFrame *dataPanel;
    QLineEdit *txtCapacidadCar;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *txtDurationCar;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *txtDurationMecladora1;
    QLabel *label_6;
    QLineEdit *txtMinMezcladora1;
    QLineEdit *txtMaxMecladora1;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLineEdit *txtCantProcesarMezcladora1;
    QLineEdit *txtCantProcesarMezcladora2;
    QLabel *label_10;
    QLineEdit *txtMinMezcladora2;
    QLabel *label_11;
    QLabel *label_12;
    QLineEdit *txtMaxMecladora2;
    QLabel *label_13;
    QLabel *label_14;
    QLineEdit *txttDurationMecladora2;
    QLineEdit *txtCantProcesarChocolatera;
    QLabel *label_15;
    QLineEdit *txtMinChocolatera;
    QLabel *label_16;
    QLabel *label_17;
    QLineEdit *txtMaxChocolatera;
    QLabel *label_18;
    QLabel *label_19;
    QLineEdit *txtDurationChocolatera;
    QPushButton *btnGotoSimulacion;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1920, 1080);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        contentPanel = new QStackedWidget(centralwidget);
        contentPanel->setObjectName(QString::fromUtf8("contentPanel"));
        contentPanel->setGeometry(QRect(0, 0, 1920, 1080));
        contentPanel->setStyleSheet(QString::fromUtf8("this->setStyleSheet(\"background-color: rgb(255, 255, 255);\");"));
        factoryPage = new QWidget();
        factoryPage->setObjectName(QString::fromUtf8("factoryPage"));
        factoryPanel = new QFrame(factoryPage);
        factoryPanel->setObjectName(QString::fromUtf8("factoryPanel"));
        factoryPanel->setGeometry(QRect(0, 0, 1731, 951));
        factoryPanel->setFrameShape(QFrame::StyledPanel);
        factoryPanel->setFrameShadow(QFrame::Raised);
        lbMachine1 = new QLabel(factoryPanel);
        lbMachine1->setObjectName(QString::fromUtf8("lbMachine1"));
        lbMachine1->setGeometry(QRect(60, 120, 301, 91));
        lbCarro = new QLabel(factoryPanel);
        lbCarro->setObjectName(QString::fromUtf8("lbCarro"));
        lbCarro->setGeometry(QRect(60, 40, 371, 101));
        lbMachine3 = new QLabel(factoryPanel);
        lbMachine3->setObjectName(QString::fromUtf8("lbMachine3"));
        lbMachine3->setGeometry(QRect(50, 410, 421, 71));
        lbMachine2 = new QLabel(factoryPanel);
        lbMachine2->setObjectName(QString::fromUtf8("lbMachine2"));
        lbMachine2->setGeometry(QRect(60, 280, 341, 71));
        btnIniciar = new QPushButton(factoryPanel);
        btnIniciar->setObjectName(QString::fromUtf8("btnIniciar"));
        btnIniciar->setGeometry(QRect(650, 350, 75, 23));
        lineEdit = new QLineEdit(factoryPanel);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(340, 230, 113, 20));
        lbCola = new QLabel(factoryPanel);
        lbCola->setObjectName(QString::fromUtf8("lbCola"));
        lbCola->setGeometry(QRect(470, 40, 311, 251));
        lbDatosMachine2 = new QLabel(factoryPanel);
        lbDatosMachine2->setObjectName(QString::fromUtf8("lbDatosMachine2"));
        lbDatosMachine2->setGeometry(QRect(60, 340, 311, 81));
        lbDatosMachine1 = new QLabel(factoryPanel);
        lbDatosMachine1->setObjectName(QString::fromUtf8("lbDatosMachine1"));
        lbDatosMachine1->setGeometry(QRect(60, 200, 311, 81));
        lbDatosMachine3 = new QLabel(factoryPanel);
        lbDatosMachine3->setObjectName(QString::fromUtf8("lbDatosMachine3"));
        lbDatosMachine3->setGeometry(QRect(60, 470, 311, 81));
        btnGotoDatos = new QPushButton(factoryPanel);
        btnGotoDatos->setObjectName(QString::fromUtf8("btnGotoDatos"));
        btnGotoDatos->setGeometry(QRect(1570, 210, 75, 23));
        contentPanel->addWidget(factoryPage);
        dataPage = new QWidget();
        dataPage->setObjectName(QString::fromUtf8("dataPage"));
        dataPanel = new QFrame(dataPage);
        dataPanel->setObjectName(QString::fromUtf8("dataPanel"));
        dataPanel->setGeometry(QRect(0, 0, 1921, 1061));
        dataPanel->setFrameShape(QFrame::StyledPanel);
        dataPanel->setFrameShadow(QFrame::Raised);
        txtCapacidadCar = new QLineEdit(dataPanel);
        txtCapacidadCar->setObjectName(QString::fromUtf8("txtCapacidadCar"));
        txtCapacidadCar->setGeometry(QRect(120, 60, 191, 21));
        QFont font;
        font.setFamilies({QString::fromUtf8("Roboto")});
        font.setPointSize(12);
        txtCapacidadCar->setFont(font);
        label = new QLabel(dataPanel);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 10, 161, 31));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Roboto")});
        font1.setPointSize(16);
        label->setFont(font1);
        label_2 = new QLabel(dataPanel);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 60, 91, 31));
        label_2->setFont(font);
        txtDurationCar = new QLineEdit(dataPanel);
        txtDurationCar->setObjectName(QString::fromUtf8("txtDurationCar"));
        txtDurationCar->setGeometry(QRect(120, 120, 191, 21));
        txtDurationCar->setFont(font);
        label_4 = new QLabel(dataPanel);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 120, 91, 31));
        label_4->setFont(font);
        label_5 = new QLabel(dataPanel);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(350, 110, 91, 31));
        label_5->setFont(font);
        txtDurationMecladora1 = new QLineEdit(dataPanel);
        txtDurationMecladora1->setObjectName(QString::fromUtf8("txtDurationMecladora1"));
        txtDurationMecladora1->setGeometry(QRect(460, 110, 191, 21));
        txtDurationMecladora1->setFont(font);
        label_6 = new QLabel(dataPanel);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(350, 80, 91, 31));
        label_6->setFont(font);
        txtMinMezcladora1 = new QLineEdit(dataPanel);
        txtMinMezcladora1->setObjectName(QString::fromUtf8("txtMinMezcladora1"));
        txtMinMezcladora1->setGeometry(QRect(460, 50, 191, 21));
        txtMinMezcladora1->setFont(font);
        txtMaxMecladora1 = new QLineEdit(dataPanel);
        txtMaxMecladora1->setObjectName(QString::fromUtf8("txtMaxMecladora1"));
        txtMaxMecladora1->setGeometry(QRect(460, 80, 191, 21));
        txtMaxMecladora1->setFont(font);
        label_7 = new QLabel(dataPanel);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(350, 50, 91, 31));
        label_7->setFont(font);
        label_8 = new QLabel(dataPanel);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(350, 10, 221, 31));
        label_8->setFont(font1);
        label_9 = new QLabel(dataPanel);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(350, 140, 101, 31));
        label_9->setFont(font);
        txtCantProcesarMezcladora1 = new QLineEdit(dataPanel);
        txtCantProcesarMezcladora1->setObjectName(QString::fromUtf8("txtCantProcesarMezcladora1"));
        txtCantProcesarMezcladora1->setGeometry(QRect(460, 140, 191, 21));
        txtCantProcesarMezcladora1->setFont(font);
        txtCantProcesarMezcladora2 = new QLineEdit(dataPanel);
        txtCantProcesarMezcladora2->setObjectName(QString::fromUtf8("txtCantProcesarMezcladora2"));
        txtCantProcesarMezcladora2->setGeometry(QRect(780, 140, 191, 21));
        txtCantProcesarMezcladora2->setFont(font);
        label_10 = new QLabel(dataPanel);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(670, 140, 101, 31));
        label_10->setFont(font);
        txtMinMezcladora2 = new QLineEdit(dataPanel);
        txtMinMezcladora2->setObjectName(QString::fromUtf8("txtMinMezcladora2"));
        txtMinMezcladora2->setGeometry(QRect(780, 50, 191, 21));
        txtMinMezcladora2->setFont(font);
        label_11 = new QLabel(dataPanel);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(670, 80, 91, 31));
        label_11->setFont(font);
        label_12 = new QLabel(dataPanel);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(670, 110, 91, 31));
        label_12->setFont(font);
        txtMaxMecladora2 = new QLineEdit(dataPanel);
        txtMaxMecladora2->setObjectName(QString::fromUtf8("txtMaxMecladora2"));
        txtMaxMecladora2->setGeometry(QRect(780, 80, 191, 21));
        txtMaxMecladora2->setFont(font);
        label_13 = new QLabel(dataPanel);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(670, 50, 91, 31));
        label_13->setFont(font);
        label_14 = new QLabel(dataPanel);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(670, 10, 221, 31));
        label_14->setFont(font1);
        txttDurationMecladora2 = new QLineEdit(dataPanel);
        txttDurationMecladora2->setObjectName(QString::fromUtf8("txttDurationMecladora2"));
        txttDurationMecladora2->setGeometry(QRect(780, 110, 191, 21));
        txttDurationMecladora2->setFont(font);
        txtCantProcesarChocolatera = new QLineEdit(dataPanel);
        txtCantProcesarChocolatera->setObjectName(QString::fromUtf8("txtCantProcesarChocolatera"));
        txtCantProcesarChocolatera->setGeometry(QRect(1100, 140, 191, 21));
        txtCantProcesarChocolatera->setFont(font);
        label_15 = new QLabel(dataPanel);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(990, 140, 101, 31));
        label_15->setFont(font);
        txtMinChocolatera = new QLineEdit(dataPanel);
        txtMinChocolatera->setObjectName(QString::fromUtf8("txtMinChocolatera"));
        txtMinChocolatera->setGeometry(QRect(1100, 50, 191, 21));
        txtMinChocolatera->setFont(font);
        label_16 = new QLabel(dataPanel);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(990, 80, 91, 31));
        label_16->setFont(font);
        label_17 = new QLabel(dataPanel);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(990, 110, 91, 31));
        label_17->setFont(font);
        txtMaxChocolatera = new QLineEdit(dataPanel);
        txtMaxChocolatera->setObjectName(QString::fromUtf8("txtMaxChocolatera"));
        txtMaxChocolatera->setGeometry(QRect(1100, 80, 191, 21));
        txtMaxChocolatera->setFont(font);
        label_18 = new QLabel(dataPanel);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(990, 50, 91, 31));
        label_18->setFont(font);
        label_19 = new QLabel(dataPanel);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(990, 10, 221, 31));
        label_19->setFont(font1);
        txtDurationChocolatera = new QLineEdit(dataPanel);
        txtDurationChocolatera->setObjectName(QString::fromUtf8("txtDurationChocolatera"));
        txtDurationChocolatera->setGeometry(QRect(1100, 110, 191, 21));
        txtDurationChocolatera->setFont(font);
        btnGotoSimulacion = new QPushButton(dataPanel);
        btnGotoSimulacion->setObjectName(QString::fromUtf8("btnGotoSimulacion"));
        btnGotoSimulacion->setGeometry(QRect(1080, 210, 75, 23));
        contentPanel->addWidget(dataPage);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1920, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        contentPanel->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        lbMachine1->setText(QCoreApplication::translate("MainWindow", "Mezcladora 1", nullptr));
        lbCarro->setText(QCoreApplication::translate("MainWindow", "Carro", nullptr));
        lbMachine3->setText(QCoreApplication::translate("MainWindow", "Chocolatera", nullptr));
        lbMachine2->setText(QCoreApplication::translate("MainWindow", "Mezcladora 2", nullptr));
        btnIniciar->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        lbCola->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        lbDatosMachine2->setText(QCoreApplication::translate("MainWindow", "datos", nullptr));
        lbDatosMachine1->setText(QCoreApplication::translate("MainWindow", "datos", nullptr));
        lbDatosMachine3->setText(QCoreApplication::translate("MainWindow", "datos", nullptr));
        btnGotoDatos->setText(QCoreApplication::translate("MainWindow", "Datos", nullptr));
        txtCapacidadCar->setText(QCoreApplication::translate("MainWindow", "10", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Datos Del Carrito", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Capacidad:", nullptr));
        txtDurationCar->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Duraci\303\263n:", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Duraci\303\263n:", nullptr));
        txtDurationMecladora1->setText(QCoreApplication::translate("MainWindow", "15", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "M\303\241ximo:", nullptr));
        txtMinMezcladora1->setText(QCoreApplication::translate("MainWindow", "20", nullptr));
        txtMaxMecladora1->setText(QCoreApplication::translate("MainWindow", "45", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "M\303\255nimo: ", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Datos Mezcladora 1", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Cant Procesar", nullptr));
        txtCantProcesarMezcladora1->setText(QCoreApplication::translate("MainWindow", "10", nullptr));
        txtCantProcesarMezcladora2->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Cant Procesar", nullptr));
        txtMinMezcladora2->setText(QCoreApplication::translate("MainWindow", "20", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "M\303\241ximo:", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Duraci\303\263n:", nullptr));
        txtMaxMecladora2->setText(QCoreApplication::translate("MainWindow", "50", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "M\303\255nimo: ", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Datos Mezcladora 2", nullptr));
        txttDurationMecladora2->setText(QCoreApplication::translate("MainWindow", "10", nullptr));
        txtCantProcesarChocolatera->setText(QCoreApplication::translate("MainWindow", "20", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "Cant Procesar", nullptr));
        txtMinChocolatera->setText(QCoreApplication::translate("MainWindow", "50", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "M\303\241ximo:", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "Duraci\303\263n:", nullptr));
        txtMaxChocolatera->setText(QCoreApplication::translate("MainWindow", "60", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "M\303\255nimo: ", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "Datos Chocolatera", nullptr));
        txtDurationChocolatera->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        btnGotoSimulacion->setText(QCoreApplication::translate("MainWindow", "Ir a Simulacion", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
