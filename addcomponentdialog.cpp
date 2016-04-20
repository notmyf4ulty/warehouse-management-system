#include "addcomponentdialog.h"

AddComponentDialog::AddComponentDialog(QWidget *parent) :
    QDialog(parent), parentWidget(parent)
{
    componentChoice = new QComboBox(this);

    codeInput = new QLineEdit(this);
    valueInput = new QLineEdit(this);
    typeInput = new QLineEdit(this);
    packageInput = new QLineEdit(this);
    packageCaseInput = new QLineEdit(this);
    powerInput = new QLineEdit(this);
    voltageInput = new QLineEdit(this);
    moreInfoInput = new QLineEdit(this);
    toleranceInput = new QLineEdit(this);
    quantityInput = new QLineEdit(this);

    codeLabel = new QLabel(tr("Code"));
    valueLabel = new QLabel(tr("Value"));
    typeLabel = new QLabel(tr("Type"));
    packageLabel = new QLabel(tr("Package"));
    packageCaseLabel = new QLabel(tr("Case"));
    powerLabel = new QLabel(tr("Power"));
    voltageLabel = new QLabel(tr("Voltage"));
    moreInfoLabel = new QLabel(tr("More Info"));
    toleranceLabel = new QLabel(tr("Tolerance"));
    quantityLabel = new QLabel(tr("Quantity"));

    addButton = new QPushButton(tr("Add"));
    connect(addButton, SIGNAL(clicked()), this, SLOT(addButtonHandle()));
    cancelButton = new QPushButton(tr("Cancel"));
    connect(cancelButton, SIGNAL(clicked()), this, SLOT(close()));

    outerLayout = new QVBoxLayout(this);
    componentInputLayout = new QHBoxLayout();
    inputLayout = new QVBoxLayout();
    labelLayout = new QVBoxLayout();
    buttonsLayout = new QHBoxLayout();

    hideAll();

    addButton->setEnabled(false);

    componentChoice->addItem(tr("<none>"));
    componentChoice->addItem(tr("Resistor"));
    componentChoice->addItem(tr("Capacitor"));
    componentChoice->addItem(tr("Transistor"));
    connect(componentChoice, SIGNAL(currentIndexChanged(int)), this, SLOT(componentChoiceShowProperties()));

    outerLayout->addWidget(componentChoice);
    outerLayout->addLayout(componentInputLayout);
    componentInputLayout->addLayout(labelLayout);
    componentInputLayout->addLayout(inputLayout);
    outerLayout->addLayout(buttonsLayout);

    inputLayout->addWidget(codeInput);
    inputLayout->addWidget(valueInput);
    inputLayout->addWidget(typeInput);
    inputLayout->addWidget(packageInput);
    inputLayout->addWidget(packageCaseInput);
    inputLayout->addWidget(toleranceInput);
    inputLayout->addWidget(powerInput);
    inputLayout->addWidget(voltageInput);
    inputLayout->addWidget(moreInfoInput);
    inputLayout->addWidget(quantityInput);

    labelLayout->addWidget(componentLabel);
    labelLayout->addWidget(codeLabel);
    labelLayout->addWidget(valueLabel);
    labelLayout->addWidget(typeLabel);
    labelLayout->addWidget(packageLabel);
    labelLayout->addWidget(packageCaseLabel);
    labelLayout->addWidget(toleranceLabel);
    labelLayout->addWidget(powerLabel);
    labelLayout->addWidget(voltageLabel);
    labelLayout->addWidget(moreInfoLabel);
    labelLayout->addWidget(quantityLabel);

    buttonsLayout->addWidget(addButton);
    buttonsLayout->addWidget(cancelButton);

    model = &dbConnector::getInstance().getModel();

    connect(this,SIGNAL(dialogClosed()),this,SLOT(close()));
    this->adjustSize();
    alignCenter<QDialog>(this);
    parentWidget->hide();
//    this->layout()->setSizeConstraint(QLayout::SetFixedSize);
    this->layout()->setSizeConstraint(QLayout::SetFixedSize);
}

