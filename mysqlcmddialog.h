#ifndef MYSQLCMDDIALOG_H
#define MYSQLCMDDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QSqlQueryModel>
#include "dbconnector.h"
#include <QHBoxLayout>
#include <QLayout>
#include "geometry.h"
#include <QKeyEvent>

class MySQLcmdDialog : public QDialog
{
    Q_OBJECT
public:
    explicit MySQLcmdDialog(QWidget *parent = 0);

signals:
    void dialogClosed();

public slots:
    void promptHandle();

private:
    QWidget *parentWidget;
    QLineEdit *prompt;
    QSqlQueryModel *model;
    QHBoxLayout *outerLayout;
    void closeEvent(QCloseEvent *event) {parentWidget->show();
                                         emit dialogClosed();
                                         event->accept();}
};

#endif // MYSQLCMDDIALOG_H
