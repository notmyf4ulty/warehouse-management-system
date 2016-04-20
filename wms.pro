#-------------------------------------------------
#
# Project created by QtCreator 2016-03-16T22:46:56
#
#-------------------------------------------------

QT       += core gui
QT       += sql
QTPLUGIN += qsqlmysql
CONFIG += console\
    c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SQL
TEMPLATE = app
DEPENDPATH *= ${INCLUDEPATH}

SOURCES += main.cpp\
        mainwindow.cpp \
    dbconnector.cpp \
    mysqlcmddialog.cpp \
    addcomponentdialog.cpp \
    basketdialog.cpp \
    basket.cpp \
    basketcomponent.cpp \
    admin.cpp \
    adminlogindialog.cpp

HEADERS  += mainwindow.h \
    dbconnector.h \
    mysqlcmddialog.h \
    addcomponentdialog.h \
    basketdialog.h \
    basket.h \
    basketcomponent.h \
    admin.h \
    adminlogindialog.h \
    geometry.h

FORMS    += mainwindow.ui
