#include "dbconnector.h"
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>

using namespace std;

dbConnector::dbConnector()
{
//    hostName = "localhost";
//    databaseName = "sakila";
//    userName = "tutorial";
//    password = "password";

    hostName = "db4free.net";
    databaseName = "wmscpp";
    userName = "wmsuser";
    password = "password";
}

void dbConnector::runDatabase()
{
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName(hostName);
    db.setDatabaseName(databaseName);
    db.setUserName(userName);
    db.setPassword(password);

    if(!db.open())
        qDebug() << "Error while opening database";
}
