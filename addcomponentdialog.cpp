#include "addelementdialog.h"

AddElementDialog::AddElementDialog(QWidget *parent) {
    //: QDialog(parent) {

    modelInput = new QLineEdit();
    packageInput = new QLineEdit();
    quantityInput = new QLineEdit();

    modelLabel = new QLabel(tr("Model"));
    packageLabel = new QLabel(tr("Package"));
    quantityLabel = new QLabel(tr("Quantity"));

    addButton = new QPushButton(tr("Add"));
    connect(addButton, SIGNAL(clicked()), this, SLOT(addButtonHandle()));
    cancelButton = new QPushButton(tr("Cancel"));

    gridLayout = new QGridLayout(this);
    gridLayout->addWidget(modelInput,0,0);
    gridLayout->addWidget(packageInput,0,1);
    gridLayout->addWidget(quantityInput,0,2);
    gridLayout->addWidget(modelLabel,1,0);
    gridLayout->addWidget(packageLabel,1,1);
    gridLayout->addWidget(quantityLabel,1,2);
    gridLayout->addWidget(addButton,2,0);
    gridLayout->addWidget(cancelButton,2,1);

    model = &dbConnector::getInstance().getModel();
}

void AddElementDialog::addButtonHandle()
{
    QString query = "";
    query += "INSERT INTO component (model, package, quantity) VALUES (\"" + modelInput->text().toUpper() + "\", \"" + packageInput->text().toUpper();
    query += "\", " + quantityInput->text();
    query += ");";
    model->setQuery(query);
}