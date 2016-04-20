#include "adminlogindialog.h"

AdminLoginDialog::AdminLoginDialog(QWidget *parent) :
    QDialog(parent), parentWidget(parent)
{
    passInput = new QTextEdit();
    OKButton = new QPushButton("OK");
    outerLayout = new QHBoxLayout(this);

    outerLayout->addWidget(passInput);
    outerLayout->addWidget(OKButton);

    connect(this,SIGNAL(dialogClosed()),this,SLOT(close()));
    alignCenter<QDialog>(this);
    parentWidget->hide();
    this->layout()->setSizeConstraint(QLayout::SetFixedSize);
}
