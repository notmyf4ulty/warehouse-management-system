#ifndef ADMINLOGINDIALOG_H
#define ADMINLOGINDIALOG_H

#include <QTextEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QDialog>

class AdminLoginDialog : public QDialog
{
    Q_OBJECT
public:
//    static AdminLoginDialog &getInstance() { static AdminLoginDialog instance; return instance;}
//private:
    AdminLoginDialog(QWidget *parent);
private:
    QTextEdit *passInput;
    QPushButton *OKButton;
    QHBoxLayout *layout;
};

#endif // ADMINLOGINDIALOG_H
