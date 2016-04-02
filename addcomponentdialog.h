#ifndef ADDCOMPONENTDIALOG_H
#define ADDCOMPONENTDIALOG_H

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

class AddComponentDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddComponentDialog(QWidget *parent = 0);

private:
    QLabel *componentLabel;
    QLabel *codeLabel;
    QLabel *valueLabel;
    QLabel *packageLabel;
    QLabel *packageCaseLabel;
    QLabel *toleranceLabel;
    QLabel *powerLabel;
    QLabel *quantityLabel;
    QLineEdit *componentInput;
    QLineEdit *codeInput;
    QLineEdit *valueInput;
    QLineEdit *packageInput;
    QLineEdit *packageCaseInput;
    QLineEdit *toleranceInput;
    QLineEdit *powerInput;
    QLineEdit *quantityInput;
    QPushButton *addButton;
    QPushButton *cancelButton;
    QVBoxLayout *outerLayout;
    QHBoxLayout *componentInputLayout;
    QVBoxLayout *inputLayout;
    QVBoxLayout *labelLayout;
    QHBoxLayout *buttonsLayout;
//    QGridLayout *gridLayout;
    QSqlQueryModel *model;


private slots:
    void addButtonHandle();
};

#endif // ADDELEMENTSCREEN_H
