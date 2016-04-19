#ifndef BASKET_H
#define BASKET_H

#include <QVector>
#include <QStringList>
#include <QStringListModel>
#include <QtAlgorithms>
#include <QSqlQueryModel>
#include "basketcomponent.h"

#include <QDebug>

class Basket
{
public:
    void addToBasket(const BasketComponent &component);
    void proceedOrder();
    QVector<BasketComponent> &getBasketComponents() {return basketComponents;}
    static Basket &getInstance() { static Basket instance; return instance;}

private:
    Basket();
    ~Basket() {}
    bool inBasket (const BasketComponent &component);

    QVector<BasketComponent> basketComponents;
    QStringList basketComponentsStringList;
    QStringListModel basketComponentsModel;
    QSqlQueryModel *queryModel;
};

#endif // BASKET_H
