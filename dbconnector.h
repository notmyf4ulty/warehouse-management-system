#ifndef DBCONNECTOR_H
#define DBCONNECTOR_H
#include <QSqlDatabase>

class dbConnector
{
private:
    QString hostName;
    QString databaseName;
    QString userName;
    QString password;
    QSqlDatabase db;
public:
    dbConnector();
    dbConnector(QString _hostName, QString _databaseName, QString _userName, QString _password):
    hostName(_hostName), databaseName(_databaseName), userName(_userName), password(_password) {}
    void runDatabase();
};

#endif // DBCONNECTOR_H
