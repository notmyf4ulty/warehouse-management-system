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

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
private slots:
    void handleButton();
    void handleTextInput();
private:
    QPushButton *m_button;
    QTableView *view;
    QSqlQueryModel *model;
    QLineEdit *textInput;
    QString addElementsQuery;
};

#endif // MAINWINDOW_H
