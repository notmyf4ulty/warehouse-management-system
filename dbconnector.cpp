#include "dbconnector.h"


using namespace std;

dbConnector::dbConnector() {
    // db4free
//    hostName = "db4free.net";
//    databaseName = "wmscpp";
//    userName = "wmsuser";
//    password = "password";

 //local
//    hostName = "localhost";
//    databaseName = "mojaBaza";
//    userName = "tutorial";
//    password = "password";
//    model.setHeaderData(0, Qt::Horizontal, "Typ");
//    model.setHeaderData(1, Qt::Horizontal, "Wartość");

    hostName = "sql7.freemysqlhosting.net";
    databaseName = "sql7115646";
    userName = "sql7115646";
    password = "j6ENDblJDY";
}

bool dbConnector::runDatabase()
{
    database = QSqlDatabase::addDatabase("QMYSQL");
    database.setHostName(hostName);
    database.setDatabaseName(databaseName);
    database.setUserName(userName);
    database.setPassword(password);
    database.setPort(3306);

    if(!database.open())
        return false;

    return true;
}