void AddComponentDialog::hideAll()
{
    codeInput->hide();
    valueInput->hide();
    typeInput->hide();
    packageInput->hide();
    packageCaseInput->hide();
    powerInput->hide();
    voltageInput->hide();
    moreInfoInput->hide();
    toleranceInput->hide();
    quantityInput->hide();

    codeLabel->hide();
    valueLabel->hide();
    typeLabel->hide();
    packageLabel->hide();
    packageCaseLabel->hide();
    powerLabel->hide();
    voltageLabel->hide();
    moreInfoLabel->hide();
    toleranceLabel->hide();
    quantityLabel->hide();
}

void AddComponentDialog::cleanInputs()
{
    codeInput->setText("");
    valueInput->setText("");
    typeInput->setText("");
    packageInput->setText("");
    packageCaseInput->setText("");
    powerInput->setText("");
    voltageInput->setText("");
    moreInfoInput->setText("");
    toleranceInput->setText("");
    quantityInput->setText("");
}

void AddComponentDialog::showDefaultProperties()
{
    codeInput->show();
    packageInput->show();
    packageCaseInput->show();
    moreInfoInput->show();
    quantityInput->show();

    codeLabel->show();
    packageLabel->show();
    packageCaseLabel->show();
    moreInfoLabel->show();
    quantityLabel->show();
}

void AddComponentDialog::showResistorProperties()
{
    hideAll();
    showDefaultProperties();

    valueInput->show();
    powerInput->show();
    toleranceInput->show();

    valueLabel->show();
    powerLabel->show();
    toleranceLabel->show();
}

void AddComponentDialog::showCapacitorProperties()
{
    hideAll();
    showDefaultProperties();

    valueInput->show();
    voltageInput->show();
    toleranceInput->show();

    valueLabel->show();
    voltageLabel->show();
    toleranceLabel->show();
}

void AddComponentDialog::showTransistorProperties()
{
    hideAll();
    showDefaultProperties();

    typeInput->show();

    typeLabel->show();
}

QString AddComponentDialog::addResistor()
{
    QString query = "";
    query += "INSERT INTO resistor (code, value, package, packageCase, tolerance, power, quantity, moreInfo) VALUES (\""
            + codeInput->text() + "\", \""
            + valueInput->text() + "\", \""
            + packageInput->text() + "\", \""
            + packageCaseInput->text() + "\", \""
            + toleranceInput->text() + "\", \""
            + powerInput->text() + "\", "
            + quantityInput->text() +  ", \""
            + moreInfoInput->text() + "\");";
    return query;
}

QString AddComponentDialog::addCapacitor()
{
    QString query = "";
    query += "INSERT INTO capacitor (code, value, package, packageCase, tolerance, voltage, quantity, moreInfo) VALUES (\""
            + codeInput->text() + "\", \""
            + valueInput->text() + "\", \""
            + packageInput->text() + "\", \""
            + packageCaseInput->text() + "\", \""
            + toleranceInput->text() + "\", \""
            + voltageInput->text() + "\", "
            + quantityInput->text() +  ", \""
            + moreInfoInput->text() + "\");";
    return query;
}

QString AddComponentDialog::addTransistor()
{
    QString query = "";
    query += "INSERT INTO transistor (code, type, package, packageCase, quantity, moreInfo) VALUES (\""
            + codeInput->text() + "\", \""
            + typeInput->text() + "\", \""
            + packageInput->text() + "\", \""
            + packageCaseInput->text() + "\", "
            + quantityInput->text() +  ", \""
            + moreInfoInput->text() + "\");";
    return query;
}

void AddComponentDialog::addButtonHandle()
{
    QString query = "";
    switch(componentChoice->currentIndex()) {
    case 1:
        query = addResistor();
        break;
    case 2:
        query = addCapacitor();
        break;
    case 3:
        query = addTransistor();
        break;
    default:
        break;
    }
    qDebug() << query << endl;
    model->setQuery(query);
}

void AddComponentDialog::componentChoiceShowProperties()
{
    addButton->setEnabled(true);

    switch(componentChoice->currentIndex()) {
    case 0:
        hideAll();
        cleanInputs();
        addButton->setEnabled(false);
        break;
    case 1:
        showResistorProperties();
        cleanInputs();
        break;
    case 2:
        showCapacitorProperties();
        cleanInputs();
        break;
    case 3:
        showTransistorProperties();
        cleanInputs();
        break;
    default:
        hideAll();
        cleanInputs();
        break;
    }

    this->adjustSize();
}
