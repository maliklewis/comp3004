#-------------------------------------------------
#
# Project created by QtCreator 2019-01-23T12:36:45
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Cuacs
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS CUACS_ROOT_DIR=\\\"$$_PRO_FILE_PWD_\\\"

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    databasemanager.cpp \
    stafflogin.cpp \
    staffview.cpp \
    staffcontroller.cpp \
    browseanimalsview.cpp \
    addanimalview.cpp \
    animaldetailsview.cpp \
    addclientview.cpp \
    browseclientview.cpp \
    clientview.cpp \
    clientlogin.cpp \
    clientcontroller.cpp \
    systemcontroller.cpp \
    editclientdetailsview.cpp \
    clientdetailsview.cpp \
    animal.cpp \
    clientpreferencesview.cpp \
    algorithmcontroller.cpp \
    client.cpp \
    algorithmoutputview.cpp

HEADERS += \
        mainwindow.h \
    databasemanager.h \
    stafflogin.h \
    staffview.h \
    staffcontroller.h \
    browseanimalsview.h \
    addanimalview.h \
    animaldetailsview.h \
    addclientview.h \
    browseclientview.h \
    clientview.h \
    clientlogin.h \
    clientcontroller.h \
    systemcontroller.h \
    editclientdetailsview.h \
    clientdetailsview.h \
    animal.h \
    clientpreferencesview.h \
    algorithmcontroller.h \
    client.h \
    algorithmoutputview.h

FORMS += \
        mainwindow.ui \
    stafflogin.ui \
    staffview.ui \
    browseanimalsview.ui \
    addanimalview.ui \
    animaldetailsview.ui \
    addclientview.ui \
    browseclientview.ui \
    clientview.ui \
    clientlogin.ui \
    editclientdetailsview.ui \
    clientdetailsview.ui \
    clientpreferencesview.ui \
    algorithmoutputview.ui
