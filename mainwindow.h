#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QObject>
#include <QMainWindow>
#include <QPushButton>
#include <QTableView>
#include <QSqlQueryModel>
#include <QBoxLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QWidget>
#include <QLineEdit>
#include <QFileDialog>
#include <QString>
#include <QDebug>
#include <QMenu>
#include <QMenuBar>
#include <QApplication>
#include <QList>
#include "dbconnector.h"
#include "addcomponentdialog.h"
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
    void addNewComponent();
    void toolsMySQLcmd();
    void addToBasketButtonHandle();
    void openBasketButtonHandle();

private:
    QApplication *app;
    QWidget *centralWidget;
    QTableView *view;
    QSqlQueryModel *model;
    QVBoxLayout *outerLayout;
    QVBoxLayout *topLayout;
    QHBoxLayout *bottomLayout;
    QString addElementsQuery;
    QPushButton *addToBasketButton;
    QPushButton *openBasketButton;
    QMenu *fileMenu;
    QMenu *addMenu;
    QMenu *toolsMenu;
    void setMenuBar();

};

#endif // MAINWINDOW_H
