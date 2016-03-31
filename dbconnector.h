#ifndef DBCONNECTOR_H
#define DBCONNECTOR_H
#include <QSqlDatabase>
#include <QSqlQueryModel>

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
    void runDatabase();
    QSqlQueryModel &getModel() { return model; }
};

#endif // DBCONNECTOR_H
