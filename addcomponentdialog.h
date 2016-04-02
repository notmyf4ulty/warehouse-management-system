#ifndef ADDELEMENTSCREEN_H
#define ADDELEMENTSCREEN_H

#include <QObject>
#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QSqlQueryModel>
#include <QString>
#include <QDebug>
#include "dbconnector.h"

class AddElementDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddElementDialog(QWidget *parent = 0);

private:
    QLabel *modelLabel;
    QLabel *packageLabel;
    QLabel *quantityLabel;
    QLabel *communicateLabel;
    QLineEdit *modelInput;
    QLineEdit *packageInput;
    QLineEdit *quantityInput;
    QPushButton *addButton;
    QPushButton *cancelButton;
    QGridLayout *gridLayout;
    QSqlQueryModel *model;

private slots:
    void addButtonHandle();
};

#endif // ADDELEMENTSCREEN_H
