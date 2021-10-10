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
    QLabel *lbMezcladora1;
    QLabel *lbCarro;
    QLabel *lbMezcladora3;
    QLabel *lbMezcladora2;
    QPushButton *btnIniciar;
    QLineEdit *lineEdit;
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
        panelMain->setGeometry(QRect(0, 0, 791, 561));
        panelMain->setFrameShape(QFrame::StyledPanel);
        panelMain->setFrameShadow(QFrame::Raised);
        lbMezcladora1 = new QLabel(panelMain);
        lbMezcladora1->setObjectName(QString::fromUtf8("lbMezcladora1"));
        lbMezcladora1->setGeometry(QRect(250, 50, 71, 51));
        lbCarro = new QLabel(panelMain);
        lbCarro->setObjectName(QString::fromUtf8("lbCarro"));
        lbCarro->setGeometry(QRect(250, 220, 271, 51));
        lbMezcladora3 = new QLabel(panelMain);
        lbMezcladora3->setObjectName(QString::fromUtf8("lbMezcladora3"));
        lbMezcladora3->setGeometry(QRect(580, 50, 71, 51));
        lbMezcladora2 = new QLabel(panelMain);
        lbMezcladora2->setObjectName(QString::fromUtf8("lbMezcladora2"));
        lbMezcladora2->setGeometry(QRect(100, 80, 71, 51));
        btnIniciar = new QPushButton(panelMain);
        btnIniciar->setObjectName(QString::fromUtf8("btnIniciar"));
        btnIniciar->setGeometry(QRect(430, 100, 75, 23));
        lineEdit = new QLineEdit(panelMain);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(460, 200, 113, 20));
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
        lbMezcladora1->setText(QCoreApplication::translate("MainWindow", "Carro", nullptr));
        lbCarro->setText(QCoreApplication::translate("MainWindow", "Carro", nullptr));
        lbMezcladora3->setText(QCoreApplication::translate("MainWindow", "Carro", nullptr));
        lbMezcladora2->setText(QCoreApplication::translate("MainWindow", "Carro", nullptr));
        btnIniciar->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
