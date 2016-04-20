#ifndef ADDCOMPONENTDIALOG_H
#define ADDCOMPONENTDIALOG_H

#include <QObject>
#include <QDialog>
#include <QComboBox>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QSqlQueryModel>
#include <QString>
#include <QDebug>
#include <QLayout>
#include "dbconnector.h"
#include "basketcomponent.h"

class AddComponentDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddComponentDialog(QWidget *parent = 0);

private:
    QComboBox *componentChoice;

    QLabel *componentLabel;
    QLabel *codeLabel;
    QLabel *valueLabel;
    QLabel *typeLabel; // HERE
    QLabel *packageLabel;
    QLabel *packageCaseLabel;
    QLabel *toleranceLabel;
    QLabel *powerLabel;
    QLabel *voltageLabel; // HERE
    QLabel *moreInfoLabel; // HERE
    QLabel *quantityLabel;

    QLineEdit *componentInput;
    QLineEdit *codeInput;
    QLineEdit *valueInput;
    QLineEdit *typeInput; // HERE
    QLineEdit *packageInput;
    QLineEdit *packageCaseInput;
    QLineEdit *toleranceInput;
    QLineEdit *powerInput;
    QLineEdit *voltageInput; // HERE
    QLineEdit *moreInfoInput; // HERE
    QLineEdit *quantityInput;

    QPushButton *addButton;
    QPushButton *cancelButton;
    QVBoxLayout *outerLayout;
    QHBoxLayout *componentInputLayout;
    QVBoxLayout *inputLayout;
    QVBoxLayout *labelLayout;
    QHBoxLayout *buttonsLayout;
//    QGridLayout *gridLayout;
//    Component *component;
    QSqlQueryModel *model;

    void hideAll();
    void cleanInputs();
    void showDefaultProperties();
    void showResistorProperties();
    void showCapacitorProperties();
    void showTransistorProperties();
    QString addResistor();
    QString addCapacitor();
    QString addTransistor();

private slots:
    void addButtonHandle();
    void componentChoiceShowProperties();
};

#endif // ADDELEMENTSCREEN_H
