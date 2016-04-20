#include "basketdialog.h"

BasketDialog::BasketDialog(QWidget *parent) :
    QDialog(parent), parentWidget(parent)
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

    QVector<BasketComponent> basketComponents = Basket::getInstance().getBasketComponents();
    QStringList list;
    for (auto it = basketComponents.begin(); it != basketComponents.end(); ++it) {
        qDebug() << (*it).toString();
        list << (*it).toString();
    }
    QStringListModel *model = new QStringListModel();
    model->setStringList(list);
    for (auto it = list.begin(); it != list.end(); ++it)
        qDebug() << (*it);
    QListView *listView = new QListView();

    connect(proceedOrderButton, SIGNAL(clicked(bool)), this, SLOT(proceedOrderButtonHandle()));
    connect(cancelButton, SIGNAL(clicked(bool)), this, SLOT(close()));

    listView->setModel(model);
    topLeftLayout->addWidget(listView);

    connect(this,SIGNAL(dialogClosed()),this,SLOT(close()));
    this->resize(300,300);
    alignCenter<QDialog>(this);
    parentWidget->hide();
    this->layout()->setSizeConstraint(QLayout::SetFixedSize);
}

void BasketDialog::proceedOrderButtonHandle()
{
    Basket::getInstance().proceedOrder();
}


