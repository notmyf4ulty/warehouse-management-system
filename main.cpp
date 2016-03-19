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

//    QSqlQueryModel *model = new QSqlQueryModel;
//    model->setQuery("SELECT first_name, last_name FROM actor;");
//    model->setHeaderData(0, Qt::Horizontal, "Name");
//    model->setHeaderData(1, Qt::Horizontal, "Salary");

//    QTableView *view = new QTableView;
//    view->setModel(model);
//    view->show();

//    string cmd;

//    do {
//        qDebug() << "Type a query: ";
//        getline(cin, cmd);
//        db.runQueryInConsole(QString::fromStdString(cmd));
//    }
//    while (cmd != "exit");

    MainWindow mainWindow;
    mainWindow.show();
    return app.exec();
}
