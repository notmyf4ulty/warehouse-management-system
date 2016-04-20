#include "mysqlcmddialog.h"

MySQLcmdDialog::MySQLcmdDialog(QWidget *parent) :
    QDialog(parent), parentWidget(parent)
{
    this->setGeometry(0,0,400,50);
    model = &dbConnector::getInstance().getModel();
    prompt = new QLineEdit(this);
    connect(prompt, SIGNAL(returnPressed()), SLOT(promptHandle()));
    outerLayout = new QHBoxLayout(this);
    outerLayout->addWidget(prompt);

    connect(this,SIGNAL(dialogClosed()),this,SLOT(close()));
    alignCenter<QDialog>(this);
    parentWidget->hide();
    this->layout()->setSizeConstraint(QLayout::SetFixedSize);
}

void MySQLcmdDialog::promptHandle() {
    model->setQuery(prompt->text());
}
