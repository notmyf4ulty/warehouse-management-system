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
#include "addelementscreen.h"

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
    void onTableClicked(const QModelIndex &index);
    void addNewElements();
private:
    QApplication *app;

    QPushButton *m_button;
    QTableView *view;
    QSqlQueryModel *model;
    QLineEdit *textInput;
    QString addElementsQuery;
    QMenu *fileMenu;
    QMenu *helpMenu;
    QMenu *addMenu;


    void setMenuBar();

};

#endif // MAINWINDOW_H
