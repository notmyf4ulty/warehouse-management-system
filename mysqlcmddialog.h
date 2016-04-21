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
#include <QRect>
#include <QString>

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
    QString oldQuery;
    QWidget *parentWidget;
    QLineEdit *prompt;
    QSqlQueryModel *model;
    QHBoxLayout *outerLayout;
    void closeEvent(QCloseEvent *event) {model->setQuery(oldQuery);
                                         emit dialogClosed();
                                         event->accept();}
};

#endif // MYSQLCMDDIALOG_H
