#-------------------------------------------------
#
# Project created by QtCreator 2016-03-16T22:46:56
#
#-------------------------------------------------

QT       += core gui
QT       += sql
QTPLUGIN += qsqlmysql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SQL
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui
