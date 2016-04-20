#ifndef MYSQLCMDDIALOG_H
#define MYSQLCMDDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QSqlQueryModel>
#include "dbconnector.h"
#include <QHBoxLayout>
#include <QLayout>

class MySQLcmdDialog : public QDialog
{
    Q_OBJECT
public:
    explicit MySQLcmdDialog(QWidget *parent = 0);

signals:

public slots:
    void promptHandle();

private:
    QLineEdit *prompt;
    QSqlQueryModel *model;
    QHBoxLayout *layout;
};

#endif // MYSQLCMDDIALOG_H
