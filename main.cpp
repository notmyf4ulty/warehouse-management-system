// General
#include <iostream>
#include <QApplication>
#include <QDebug>

// Databases
#include <QSqlDatabase>
#include <QSqlQuery>
#include "dbconnector.h"
#include <QSqlQueryModel>

// GUI
#include "mainwindow.h"
#include <QTableView>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    dbConnector db;
    db.runDatabase();

    MainWindow mainWindow;
    mainWindow.show();
    return app.exec();
}
