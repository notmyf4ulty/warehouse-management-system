#ifndef ADMINLOGINDIALOG_H
#define ADMINLOGINDIALOG_H

#include <QObject>
#include <QWidget>
#include <QDialog>
#include <QTextEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include "geometry.h"
#include <QKeyEvent>

class AdminLoginDialog : public QDialog
{
    Q_OBJECT
public:
    explicit AdminLoginDialog(QWidget *parent = 0);


signals:
    void dialogClosed();
private slots:
private:
    QWidget *parentWidget;
    QTextEdit *passInput;
    QPushButton *OKButton;
    QHBoxLayout *outerLayout;
    void closeEvent(QCloseEvent *event) {parentWidget->show();
                                         emit dialogClosed();
                                         event->accept();}
};

#endif // ADMINLOGINDIALOG_H
