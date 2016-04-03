#ifndef BASKET_H
#define BASKET_H

#include <QVector>
#include <QStringList>
#include <QStringListModel>
#include "component.h"

class Basket
{
public:
    Basket();
    ~Basket() {}
    void addToBasket(const Component &component);
    QVector<Component> getBasketComponents() const;
    void setBasketComponents(const QVector<Component> &value);

private:
    QVector<Component> basketComponents;
    QStringList basketComponentsStringList;
    QStringListModel basketComponentsModel;
};

#endif // BASKET_H
