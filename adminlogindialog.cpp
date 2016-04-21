#include "adminlogindialog.h"

AdminLoginDialog::AdminLoginDialog(QWidget *parent) :
    QDialog(parent), parentWidget(parent)
{
    isAdmin = false;
    passInput = new QLineEdit();
    outerLayout = new QHBoxLayout(this);

    passInput->setEchoMode(QLineEdit::EchoMode::Password);
    connect(passInput, SIGNAL(returnPressed()), SLOT(passInputHandle()));
    outerLayout->addWidget(passInput);

    this->resize(300,50);
    connect(this,SIGNAL(dialogClosed()),this,SLOT(close()));
    alignCenter<QDialog>(this);
    parentWidget->hide();
}

void AdminLoginDialog::passInputHandle()
{
    Admin::getInstance().login(passInput->text());
    close();
}
