#include "basketdialog.h"

BasketDialog::BasketDialog(QWidget *parent) :
    QDialog(parent)
{
    proceedOrderButton = new QPushButton(tr("Proceed Order"));
    cancelButton = new QPushButton(tr("Cancel"));

    outerLayout = new QVBoxLayout(this);
    topLayout = new QHBoxLayout();
    topLeftLayout = new QVBoxLayout();
    topRightLayout = new QVBoxLayout();
    bottomLayout = new QHBoxLayout();

    outerLayout->addLayout(topLayout);
    outerLayout->addLayout(bottomLayout);
    topLayout->addLayout(topLeftLayout);
    topLayout->addLayout(topRightLayout);

    bottomLayout->addWidget(proceedOrderButton);
    bottomLayout->addWidget(cancelButton);
}
