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
#include "dbconnector.h"
#include "addcomponentdialog.h"
#include "addtobasketdialog.h"
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
    QLabel *componentLabel;
    QVBoxLayout *outerLayout;
    QHBoxLayout *topLayout;
    QVBoxLayout *tableLayout;
    QHBoxLayout *bottomLayout;
    QString addElementsQuery;
    QComboBox *componentComboBox;
    QPushButton *addToBasketButton;
    QPushButton *openBasketButton;
    QMenu *fileMenu;
    QMenu *componentsMenu;
    QMenu *toolsMenu;
    void setMenuBar();

};

#endif // MAINWINDOW_H
