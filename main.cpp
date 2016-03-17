#include "mainwindow.h"
#include <QApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>


int main(int argc, char *argv[])
{
//    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

//    return a.exec();
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("sakila");
    db.setUserName("tutorial");
    db.setPassword("password");
    bool ok = db.open();

    QSqlQuery query;
    //actor_id, first_name, second_name
    query.exec("SELECT * FROM actor;");

    while (query.next()) {
        QString f_name = query.value(0).toString();
        QString s_name = query.value(1).toString();
        qDebug() << f_name + " " + s_name;
    }
}
