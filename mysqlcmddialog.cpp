#include "mysqlcmddialog.h"

MySQLcmdDialog::MySQLcmdDialog(QWidget *parent) :
    QDialog(parent)
{
    this->setGeometry(0,0,400,50);
    model = &dbConnector::getInstance().getModel();
    prompt = new QLineEdit(this);
    connect(prompt, SIGNAL(returnPressed()), SLOT(promptHandle()));
    layout = new QHBoxLayout(this);
    layout->addWidget(prompt);
}

void MySQLcmdDialog::promptHandle() {
    model->setQuery(prompt->text());
}
