#ifndef DBCONNECTOR_H
#define DBCONNECTOR_H

#include <QObject>
#include <QTranslator>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlDatabase>
//#include <QtSql>
#include <QDebug>
#include <QSqlQuery>

//!  Klasa obsługująca połączenie z bazą danych.
/*!
  Za jej pomocą aplikacja łączy się z bazą danych i to ona zapewnia logikę komunikacji.
  Klasa stworzona wg wzorca Singleton.
*/
class dbConnector
{
public:
    //! Funkcja zwracająca instancję klasy.
    /*!
      Wzorzec nie pozwala na stworzenie więcej niż jednej instancji klasy - konstruktor jest niedostępny publicznie.
      Jedyna możliwość skorzystania z klasy to odwołanie się do opisywanej funkcji.
    */
    static dbConnector &getInstance() { static dbConnector instance; return instance; }

    //! Funkcja uruchamiająca połączenie z bazą danych.
    bool runDatabase();

    //! Funkcja zwracająca model
    //! (patrz <a href="https://pl.wikipedia.org/wiki/Model-View-Controller">Wzorzec MVC</a>), za pomocą którego
    //! można wykonywać zapytania na bazie danych.
    QSqlQueryModel &getModel() { return model; }

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
};

#endif // DBCONNECTOR_H
