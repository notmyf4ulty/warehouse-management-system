#include "addtobasketdialog.h"

AddToBasketDialog::AddToBasketDialog(QWidget *parent) :
    QDialog(parent)
{
    loadComponentLabel = new QLabel(tr("Load component"));
    setQuantityLabel = new QLabel(tr("Set Quantity"));
    quantityErrorLabel = new QLabel();

    loadComponentButton = new QPushButton(tr("Load component"));
    addToBasketButton = new QPushButton(tr("Add to basket"));

    loadComponentInput = new QLineEdit();
    setQuantityInput = new QLineEdit();

    model = &dbConnector::getInstance().getModel();
    loadComponentCompleter = new QCompleter(model);

    view = new QListView();

    outerLayout = new QHBoxLayout(this);
    leftLayout = new QVBoxLayout();
    rightLayout = new QVBoxLayout();
    leftLoadComponentLayout = new QHBoxLayout();
    leftSetQuantityLayout = new QHBoxLayout();

    loadComponentCompleter->setCompletionColumn(0);
    loadComponentCompleter->setCaseSensitivity(Qt::CaseInsensitive);
    loadComponentInput->setCompleter(loadComponentCompleter);

    view->setModel(model);

    outerLayout->addLayout(leftLayout);
    outerLayout->addLayout(rightLayout);

    leftLayout->addLayout(leftLoadComponentLayout);
    leftLayout->addLayout(leftSetQuantityLayout);

    leftLoadComponentLayout->addWidget(loadComponentLabel);
    leftLoadComponentLayout->addWidget(loadComponentInput);
    leftLoadComponentLayout->addWidget(loadComponentButton);

    leftSetQuantityLayout->addWidget(setQuantityLabel);
    leftSetQuantityLayout->addWidget(setQuantityInput);

    leftLayout->addWidget(addToBasketButton);

    rightLayout->addWidget(view);
}
