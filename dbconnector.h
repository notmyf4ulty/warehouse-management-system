#ifndef DBCONNECTOR_H
#define DBCONNECTOR_H

#include <QObject>
#include <QTranslator>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>

class dbConnector
{
private:
    dbConnector();
    dbConnector(const dbConnector &);
    dbConnector& operator=(const dbConnector&);
    ~dbConnector() {}
    QString hostName;
    QString databaseName;
    QString userName;
    QString password;
    QSqlDatabase database;
    QSqlQueryModel model;

public:
    static dbConnector &getInstance() { static dbConnector instance; return instance; }
    bool runDatabase();
    QSqlQueryModel &getModel() { return model; }
};

#endif // DBCONNECTOR_H
