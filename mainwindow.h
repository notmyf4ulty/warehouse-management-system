#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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
#include "dbconnector.h"

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
    void handleTextInput();
    void configureDatabase();
    void quitApp();
private:
    QApplication *app;

    QPushButton *m_button;
    QTableView *view;
    QSqlQueryModel *model;
    QLineEdit *textInput;
    QString addElementsQuery;
    QMenu *fileMenu;
    QMenu *helpMenu;
    dbConnector *db;

    void setMenuBar();

};

#endif // MAINWINDOW_H
