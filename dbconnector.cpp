#include "dbconnector.h"


using namespace std;

dbConnector::dbConnector() {
//    hostName = "db4free.net";
//    databaseName = "wmscpp";
//    userName = "wmsuser";
//    password = "password";
    hostName = "localhost";
    databaseName = "mojaBaza";
    userName = "tutorial";
    password = "password";
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
    database.setPort(3306);

    if(!database.open())
        qDebug() << "Error while opening database";
}


