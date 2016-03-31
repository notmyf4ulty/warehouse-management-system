#include "dbconnector.h"
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>

using namespace std;

dbConnector::dbConnector() {
//    hostName = "localhost";
//    databaseName = "sakila";
//    userName = "tutorial";
//    password = "password";

    hostName = "db4free.net";
    databaseName = "wmscpp";
    userName = "wmsuser";
    password = "password";
//    model = new QSqlQueryModel(this);
    model.setHeaderData(0, Qt::Horizontal, "Typ");
    model.setHeaderData(1, Qt::Horizontal, "Wartość");
}



void dbConnector::runDatabase()
{
    database = QSqlDatabase::addDatabase("QMYSQL");
    database.setHostName(hostName);
    database.setDatabaseName(databaseName);
    database.setUserName(userName);
    database.setPassword(password);

    if(!database.open())
        qDebug() << "Error while opening database";
}
