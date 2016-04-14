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

//DEBUG
#include <QDebug>
#include "component.h"
#include <QString>
#include <QVector>
#include "basket.h"

using namespace std;

void testInConsole();

int main(int argc, char *argv[])
{
//    testInConsole();
    QApplication app(argc, argv);

    MainWindow mainWindow(&app);
    mainWindow.show();
    return app.exec();
}

//void testInConsole() {
//    Basket basket;
//}
