#include "basketdialog.h"

BasketDialog::BasketDialog(QWidget *parent) :
    QDialog(parent), parentWidget(parent)
{
    proceedOrderButton = new QPushButton(tr("Proceed Order"));
    clearOrderButton = new QPushButton(tr("Clear Order"));
    cancelButton = new QPushButton(tr("Cancel"));

    outerLayout = new QVBoxLayout(this);
    topLayout = new QHBoxLayout();
    topLeftLayout = new QVBoxLayout();
    topRightLayout = new QVBoxLayout();
    bottomLayout = new QHBoxLayout();

    basketComponentsList = new QStringList();
    basketComponentsModel = new QStringListModel();
    basketComponentsView = new QListView();

    outerLayout->addLayout(topLayout);
    outerLayout->addLayout(bottomLayout);
    topLayout->addLayout(topLeftLayout);
    topLayout->addLayout(topRightLayout);

    bottomLayout->addWidget(proceedOrderButton);
    bottomLayout->addWidget(clearOrderButton);
    bottomLayout->addWidget(cancelButton);

    QVector<BasketComponent> basketComponents = Basket::getInstance().getBasketComponents();
//    QStringList list;
    for (auto it = basketComponents.begin(); it != basketComponents.end(); ++it) {
//        qDebug() << (*it).toString();
        (*basketComponentsList) << (*it).toString();
    }
//    QStringListModel *model = new QStringListModel();
    basketComponentsModel->setStringList(*basketComponentsList);
//    for (auto it = list.begin(); it != list.end(); ++it)
//        qDebug() << (*it);
//    QListView *listView = new QListView();

    connect(proceedOrderButton, SIGNAL(clicked(bool)), this, SLOT(proceedOrderButtonHandle()));
    connect(clearOrderButton, SIGNAL(clicked(bool)), this, SLOT(clearOrderButtonHanle()));
    connect(cancelButton, SIGNAL(clicked(bool)), this, SLOT(close()));

    basketComponentsView->setModel(basketComponentsModel);
    topLeftLayout->addWidget(basketComponentsView);

    connect(this,SIGNAL(dialogClosed()),this,SLOT(close()));
    this->resize(300,300);
    alignCenter<QDialog>(this);
    parentWidget->hide();
}

void BasketDialog::proceedOrderButtonHandle()
{
    Basket::getInstance().proceedOrder();
    close();

}

void BasketDialog::clearOrderButtonHanle()
{
    Basket::getInstance().clearBasket();
    basketComponentsList->erase(basketComponentsList->begin(),basketComponentsList->end());
    basketComponentsModel->setStringList(*basketComponentsList);
}


