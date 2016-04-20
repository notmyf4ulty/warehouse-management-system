#include "adminlogindialog.h"

AdminLoginDialog::AdminLoginDialog(QWidget *parent) :
    QDialog(parent)
{
    passInput = new QTextEdit();
    OKButton = new QPushButton("OK");
    layout = new QHBoxLayout();

    layout->addWidget(passInput);
    layout->addWidget(OKButton);
}
