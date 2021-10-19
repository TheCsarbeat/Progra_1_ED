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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
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
    QPushButton *btnGotoDatos;
    QFrame *frameTop;
    QFrame *frame;
    QLabel *iconCar;
    QCheckBox *checkBoxCar;
    QLabel *lbCarro;
    QFrame *panelProgressCar;
    QFrame *barCar;
    QFrame *progressCar;
    QLabel *lbProgressCar;
    QLabel *lbDatosCar;
    QFrame *frame_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaContents;
    QLabel *lbCola;
    QFrame *frame_6;
    QFrame *frame_3;
    QLabel *iconMachine1;
    QLabel *lbMachine1;
    QLabel *lbDatosMachine1;
    QCheckBox *checkBoxMachine1;
    QFrame *panelProgress2;
    QFrame *barMachine1;
    QFrame *progressMachine1;
    QLabel *lbProgressMachine1;
    QFrame *frame_4;
    QLabel *iconMachine2;
    QLabel *lbMachine2;
    QLabel *lbDatosMachine2;
    QCheckBox *checkBoxMachine2;
    QFrame *panelProgress3;
    QFrame *barMachine2;
    QFrame *progressMachine2;
    QLabel *lbProgressMachine2;
    QFrame *frame_5;
    QLabel *iconMachine3;
    QLabel *lbMachine3;
    QLabel *lbDatosMachine3;
    QCheckBox *checkBoxMachine3;
    QFrame *panelProgress4;
    QFrame *barMachine3;
    QFrame *progressMachine3;
    QLabel *lbProgressMachine3;
    QFrame *frame_7;
    QFrame *frame_8;
    QLabel *iconBanda1Mazcla;
    QLabel *lbNameBanda1Mezcla;
    QLabel *lbDatosBanda1Mezcla;
    QFrame *frame_9;
    QLabel *iconBanda2Chocolate;
    QLabel *lbNameBanda2Chocolate;
    QLabel *lbDatosBanda2Chocolate;
    QFrame *frame_10;
    QLabel *iconAssembler;
    QLabel *lbNameAssembler;
    QLabel *lbDatosAssembler;
    QCheckBox *checkBoxAssembler;
    QFrame *panelProgress3_3;
    QFrame *barAssembler;
    QFrame *progressAssembler;
    QLabel *lbProgressAssembler;
    QPushButton *btnIniciar;
    QWidget *dataPage;
    QFrame *dataPanel;
    QFrame *frame_12;
    QLabel *label_4;
    QLineEdit *txtDurationCar;
    QLineEdit *txtCapacidadCar;
    QLabel *label_2;
    QLabel *label;
    QFrame *frame_13;
    QLabel *label_8;
    QLineEdit *txtCantProcesarMezcladora1;
    QLabel *label_9;
    QLineEdit *txtMaxMecladora1;
    QLineEdit *txtDurationMecladora1;
    QLabel *label_7;
    QLineEdit *txtMinMezcladora1;
    QLabel *label_6;
    QLabel *label_5;
    QFrame *frame_14;
    QLabel *label_14;
    QLineEdit *txtMaxMecladora2;
    QLabel *label_12;
    QLabel *label_11;
    QLabel *label_10;
    QLineEdit *txtCantProcesarMezcladora2;
    QLabel *label_13;
    QLineEdit *txtMinMezcladora2;
    QLineEdit *txttDurationMecladora2;
    QFrame *frame_15;
    QLabel *label_19;
    QLineEdit *txtMinChocolatera;
    QLabel *label_15;
    QLineEdit *txtDurationChocolatera;
    QLabel *label_18;
    QLineEdit *txtCantProcesarChocolatera;
    QLabel *label_16;
    QLabel *label_17;
    QLineEdit *txtMaxChocolatera;
    QFrame *frame_11;
    QLabel *label_20;
    QLabel *label_22;
    QFrame *frame_16;
    QLabel *label_21;
    QLineEdit *txtMaxBanda2Chocolate;
    QLabel *label_23;
    QLabel *label_24;
    QLabel *label_25;
    QLineEdit *txtCantProcesarAssembler;
    QLabel *label_26;
    QLineEdit *txtMaxBanda1Mezcla;
    QLineEdit *txtDurationAssembler;
    QLabel *label_27;
    QLabel *label_28;
    QPushButton *btnGoToSimulation;
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
        contentPanel->setGeometry(QRect(0, -1, 1920, 1080));
        contentPanel->setStyleSheet(QString::fromUtf8("this->setStyleSheet(\"background-color: rgb(255, 255, 255);\");"));
        factoryPage = new QWidget();
        factoryPage->setObjectName(QString::fromUtf8("factoryPage"));
        factoryPage->setStyleSheet(QString::fromUtf8(""));
        factoryPanel = new QFrame(factoryPage);
        factoryPanel->setObjectName(QString::fromUtf8("factoryPanel"));
        factoryPanel->setGeometry(QRect(-10, 0, 1931, 851));
        factoryPanel->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 255, 255);"));
        factoryPanel->setFrameShape(QFrame::StyledPanel);
        factoryPanel->setFrameShadow(QFrame::Raised);
        btnGotoDatos = new QPushButton(factoryPanel);
        btnGotoDatos->setObjectName(QString::fromUtf8("btnGotoDatos"));
        btnGotoDatos->setGeometry(QRect(1570, 210, 75, 23));
        frameTop = new QFrame(factoryPanel);
        frameTop->setObjectName(QString::fromUtf8("frameTop"));
        frameTop->setGeometry(QRect(10, 0, 1921, 31));
        frameTop->setStyleSheet(QString::fromUtf8("background-color:rgb(97, 197, 161);"));
        frameTop->setFrameShape(QFrame::StyledPanel);
        frameTop->setFrameShadow(QFrame::Raised);
        frame = new QFrame(factoryPanel);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(90, 50, 250, 120));
        frame->setStyleSheet(QString::fromUtf8("background-color:rgb(254, 188, 187);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        iconCar = new QLabel(frame);
        iconCar->setObjectName(QString::fromUtf8("iconCar"));
        iconCar->setGeometry(QRect(160, 50, 81, 61));
        iconCar->setStyleSheet(QString::fromUtf8("image:url(\":/images/vehicle.png\");\n"
""));
        checkBoxCar = new QCheckBox(frame);
        checkBoxCar->setObjectName(QString::fromUtf8("checkBoxCar"));
        checkBoxCar->setGeometry(QRect(190, 10, 41, 31));
        checkBoxCar->setStyleSheet(QString::fromUtf8("QCheckBox::indicator{\n"
"	width: 40px;\n"
"	height:40px;\n"
"}\n"
"\n"
"QCheckBox::indicator:checked{\n"
"	image:url(\":/images/switch-on.png\");\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked{\n"
"	image:url(\":/images/switch-off.png\");\n"
"}"));
        checkBoxCar->setChecked(true);
        lbCarro = new QLabel(frame);
        lbCarro->setObjectName(QString::fromUtf8("lbCarro"));
        lbCarro->setGeometry(QRect(10, 10, 161, 31));
        QFont font;
        font.setFamilies({QString::fromUtf8("Open Sans")});
        font.setPointSize(10);
        font.setBold(true);
        lbCarro->setFont(font);
        panelProgressCar = new QFrame(frame);
        panelProgressCar->setObjectName(QString::fromUtf8("panelProgressCar"));
        panelProgressCar->setGeometry(QRect(10, 90, 150, 20));
        panelProgressCar->setFrameShape(QFrame::StyledPanel);
        panelProgressCar->setFrameShadow(QFrame::Raised);
        barCar = new QFrame(panelProgressCar);
        barCar->setObjectName(QString::fromUtf8("barCar"));
        barCar->setGeometry(QRect(0, 0, 100, 20));
        barCar->setStyleSheet(QString::fromUtf8("background-color:rgb(230, 230, 230);"));
        barCar->setFrameShape(QFrame::StyledPanel);
        barCar->setFrameShadow(QFrame::Raised);
        progressCar = new QFrame(barCar);
        progressCar->setObjectName(QString::fromUtf8("progressCar"));
        progressCar->setGeometry(QRect(0, 0, 81, 20));
        progressCar->setStyleSheet(QString::fromUtf8("background-color:rgb(46, 194, 67);"));
        progressCar->setFrameShape(QFrame::StyledPanel);
        progressCar->setFrameShadow(QFrame::Raised);
        lbProgressCar = new QLabel(panelProgressCar);
        lbProgressCar->setObjectName(QString::fromUtf8("lbProgressCar"));
        lbProgressCar->setGeometry(QRect(110, 0, 21, 20));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Open Sans Light")});
        font1.setPointSize(7);
        font1.setBold(false);
        lbProgressCar->setFont(font1);
        lbDatosCar = new QLabel(frame);
        lbDatosCar->setObjectName(QString::fromUtf8("lbDatosCar"));
        lbDatosCar->setGeometry(QRect(10, 50, 151, 20));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Open Sans")});
        font2.setPointSize(10);
        lbDatosCar->setFont(font2);
        frame_2 = new QFrame(factoryPanel);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(90, 230, 250, 471));
        frame_2->setStyleSheet(QString::fromUtf8("background-color:rgb(254, 188, 187);"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        scrollArea = new QScrollArea(frame_2);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(0, 0, 250, 451));
        scrollArea->setWidgetResizable(true);
        scrollAreaContents = new QWidget();
        scrollAreaContents->setObjectName(QString::fromUtf8("scrollAreaContents"));
        scrollAreaContents->setGeometry(QRect(0, 0, 248, 449));
        lbCola = new QLabel(scrollAreaContents);
        lbCola->setObjectName(QString::fromUtf8("lbCola"));
        lbCola->setGeometry(QRect(0, 0, 250, 441));
        lbCola->setFont(font);
        scrollArea->setWidget(scrollAreaContents);
        frame_6 = new QFrame(factoryPanel);
        frame_6->setObjectName(QString::fromUtf8("frame_6"));
        frame_6->setGeometry(QRect(410, 50, 270, 501));
        frame_6->setFrameShape(QFrame::StyledPanel);
        frame_6->setFrameShadow(QFrame::Raised);
        frame_3 = new QFrame(frame_6);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setGeometry(QRect(0, 0, 270, 150));
        frame_3->setStyleSheet(QString::fromUtf8("background-color:rgb(167, 235, 248);"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        iconMachine1 = new QLabel(frame_3);
        iconMachine1->setObjectName(QString::fromUtf8("iconMachine1"));
        iconMachine1->setGeometry(QRect(180, 50, 71, 71));
        iconMachine1->setStyleSheet(QString::fromUtf8("image:url(\":/images/batidora.png\");\n"
""));
        lbMachine1 = new QLabel(frame_3);
        lbMachine1->setObjectName(QString::fromUtf8("lbMachine1"));
        lbMachine1->setGeometry(QRect(10, 10, 150, 31));
        lbMachine1->setFont(font);
        lbDatosMachine1 = new QLabel(frame_3);
        lbDatosMachine1->setObjectName(QString::fromUtf8("lbDatosMachine1"));
        lbDatosMachine1->setGeometry(QRect(10, 75, 150, 71));
        lbDatosMachine1->setFont(font2);
        checkBoxMachine1 = new QCheckBox(frame_3);
        checkBoxMachine1->setObjectName(QString::fromUtf8("checkBoxMachine1"));
        checkBoxMachine1->setGeometry(QRect(200, 0, 51, 51));
        checkBoxMachine1->setStyleSheet(QString::fromUtf8("QCheckBox::indicator{\n"
"	width: 40px;\n"
"	height:40px;\n"
"}\n"
"\n"
"QCheckBox::indicator:checked{\n"
"	image:url(\":/images/switch-on.png\");\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked{\n"
"	image:url(\":/images/switch-off.png\");\n"
"}"));
        checkBoxMachine1->setChecked(true);
        panelProgress2 = new QFrame(frame_3);
        panelProgress2->setObjectName(QString::fromUtf8("panelProgress2"));
        panelProgress2->setGeometry(QRect(10, 50, 150, 20));
        panelProgress2->setFrameShape(QFrame::StyledPanel);
        panelProgress2->setFrameShadow(QFrame::Raised);
        barMachine1 = new QFrame(panelProgress2);
        barMachine1->setObjectName(QString::fromUtf8("barMachine1"));
        barMachine1->setGeometry(QRect(0, 0, 100, 20));
        barMachine1->setStyleSheet(QString::fromUtf8("background-color:rgb(230, 230, 230);"));
        barMachine1->setFrameShape(QFrame::StyledPanel);
        barMachine1->setFrameShadow(QFrame::Raised);
        progressMachine1 = new QFrame(barMachine1);
        progressMachine1->setObjectName(QString::fromUtf8("progressMachine1"));
        progressMachine1->setGeometry(QRect(0, 0, 81, 20));
        progressMachine1->setStyleSheet(QString::fromUtf8("background-color:rgb(46, 194, 67);"));
        progressMachine1->setFrameShape(QFrame::StyledPanel);
        progressMachine1->setFrameShadow(QFrame::Raised);
        lbProgressMachine1 = new QLabel(panelProgress2);
        lbProgressMachine1->setObjectName(QString::fromUtf8("lbProgressMachine1"));
        lbProgressMachine1->setGeometry(QRect(110, 0, 21, 20));
        lbProgressMachine1->setFont(font1);
        frame_4 = new QFrame(frame_6);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setGeometry(QRect(0, 170, 270, 150));
        frame_4->setStyleSheet(QString::fromUtf8("background-color:rgb(167, 235, 248);"));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        iconMachine2 = new QLabel(frame_4);
        iconMachine2->setObjectName(QString::fromUtf8("iconMachine2"));
        iconMachine2->setGeometry(QRect(180, 50, 71, 71));
        iconMachine2->setStyleSheet(QString::fromUtf8("image:url(\":/images/batidora.png\");\n"
""));
        lbMachine2 = new QLabel(frame_4);
        lbMachine2->setObjectName(QString::fromUtf8("lbMachine2"));
        lbMachine2->setGeometry(QRect(10, 10, 150, 31));
        lbMachine2->setFont(font);
        lbDatosMachine2 = new QLabel(frame_4);
        lbDatosMachine2->setObjectName(QString::fromUtf8("lbDatosMachine2"));
        lbDatosMachine2->setGeometry(QRect(10, 75, 150, 71));
        lbDatosMachine2->setFont(font2);
        checkBoxMachine2 = new QCheckBox(frame_4);
        checkBoxMachine2->setObjectName(QString::fromUtf8("checkBoxMachine2"));
        checkBoxMachine2->setGeometry(QRect(200, 0, 51, 51));
        checkBoxMachine2->setStyleSheet(QString::fromUtf8("QCheckBox::indicator{\n"
"	width: 40px;\n"
"	height:40px;\n"
"}\n"
"\n"
"QCheckBox::indicator:checked{\n"
"	image:url(\":/images/switch-on.png\");\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked{\n"
"	image:url(\":/images/switch-off.png\");\n"
"}"));
        checkBoxMachine2->setChecked(true);
        panelProgress3 = new QFrame(frame_4);
        panelProgress3->setObjectName(QString::fromUtf8("panelProgress3"));
        panelProgress3->setGeometry(QRect(10, 50, 150, 20));
        panelProgress3->setFrameShape(QFrame::StyledPanel);
        panelProgress3->setFrameShadow(QFrame::Raised);
        barMachine2 = new QFrame(panelProgress3);
        barMachine2->setObjectName(QString::fromUtf8("barMachine2"));
        barMachine2->setGeometry(QRect(0, 0, 100, 20));
        barMachine2->setStyleSheet(QString::fromUtf8("background-color:rgb(230, 230, 230);"));
        barMachine2->setFrameShape(QFrame::StyledPanel);
        barMachine2->setFrameShadow(QFrame::Raised);
        progressMachine2 = new QFrame(barMachine2);
        progressMachine2->setObjectName(QString::fromUtf8("progressMachine2"));
        progressMachine2->setGeometry(QRect(0, 0, 81, 20));
        progressMachine2->setStyleSheet(QString::fromUtf8("background-color:rgb(46, 194, 67);"));
        progressMachine2->setFrameShape(QFrame::StyledPanel);
        progressMachine2->setFrameShadow(QFrame::Raised);
        lbProgressMachine2 = new QLabel(panelProgress3);
        lbProgressMachine2->setObjectName(QString::fromUtf8("lbProgressMachine2"));
        lbProgressMachine2->setGeometry(QRect(110, 0, 21, 20));
        lbProgressMachine2->setFont(font1);
        frame_5 = new QFrame(frame_6);
        frame_5->setObjectName(QString::fromUtf8("frame_5"));
        frame_5->setGeometry(QRect(0, 340, 270, 150));
        frame_5->setStyleSheet(QString::fromUtf8("background-color:rgb(167, 235, 248);"));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        iconMachine3 = new QLabel(frame_5);
        iconMachine3->setObjectName(QString::fromUtf8("iconMachine3"));
        iconMachine3->setGeometry(QRect(180, 50, 71, 71));
        iconMachine3->setStyleSheet(QString::fromUtf8("image:url(\":/images/chocolatera.png\");\n"
""));
        lbMachine3 = new QLabel(frame_5);
        lbMachine3->setObjectName(QString::fromUtf8("lbMachine3"));
        lbMachine3->setGeometry(QRect(10, 10, 150, 31));
        lbMachine3->setFont(font);
        lbDatosMachine3 = new QLabel(frame_5);
        lbDatosMachine3->setObjectName(QString::fromUtf8("lbDatosMachine3"));
        lbDatosMachine3->setGeometry(QRect(10, 75, 150, 71));
        lbDatosMachine3->setFont(font2);
        checkBoxMachine3 = new QCheckBox(frame_5);
        checkBoxMachine3->setObjectName(QString::fromUtf8("checkBoxMachine3"));
        checkBoxMachine3->setGeometry(QRect(200, 0, 51, 51));
        checkBoxMachine3->setStyleSheet(QString::fromUtf8("QCheckBox::indicator{\n"
"	width: 40px;\n"
"	height:40px;\n"
"}\n"
"\n"
"QCheckBox::indicator:checked{\n"
"	image:url(\":/images/switch-on.png\");\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked{\n"
"	image:url(\":/images/switch-off.png\");\n"
"}"));
        checkBoxMachine3->setChecked(true);
        panelProgress4 = new QFrame(frame_5);
        panelProgress4->setObjectName(QString::fromUtf8("panelProgress4"));
        panelProgress4->setGeometry(QRect(10, 50, 150, 20));
        panelProgress4->setFrameShape(QFrame::StyledPanel);
        panelProgress4->setFrameShadow(QFrame::Raised);
        barMachine3 = new QFrame(panelProgress4);
        barMachine3->setObjectName(QString::fromUtf8("barMachine3"));
        barMachine3->setGeometry(QRect(0, 0, 100, 20));
        barMachine3->setStyleSheet(QString::fromUtf8("background-color:rgb(230, 230, 230);"));
        barMachine3->setFrameShape(QFrame::StyledPanel);
        barMachine3->setFrameShadow(QFrame::Raised);
        progressMachine3 = new QFrame(barMachine3);
        progressMachine3->setObjectName(QString::fromUtf8("progressMachine3"));
        progressMachine3->setGeometry(QRect(0, 0, 81, 20));
        progressMachine3->setStyleSheet(QString::fromUtf8("background-color:rgb(46, 194, 67);"));
        progressMachine3->setFrameShape(QFrame::StyledPanel);
        progressMachine3->setFrameShadow(QFrame::Raised);
        lbProgressMachine3 = new QLabel(panelProgress4);
        lbProgressMachine3->setObjectName(QString::fromUtf8("lbProgressMachine3"));
        lbProgressMachine3->setGeometry(QRect(110, 0, 21, 20));
        lbProgressMachine3->setFont(font1);
        frame_7 = new QFrame(factoryPanel);
        frame_7->setObjectName(QString::fromUtf8("frame_7"));
        frame_7->setGeometry(QRect(730, 130, 441, 341));
        frame_7->setFrameShape(QFrame::StyledPanel);
        frame_7->setFrameShadow(QFrame::Raised);
        frame_8 = new QFrame(frame_7);
        frame_8->setObjectName(QString::fromUtf8("frame_8"));
        frame_8->setGeometry(QRect(0, 0, 130, 150));
        frame_8->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 239, 120);"));
        frame_8->setFrameShape(QFrame::StyledPanel);
        frame_8->setFrameShadow(QFrame::Raised);
        iconBanda1Mazcla = new QLabel(frame_8);
        iconBanda1Mazcla->setObjectName(QString::fromUtf8("iconBanda1Mazcla"));
        iconBanda1Mazcla->setGeometry(QRect(30, 30, 71, 71));
        iconBanda1Mazcla->setStyleSheet(QString::fromUtf8("image:url(\":/images/banda1Mezcla.png\");\n"
""));
        lbNameBanda1Mezcla = new QLabel(frame_8);
        lbNameBanda1Mezcla->setObjectName(QString::fromUtf8("lbNameBanda1Mezcla"));
        lbNameBanda1Mezcla->setGeometry(QRect(10, 0, 120, 31));
        lbNameBanda1Mezcla->setFont(font);
        lbDatosBanda1Mezcla = new QLabel(frame_8);
        lbDatosBanda1Mezcla->setObjectName(QString::fromUtf8("lbDatosBanda1Mezcla"));
        lbDatosBanda1Mezcla->setGeometry(QRect(10, 110, 120, 30));
        lbDatosBanda1Mezcla->setFont(font2);
        frame_9 = new QFrame(frame_7);
        frame_9->setObjectName(QString::fromUtf8("frame_9"));
        frame_9->setGeometry(QRect(0, 170, 130, 151));
        frame_9->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 239, 120);"));
        frame_9->setFrameShape(QFrame::StyledPanel);
        frame_9->setFrameShadow(QFrame::Raised);
        iconBanda2Chocolate = new QLabel(frame_9);
        iconBanda2Chocolate->setObjectName(QString::fromUtf8("iconBanda2Chocolate"));
        iconBanda2Chocolate->setGeometry(QRect(30, 30, 71, 71));
        iconBanda2Chocolate->setStyleSheet(QString::fromUtf8("image:url(\":/images/banda 2Chocolate.png\");\n"
""));
        lbNameBanda2Chocolate = new QLabel(frame_9);
        lbNameBanda2Chocolate->setObjectName(QString::fromUtf8("lbNameBanda2Chocolate"));
        lbNameBanda2Chocolate->setGeometry(QRect(5, 0, 120, 31));
        lbNameBanda2Chocolate->setFont(font);
        lbDatosBanda2Chocolate = new QLabel(frame_9);
        lbDatosBanda2Chocolate->setObjectName(QString::fromUtf8("lbDatosBanda2Chocolate"));
        lbDatosBanda2Chocolate->setGeometry(QRect(10, 109, 120, 31));
        lbDatosBanda2Chocolate->setFont(font2);
        frame_10 = new QFrame(frame_7);
        frame_10->setObjectName(QString::fromUtf8("frame_10"));
        frame_10->setGeometry(QRect(170, 60, 270, 150));
        frame_10->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 239, 120);"));
        frame_10->setFrameShape(QFrame::StyledPanel);
        frame_10->setFrameShadow(QFrame::Raised);
        iconAssembler = new QLabel(frame_10);
        iconAssembler->setObjectName(QString::fromUtf8("iconAssembler"));
        iconAssembler->setGeometry(QRect(180, 50, 71, 71));
        iconAssembler->setStyleSheet(QString::fromUtf8("image:url(\":/images/assembler.png\");\n"
""));
        lbNameAssembler = new QLabel(frame_10);
        lbNameAssembler->setObjectName(QString::fromUtf8("lbNameAssembler"));
        lbNameAssembler->setGeometry(QRect(10, 10, 150, 31));
        lbNameAssembler->setFont(font);
        lbDatosAssembler = new QLabel(frame_10);
        lbDatosAssembler->setObjectName(QString::fromUtf8("lbDatosAssembler"));
        lbDatosAssembler->setGeometry(QRect(10, 75, 150, 71));
        lbDatosAssembler->setFont(font2);
        checkBoxAssembler = new QCheckBox(frame_10);
        checkBoxAssembler->setObjectName(QString::fromUtf8("checkBoxAssembler"));
        checkBoxAssembler->setGeometry(QRect(200, 0, 51, 51));
        checkBoxAssembler->setStyleSheet(QString::fromUtf8("QCheckBox::indicator{\n"
"	width: 40px;\n"
"	height:40px;\n"
"}\n"
"\n"
"QCheckBox::indicator:checked{\n"
"	image:url(\":/images/switch-on.png\");\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked{\n"
"	image:url(\":/images/switch-off.png\");\n"
"}"));
        checkBoxAssembler->setChecked(true);
        panelProgress3_3 = new QFrame(frame_10);
        panelProgress3_3->setObjectName(QString::fromUtf8("panelProgress3_3"));
        panelProgress3_3->setGeometry(QRect(10, 50, 150, 20));
        panelProgress3_3->setFrameShape(QFrame::StyledPanel);
        panelProgress3_3->setFrameShadow(QFrame::Raised);
        barAssembler = new QFrame(panelProgress3_3);
        barAssembler->setObjectName(QString::fromUtf8("barAssembler"));
        barAssembler->setGeometry(QRect(0, 0, 100, 20));
        barAssembler->setStyleSheet(QString::fromUtf8("background-color:rgb(230, 230, 230);"));
        barAssembler->setFrameShape(QFrame::StyledPanel);
        barAssembler->setFrameShadow(QFrame::Raised);
        progressAssembler = new QFrame(barAssembler);
        progressAssembler->setObjectName(QString::fromUtf8("progressAssembler"));
        progressAssembler->setGeometry(QRect(0, 0, 81, 20));
        progressAssembler->setStyleSheet(QString::fromUtf8("background-color:rgb(46, 194, 67);"));
        progressAssembler->setFrameShape(QFrame::StyledPanel);
        progressAssembler->setFrameShadow(QFrame::Raised);
        lbProgressAssembler = new QLabel(panelProgress3_3);
        lbProgressAssembler->setObjectName(QString::fromUtf8("lbProgressAssembler"));
        lbProgressAssembler->setGeometry(QRect(110, 0, 21, 20));
        lbProgressAssembler->setFont(font1);
        btnIniciar = new QPushButton(factoryPage);
        btnIniciar->setObjectName(QString::fromUtf8("btnIniciar"));
        btnIniciar->setGeometry(QRect(220, 890, 121, 41));
        contentPanel->addWidget(factoryPage);
        dataPage = new QWidget();
        dataPage->setObjectName(QString::fromUtf8("dataPage"));
        dataPanel = new QFrame(dataPage);
        dataPanel->setObjectName(QString::fromUtf8("dataPanel"));
        dataPanel->setGeometry(QRect(0, 0, 1921, 1080));
        dataPanel->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 255, 255);"));
        dataPanel->setFrameShape(QFrame::StyledPanel);
        dataPanel->setFrameShadow(QFrame::Raised);
        frame_12 = new QFrame(dataPanel);
        frame_12->setObjectName(QString::fromUtf8("frame_12"));
        frame_12->setGeometry(QRect(10, 120, 500, 121));
        frame_12->setStyleSheet(QString::fromUtf8("background-color:rgb(250,250,250);"));
        frame_12->setFrameShape(QFrame::StyledPanel);
        frame_12->setFrameShadow(QFrame::Raised);
        label_4 = new QLabel(frame_12);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 80, 91, 31));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Roboto")});
        font3.setPointSize(12);
        label_4->setFont(font3);
        txtDurationCar = new QLineEdit(frame_12);
        txtDurationCar->setObjectName(QString::fromUtf8("txtDurationCar"));
        txtDurationCar->setGeometry(QRect(130, 85, 191, 21));
        txtDurationCar->setFont(font3);
        txtDurationCar->setStyleSheet(QString::fromUtf8("border-width: 1px;\n"
"border-style: solid;\n"
"border-color: rgb(254, 188, 187);;"));
        txtCapacidadCar = new QLineEdit(frame_12);
        txtCapacidadCar->setObjectName(QString::fromUtf8("txtCapacidadCar"));
        txtCapacidadCar->setGeometry(QRect(130, 45, 191, 21));
        txtCapacidadCar->setFont(font3);
        txtCapacidadCar->setStyleSheet(QString::fromUtf8("border-width: 1px;\n"
"border-style: solid;\n"
"border-color: rgb(254, 188, 187);;"));
        label_2 = new QLabel(frame_12);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 40, 91, 31));
        label_2->setFont(font3);
        label = new QLabel(frame_12);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 500, 31));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Doppio One")});
        font4.setPointSize(16);
        font4.setBold(false);
        label->setFont(font4);
        label->setStyleSheet(QString::fromUtf8("color: white;\n"
"background-color:rgb(254, 188, 187);\n"
""));
        frame_13 = new QFrame(dataPanel);
        frame_13->setObjectName(QString::fromUtf8("frame_13"));
        frame_13->setGeometry(QRect(10, 500, 500, 201));
        frame_13->setStyleSheet(QString::fromUtf8("background-color:rgb(250,250,250);"));
        frame_13->setFrameShape(QFrame::StyledPanel);
        frame_13->setFrameShadow(QFrame::Raised);
        label_8 = new QLabel(frame_13);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(0, 0, 501, 31));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Doppio One")});
        font5.setPointSize(16);
        label_8->setFont(font5);
        label_8->setStyleSheet(QString::fromUtf8("color: white;\n"
"background-color:rgb(167, 235, 248);"));
        txtCantProcesarMezcladora1 = new QLineEdit(frame_13);
        txtCantProcesarMezcladora1->setObjectName(QString::fromUtf8("txtCantProcesarMezcladora1"));
        txtCantProcesarMezcladora1->setGeometry(QRect(120, 145, 191, 21));
        txtCantProcesarMezcladora1->setFont(font3);
        label_9 = new QLabel(frame_13);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(10, 140, 101, 31));
        label_9->setFont(font3);
        txtMaxMecladora1 = new QLineEdit(frame_13);
        txtMaxMecladora1->setObjectName(QString::fromUtf8("txtMaxMecladora1"));
        txtMaxMecladora1->setGeometry(QRect(120, 85, 191, 21));
        txtMaxMecladora1->setFont(font3);
        txtDurationMecladora1 = new QLineEdit(frame_13);
        txtDurationMecladora1->setObjectName(QString::fromUtf8("txtDurationMecladora1"));
        txtDurationMecladora1->setGeometry(QRect(120, 115, 191, 21));
        txtDurationMecladora1->setFont(font3);
        label_7 = new QLabel(frame_13);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 50, 91, 31));
        label_7->setFont(font3);
        txtMinMezcladora1 = new QLineEdit(frame_13);
        txtMinMezcladora1->setObjectName(QString::fromUtf8("txtMinMezcladora1"));
        txtMinMezcladora1->setGeometry(QRect(120, 55, 191, 21));
        txtMinMezcladora1->setFont(font3);
        label_6 = new QLabel(frame_13);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 80, 91, 31));
        label_6->setFont(font3);
        label_5 = new QLabel(frame_13);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 110, 91, 31));
        label_5->setFont(font3);
        frame_14 = new QFrame(dataPanel);
        frame_14->setObjectName(QString::fromUtf8("frame_14"));
        frame_14->setGeometry(QRect(10, 280, 500, 200));
        frame_14->setStyleSheet(QString::fromUtf8("background-color:rgb(250,250,250);"));
        frame_14->setFrameShape(QFrame::StyledPanel);
        frame_14->setFrameShadow(QFrame::Raised);
        label_14 = new QLabel(frame_14);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(0, 0, 500, 31));
        label_14->setFont(font4);
        label_14->setStyleSheet(QString::fromUtf8("color: white;\n"
"background-color:rgb(167, 235, 248);"));
        txtMaxMecladora2 = new QLineEdit(frame_14);
        txtMaxMecladora2->setObjectName(QString::fromUtf8("txtMaxMecladora2"));
        txtMaxMecladora2->setGeometry(QRect(130, 85, 191, 21));
        txtMaxMecladora2->setFont(font3);
        txtMaxMecladora2->setStyleSheet(QString::fromUtf8("border-width: 1px;\n"
"border-style: solid;\n"
"border-color: rgb(167, 235, 248);"));
        label_12 = new QLabel(frame_14);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(20, 110, 91, 31));
        label_12->setFont(font3);
        label_11 = new QLabel(frame_14);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(20, 80, 91, 31));
        label_11->setFont(font3);
        label_10 = new QLabel(frame_14);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(20, 140, 101, 31));
        label_10->setFont(font3);
        txtCantProcesarMezcladora2 = new QLineEdit(frame_14);
        txtCantProcesarMezcladora2->setObjectName(QString::fromUtf8("txtCantProcesarMezcladora2"));
        txtCantProcesarMezcladora2->setGeometry(QRect(130, 145, 191, 21));
        txtCantProcesarMezcladora2->setFont(font3);
        txtCantProcesarMezcladora2->setStyleSheet(QString::fromUtf8("border-width: 1px;\n"
"border-style: solid;\n"
"border-color: rgb(167, 235, 248);"));
        label_13 = new QLabel(frame_14);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(20, 50, 91, 31));
        label_13->setFont(font3);
        txtMinMezcladora2 = new QLineEdit(frame_14);
        txtMinMezcladora2->setObjectName(QString::fromUtf8("txtMinMezcladora2"));
        txtMinMezcladora2->setGeometry(QRect(130, 55, 191, 21));
        txtMinMezcladora2->setFont(font3);
        txtMinMezcladora2->setStyleSheet(QString::fromUtf8("border-width: 1px;\n"
"border-style: solid;\n"
"border-color: rgb(167, 235, 248);"));
        txttDurationMecladora2 = new QLineEdit(frame_14);
        txttDurationMecladora2->setObjectName(QString::fromUtf8("txttDurationMecladora2"));
        txttDurationMecladora2->setGeometry(QRect(130, 115, 191, 21));
        txttDurationMecladora2->setFont(font3);
        txttDurationMecladora2->setStyleSheet(QString::fromUtf8("border-width: 1px;\n"
"border-style: solid;\n"
"border-color: rgb(167, 235, 248);"));
        frame_15 = new QFrame(dataPanel);
        frame_15->setObjectName(QString::fromUtf8("frame_15"));
        frame_15->setGeometry(QRect(10, 720, 500, 200));
        frame_15->setStyleSheet(QString::fromUtf8("background-color:rgb(250,250,250);"));
        frame_15->setFrameShape(QFrame::StyledPanel);
        frame_15->setFrameShadow(QFrame::Raised);
        label_19 = new QLabel(frame_15);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(0, 0, 500, 31));
        label_19->setFont(font4);
        label_19->setStyleSheet(QString::fromUtf8("color: white;\n"
"background-color:rgb(167, 235, 248);"));
        txtMinChocolatera = new QLineEdit(frame_15);
        txtMinChocolatera->setObjectName(QString::fromUtf8("txtMinChocolatera"));
        txtMinChocolatera->setGeometry(QRect(130, 55, 191, 21));
        txtMinChocolatera->setFont(font3);
        label_15 = new QLabel(frame_15);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(20, 140, 101, 31));
        label_15->setFont(font3);
        txtDurationChocolatera = new QLineEdit(frame_15);
        txtDurationChocolatera->setObjectName(QString::fromUtf8("txtDurationChocolatera"));
        txtDurationChocolatera->setGeometry(QRect(130, 115, 191, 21));
        txtDurationChocolatera->setFont(font3);
        label_18 = new QLabel(frame_15);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(20, 50, 91, 31));
        label_18->setFont(font3);
        txtCantProcesarChocolatera = new QLineEdit(frame_15);
        txtCantProcesarChocolatera->setObjectName(QString::fromUtf8("txtCantProcesarChocolatera"));
        txtCantProcesarChocolatera->setGeometry(QRect(130, 145, 191, 21));
        txtCantProcesarChocolatera->setFont(font3);
        label_16 = new QLabel(frame_15);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(20, 80, 91, 31));
        label_16->setFont(font3);
        label_17 = new QLabel(frame_15);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(20, 110, 91, 31));
        label_17->setFont(font3);
        txtMaxChocolatera = new QLineEdit(frame_15);
        txtMaxChocolatera->setObjectName(QString::fromUtf8("txtMaxChocolatera"));
        txtMaxChocolatera->setGeometry(QRect(130, 85, 191, 21));
        txtMaxChocolatera->setFont(font3);
        frame_11 = new QFrame(dataPanel);
        frame_11->setObjectName(QString::fromUtf8("frame_11"));
        frame_11->setGeometry(QRect(0, 0, 1921, 51));
        frame_11->setFrameShape(QFrame::StyledPanel);
        frame_11->setFrameShadow(QFrame::Raised);
        label_20 = new QLabel(frame_11);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(0, 0, 1931, 61));
        label_20->setFont(font3);
        label_20->setStyleSheet(QString::fromUtf8("background-color:rgb(254, 188, 187);"));
        label_22 = new QLabel(frame_11);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(10, 10, 1901, 51));
        label_22->setFont(font3);
        label_22->setStyleSheet(QString::fromUtf8("\n"
"background-color:rgb(25,25,50);"));
        frame_16 = new QFrame(dataPanel);
        frame_16->setObjectName(QString::fromUtf8("frame_16"));
        frame_16->setGeometry(QRect(570, 120, 500, 350));
        frame_16->setStyleSheet(QString::fromUtf8("background-color:rgb(250,250,250);"));
        frame_16->setFrameShape(QFrame::StyledPanel);
        frame_16->setFrameShadow(QFrame::Raised);
        label_21 = new QLabel(frame_16);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(0, 0, 500, 31));
        label_21->setFont(font4);
        label_21->setStyleSheet(QString::fromUtf8("color: black;\n"
"background-color:rgb(255, 239, 120);"));
        txtMaxBanda2Chocolate = new QLineEdit(frame_16);
        txtMaxBanda2Chocolate->setObjectName(QString::fromUtf8("txtMaxBanda2Chocolate"));
        txtMaxBanda2Chocolate->setGeometry(QRect(130, 290, 191, 21));
        txtMaxBanda2Chocolate->setFont(font3);
        txtMaxBanda2Chocolate->setStyleSheet(QString::fromUtf8("border-width: 1px;\n"
"border-style: solid;\n"
"border-color: rgb(255, 239, 120);"));
        label_23 = new QLabel(frame_16);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(20, 50, 91, 31));
        label_23->setFont(font3);
        label_24 = new QLabel(frame_16);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(20, 290, 91, 31));
        label_24->setFont(font3);
        label_25 = new QLabel(frame_16);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(20, 80, 101, 31));
        label_25->setFont(font3);
        txtCantProcesarAssembler = new QLineEdit(frame_16);
        txtCantProcesarAssembler->setObjectName(QString::fromUtf8("txtCantProcesarAssembler"));
        txtCantProcesarAssembler->setGeometry(QRect(130, 85, 191, 21));
        txtCantProcesarAssembler->setFont(font3);
        txtCantProcesarAssembler->setStyleSheet(QString::fromUtf8("border-width: 1px;\n"
"border-style: solid;\n"
"border-color: rgb(255, 239, 120);"));
        label_26 = new QLabel(frame_16);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setGeometry(QRect(20, 190, 91, 31));
        label_26->setFont(font3);
        txtMaxBanda1Mezcla = new QLineEdit(frame_16);
        txtMaxBanda1Mezcla->setObjectName(QString::fromUtf8("txtMaxBanda1Mezcla"));
        txtMaxBanda1Mezcla->setGeometry(QRect(130, 190, 191, 21));
        txtMaxBanda1Mezcla->setFont(font3);
        txtMaxBanda1Mezcla->setStyleSheet(QString::fromUtf8("border-width: 1px;\n"
"border-style: solid;\n"
"border-color: rgb(255, 239, 120);"));
        txtDurationAssembler = new QLineEdit(frame_16);
        txtDurationAssembler->setObjectName(QString::fromUtf8("txtDurationAssembler"));
        txtDurationAssembler->setGeometry(QRect(130, 55, 191, 21));
        txtDurationAssembler->setFont(font3);
        txtDurationAssembler->setStyleSheet(QString::fromUtf8("border-width: 1px;\n"
"border-style: solid;\n"
"border-color: rgb(255, 239, 120);"));
        label_27 = new QLabel(frame_16);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setGeometry(QRect(10, 140, 141, 31));
        QFont font6;
        font6.setFamilies({QString::fromUtf8("Doppio One")});
        font6.setPointSize(14);
        label_27->setFont(font6);
        label_27->setStyleSheet(QString::fromUtf8(""));
        label_28 = new QLabel(frame_16);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setGeometry(QRect(10, 240, 171, 31));
        label_28->setFont(font6);
        label_28->setStyleSheet(QString::fromUtf8(""));
        btnGoToSimulation = new QPushButton(dataPanel);
        btnGoToSimulation->setObjectName(QString::fromUtf8("btnGoToSimulation"));
        btnGoToSimulation->setGeometry(QRect(1300, 200, 251, 101));
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
        btnGotoDatos->setText(QCoreApplication::translate("MainWindow", "Datos", nullptr));
        iconCar->setText(QString());
        checkBoxCar->setText(QString());
        lbCarro->setText(QCoreApplication::translate("MainWindow", "Carro", nullptr));
        lbProgressCar->setText(QCoreApplication::translate("MainWindow", "0 %", nullptr));
        lbDatosCar->setText(QCoreApplication::translate("MainWindow", "datos", nullptr));
        lbCola->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        iconMachine1->setText(QString());
        lbMachine1->setText(QCoreApplication::translate("MainWindow", "Mezcladora 1", nullptr));
        lbDatosMachine1->setText(QCoreApplication::translate("MainWindow", "datos", nullptr));
        checkBoxMachine1->setText(QString());
        lbProgressMachine1->setText(QCoreApplication::translate("MainWindow", "0 %", nullptr));
        iconMachine2->setText(QString());
        lbMachine2->setText(QCoreApplication::translate("MainWindow", "Mezcladora 2", nullptr));
        lbDatosMachine2->setText(QCoreApplication::translate("MainWindow", "datos", nullptr));
        checkBoxMachine2->setText(QString());
        lbProgressMachine2->setText(QCoreApplication::translate("MainWindow", "0 %", nullptr));
        iconMachine3->setText(QString());
        lbMachine3->setText(QCoreApplication::translate("MainWindow", "Chocolatera", nullptr));
        lbDatosMachine3->setText(QCoreApplication::translate("MainWindow", "datos", nullptr));
        checkBoxMachine3->setText(QString());
        lbProgressMachine3->setText(QCoreApplication::translate("MainWindow", "0 %", nullptr));
        iconBanda1Mazcla->setText(QString());
        lbNameBanda1Mezcla->setText(QCoreApplication::translate("MainWindow", "Banda 1 Mezcla", nullptr));
        lbDatosBanda1Mezcla->setText(QCoreApplication::translate("MainWindow", "datos", nullptr));
        iconBanda2Chocolate->setText(QString());
        lbNameBanda2Chocolate->setText(QCoreApplication::translate("MainWindow", "Banda 1 Chocolate", nullptr));
        lbDatosBanda2Chocolate->setText(QCoreApplication::translate("MainWindow", "datos", nullptr));
        iconAssembler->setText(QString());
        lbNameAssembler->setText(QCoreApplication::translate("MainWindow", "Assembler", nullptr));
        lbDatosAssembler->setText(QCoreApplication::translate("MainWindow", "datos", nullptr));
        checkBoxAssembler->setText(QString());
        lbProgressAssembler->setText(QCoreApplication::translate("MainWindow", "0 %", nullptr));
        btnIniciar->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Duraci\303\263n:", nullptr));
        txtDurationCar->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        txtCapacidadCar->setText(QCoreApplication::translate("MainWindow", "100", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Capacidad:", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Datos Del Carrito", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Datos Mezcladora 1", nullptr));
        txtCantProcesarMezcladora1->setText(QCoreApplication::translate("MainWindow", "15", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Cant Procesar", nullptr));
        txtMaxMecladora1->setText(QCoreApplication::translate("MainWindow", "45", nullptr));
        txtDurationMecladora1->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "M\303\255nimo: ", nullptr));
        txtMinMezcladora1->setText(QCoreApplication::translate("MainWindow", "20", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "M\303\241ximo:", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Duraci\303\263n:", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Datos Mezcladora 2", nullptr));
        txtMaxMecladora2->setText(QCoreApplication::translate("MainWindow", "50", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Duraci\303\263n:", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "M\303\241ximo:", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Cant Procesar", nullptr));
        txtCantProcesarMezcladora2->setText(QCoreApplication::translate("MainWindow", "10", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "M\303\255nimo: ", nullptr));
        txtMinMezcladora2->setText(QCoreApplication::translate("MainWindow", "20", nullptr));
        txttDurationMecladora2->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "Datos Chocolatera", nullptr));
        txtMinChocolatera->setText(QCoreApplication::translate("MainWindow", "50", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "Cant Procesar", nullptr));
        txtDurationChocolatera->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "M\303\255nimo: ", nullptr));
        txtCantProcesarChocolatera->setText(QCoreApplication::translate("MainWindow", "20", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "M\303\241ximo:", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "Duraci\303\263n:", nullptr));
        txtMaxChocolatera->setText(QCoreApplication::translate("MainWindow", "600", nullptr));
        label_20->setText(QString());
        label_22->setText(QString());
        label_21->setText(QCoreApplication::translate("MainWindow", "Datos Ensambladora", nullptr));
        txtMaxBanda2Chocolate->setText(QCoreApplication::translate("MainWindow", "300", nullptr));
        label_23->setText(QCoreApplication::translate("MainWindow", "Duraci\303\263n:", nullptr));
        label_24->setText(QCoreApplication::translate("MainWindow", "M\303\241ximo:", nullptr));
        label_25->setText(QCoreApplication::translate("MainWindow", "Cant Procesar", nullptr));
        txtCantProcesarAssembler->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        label_26->setText(QCoreApplication::translate("MainWindow", "M\303\241ximo:", nullptr));
        txtMaxBanda1Mezcla->setText(QCoreApplication::translate("MainWindow", "200", nullptr));
        txtDurationAssembler->setText(QCoreApplication::translate("MainWindow", "15", nullptr));
        label_27->setText(QCoreApplication::translate("MainWindow", "Banda 1 Mezcla", nullptr));
        label_28->setText(QCoreApplication::translate("MainWindow", "Banda 2 Chocolate", nullptr));
        btnGoToSimulation->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
