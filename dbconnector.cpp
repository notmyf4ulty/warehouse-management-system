#include "dbconnector.h"
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>

using namespace std;

dbConnector::dbConnector()
{
    hostName = "localhost";
    databaseName = "sakila";
    userName = "tutorial";
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

void dbConnector::runQueryInConsole(QString queryCommand)
{
    QSqlQuery query;
    query.exec(queryCommand);

    while (query.next()) {
        for (int i = 0 ; i < 4 ; ++i) {
            qDebug() << query.value(i).toString();
        }
        qDebug() << endl;
    }
}

//    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
//    db.setHostName("localhost");
//    db.setDatabaseName("sakila");
//    db.setUserName("tutorial");
//    db.setPassword("password");
//    bool ok = db.open();

//    string tellMe;
//    QString QtellMe;
//    cout << "Tell me something\n";
//    getline(cin,tellMe);
//    cout << tellMe << endl;
//    QtellMe = QString::fromStdString(tellMe);

//    QSqlQuery query;
//    query.exec(QtellMe);

//    while (query.next()) {
//        QString f_name = query.value(0).toString();
//        QString s_name = query.value(1).toString();
//        qDebug() << f_name + " " + s_name;

//    }
