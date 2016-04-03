#ifndef ADDTOBASKETDIALOG_H
#define ADDTOBASKETDIALOG_H

#include <QDialog>
#include <QPushButton>
#include <QLineEdit>
#include <QCompleter>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSqlQueryModel>
#include <QListView>
#include <dbconnector.h>

class addToBasketDialog : public QDialog
{
    Q_OBJECT
public:
    explicit addToBasketDialog(QWidget *parent = 0);

signals:

public slots:

private:
    QLabel *loadComponentLabel;
    QLabel *setQuantityLabel;
    QLabel *quantityErrorLabel;
    QPushButton *loadComponentButton;
    QPushButton *addToBasketButton;
    QLineEdit *loadComponentInput;
    QLineEdit *setQuantityInput;
    QCompleter *loadComponentCompleter;
    QHBoxLayout *outerLayout;
    QVBoxLayout *leftLayout;
    QVBoxLayout *rightLayout;
    QHBoxLayout *leftLoadComponentLayout;
    QHBoxLayout *leftSetQuantityLayout;
    QSqlQueryModel *model;
    QListView *view;
};

#endif // ADDTOBASKETDIALOG_H
