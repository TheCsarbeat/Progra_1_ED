QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    estructuras_almacen.cpp \
    estructuras_ensambladora.cpp \
    estructuras_mezcladoras.cpp \
    estructuras_planificacion.cpp \
    machines_thread.cpp \
    main.cpp \
    main_struct.cpp \
    main_thread.cpp \
    mainwindow.cpp \
    thread_almacen_machines.cpp \
    thread_machines_ensambladora.cpp

HEADERS += \
    estructuras_almacen.h \
    estructuras_ensambladora.h \
    estructuras_mezcladoras.h \
    estructuras_planificacion.h \
    main_struct.h \
    main_thread.h \
    mainwindow.h \
    thread_almacen_machines.h \
    thread_machines_ensambladora.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
