#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QObject>
#include <QMainWindow>
#include <QPushButton>
#include <QTableView>
#include <QSqlQueryModel>
#include <QGridLayout>
#include <QWidget>
#include <QLineEdit>
#include <QFileDialog>
#include <QString>
#include <QDebug>
#include <QVector>
#include <QMenu>
#include <QMenuBar>
#include <QApplication>
#include <QList>
#include "dbconnector.h"
#include "addelementdialog.h"
#include "mysqlcmddialog.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QApplication *_app, QWidget *parent = 0);

private slots:
    void importCSV();
    void configureDatabase();
    void quitApp();
    void onTableClicked(const QModelIndex &index);
    void addNewElements();
    void toolsMySQLcmd();

private:
    QApplication *app;
    QPushButton *m_button;
    QTableView *view;
    QSqlQueryModel *model;
    QString addElementsQuery;
    QMenu *fileMenu;
    QMenu *addMenu;
    QMenu *toolsMenu;
    void setMenuBar();

};

#endif // MAINWINDOW_H
