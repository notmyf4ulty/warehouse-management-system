#ifndef ADDELEMENTSCREEN_H
#define ADDELEMENTSCREEN_H

#include <QObject>
#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include "dbconnector.h"

class AddElementDialog : public QDialog
{
public:
    AddElementDialog(QWidget *parent = 0);

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

private slots:
    bool addElements();
};

#endif // ADDELEMENTSCREEN_H
