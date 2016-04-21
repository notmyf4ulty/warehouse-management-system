#include "mysqlcmddialog.h"

MySQLcmdDialog::MySQLcmdDialog(QWidget *parent) :
    QDialog(parent), parentWidget(parent)
{
    model = &dbConnector::getInstance().getModel();
    prompt = new QLineEdit(this);
    connect(prompt, SIGNAL(returnPressed()), SLOT(promptHandle()));
    outerLayout = new QHBoxLayout(this);
    outerLayout->addWidget(prompt);

    connect(this,SIGNAL(dialogClosed()),this,SLOT(close()));
    this->resize(500,50);
    alignCenter<QDialog>(this);

    oldQuery = model->query().executedQuery();
}

void MySQLcmdDialog::promptHandle() {
    model->setQuery(prompt->text());
}
