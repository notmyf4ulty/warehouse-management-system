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
#include <QLabel>
#include <QFileDialog>
#include <QString>
#include <QDebug>
#include <QMenu>
#include <QMenuBar>
#include <QApplication>
#include <QList>
#include <QComboBox>
#include <QModelIndex>
#include <QVector>
#include <QStatusBar>
#include "dbconnector.h"
#include "addcomponentdialog.h"
#include "basketdialog.h"
#include "basketcomponent.h"
#include "basket.h"
#include "mysqlcmddialog.h"
#include "adminlogindialog.h"
#include "geometry.h"

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
    void showComponentsTable();
    void adminLogin();

private:
    QApplication *app;
    QWidget *centralWidget;
    QTableView *view;
    QSqlQueryModel *model;
    const QModelIndex *currentTableIndex;
    Basket *basket;
//    QVector<Component> *basketComponents;
    QLabel *componentLabel;
    QLabel *setQuantityLabel;
    QLabel *setQuantityCommunicateLabel;
    QLineEdit *setQuantityInput;
    QString addElementsQuery;
    QComboBox *componentComboBox;
    QPushButton *addToBasketButton;
    QPushButton *openBasketButton;
    QMenu *fileMenu;
    QMenu *adminToolsMenu;
    QStatusBar *statusBar;
    QLabel *statusBarDbInfoPermanentLabel;
    QLabel *statusBarDbInfoModifableLabel;
    QVBoxLayout *outerLayout;
    QHBoxLayout *topLayout;
    QVBoxLayout *tableLayout;
    QHBoxLayout *bottomLayout;
    QVBoxLayout *bottomLeftLayout;
    QHBoxLayout *bottomLeftTopLayout;
    QHBoxLayout *statusBarLayout;
    void setMenuBar();
    QString getTableName();
    void eraseKeyFields();

};

#endif // MAINWINDOW_H
