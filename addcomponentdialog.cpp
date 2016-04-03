#include "addcomponentdialog.h"

AddComponentDialog::AddComponentDialog(QWidget *parent) {
    //: QDialog(parent) {

    componentInput = new QLineEdit(this);
    codeInput = new QLineEdit(this);
    valueInput = new QLineEdit(this);
    packageInput = new QLineEdit(this);
    packageCaseInput = new QLineEdit(this);
    powerInput = new QLineEdit(this);
    toleranceInput = new QLineEdit(this);
    quantityInput = new QLineEdit(this);

    componentLabel = new QLabel(tr("Component"));
    codeLabel = new QLabel(tr("Code"));
    valueLabel = new QLabel(tr("Value"));
    packageLabel = new QLabel(tr("Package"));
    packageCaseLabel = new QLabel(tr("Case"));
    powerLabel = new QLabel(tr("Power"));
    toleranceLabel = new QLabel(tr("Tolerance"));
    quantityLabel = new QLabel(tr("Quantity"));

    addButton = new QPushButton(tr("Add"));
    connect(addButton, SIGNAL(clicked()), this, SLOT(addButtonHandle()));
    cancelButton = new QPushButton(tr("Cancel"));
    connect(addButton, SIGNAL(clicked()), this, SLOT(close()));

    outerLayout = new QVBoxLayout(this);
    componentInputLayout = new QHBoxLayout();
    inputLayout = new QVBoxLayout();
    labelLayout = new QVBoxLayout();
    buttonsLayout = new QHBoxLayout();

    outerLayout->addLayout(componentInputLayout);
    componentInputLayout->addLayout(labelLayout);
    componentInputLayout->addLayout(inputLayout);
    outerLayout->addLayout(buttonsLayout);

    inputLayout->addWidget(componentInput);
    inputLayout->addWidget(codeInput);
    inputLayout->addWidget(valueInput);
    inputLayout->addWidget(packageInput);
    inputLayout->addWidget(packageCaseInput);
    inputLayout->addWidget(powerInput);
    inputLayout->addWidget(toleranceInput);
    inputLayout->addWidget(quantityInput);

    labelLayout->addWidget(componentLabel);
    labelLayout->addWidget(codeLabel);
    labelLayout->addWidget(valueLabel);
    labelLayout->addWidget(packageLabel);
    labelLayout->addWidget(packageCaseLabel);
    labelLayout->addWidget(powerLabel);
    labelLayout->addWidget(toleranceLabel);
    labelLayout->addWidget(quantityLabel);

    buttonsLayout->addWidget(addButton);
    buttonsLayout->addWidget(cancelButton);

    model = &dbConnector::getInstance().getModel();
}

void AddComponentDialog::addButtonHandle()
{
    QString query = "";
    query += "INSERT INTO " + componentInput->text()
            + " (code, value, package, packageCase, tolerance, power, quantity) VALUES (\""
            + codeInput->text() + "\", \""
            + valueInput->text() + "\", \""
            + packageInput->text() + "\", \""
            + packageCaseInput->text() + "\", \""
            + powerInput->text() + "\", "
            + toleranceInput->text() + "\", \""
            + quantityInput->text() + ");";
    qDebug() << query << endl;
    model->setQuery(query);
}
