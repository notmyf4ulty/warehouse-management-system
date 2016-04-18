#ifndef BASKET_H
#define BASKET_H

#include <QVector>
#include <QStringList>
#include <QStringListModel>
#include "component.h"

class Basket
{
public:
    void addToBasket(const Component &component);
    QVector<Component> &getBasketComponents() {return basketComponents;}
    static Basket &getInstance() { static Basket instance; return instance; }

private:
    Basket();
    ~Basket() {}
    QVector<Component> basketComponents;
    QStringList basketComponentsStringList;
    QStringListModel basketComponentsModel;
};

#endif // BASKET_H
