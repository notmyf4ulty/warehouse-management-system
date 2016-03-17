#include "mainwindow.h"
#include <QApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <iostream>

using namespace std;

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

    string tellMe;
    QString QtellMe;

    QSqlQuery query;

    cout << "Tell me something\n";

    do {

        cin >> tellMe;
        cout << tellMe << endl;
        //        QtellMe = QString::fromStdString(tellMe);

        //        query.exec(QtellMe);

        //        while (query.next()) {
        //            QString f_name = query.value(0).toString();
        //            QString s_name = query.value(1).toString();
        //            qDebug() << f_name + " " + s_name;
        //        }
    }
    while (tellMe != "exit");

}
