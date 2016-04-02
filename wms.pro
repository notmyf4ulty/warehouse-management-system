#-------------------------------------------------
#
# Project created by QtCreator 2016-03-16T22:46:56
#
#-------------------------------------------------

QT       += core gui
QT       += sql
QTPLUGIN += qsqlmysql
CONFIG += console

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SQL
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    dbconnector.cpp \
    mysqlcmddialog.cpp \
    addcomponentdialog.cpp \
    addtobasketdialog.cpp

HEADERS  += mainwindow.h \
    dbconnector.h \
    mysqlcmddialog.h \
    addcomponentdialog.h \
    addtobasketdialog.h

FORMS    += mainwindow.ui
