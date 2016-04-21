#ifndef ADMINLOGINDIALOG_H
#define ADMINLOGINDIALOG_H

#include <QObject>
#include <QWidget>
#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include "geometry.h"
#include <QKeyEvent>
#include "admin.h"

class AdminLoginDialog : public QDialog
{
    Q_OBJECT
public:
    explicit AdminLoginDialog(QWidget *parent = 0);
signals:
    void dialogClosed();
    void adminPassed();
private slots:
    void passInputHandle();
private:
    bool isAdmin;
    QWidget *parentWidget;
    QLineEdit *passInput;
    QPushButton *OKButton;
    QHBoxLayout *outerLayout;
    void closeEvent(QCloseEvent *event) {parentWidget->show();
                                         emit dialogClosed();
                                         event->accept();}
};

#endif // ADMINLOGINDIALOG_H
