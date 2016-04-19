#include "basket.h"

Basket::Basket()
{
    queryModel = &dbConnector::getInstance().getModel();
}

bool Basket::inBasket(const BasketComponent &component)
{
    auto it = qFind(basketComponents.begin(), basketComponents.end(), component);
    return (it == basketComponents.end()) ? false : true;
}

void Basket::addToBasket(const BasketComponent &component)
{
    if (inBasket(component)) {
        auto basketComponentsIterator = basketComponents.begin();
        auto basketComponentsStringListIterator = basketComponentsStringList.begin();
        int componentIndex = basketComponents.indexOf(component);
        basketComponentsIterator += componentIndex;
        basketComponentsStringListIterator += componentIndex;
        *basketComponentsIterator += component;
        *basketComponentsStringListIterator;
    }
    else
        basketComponents.push_back(component);
}

void Basket::proceedOrder()
{
    QString query = "";
    for(auto it = basketComponents.begin(); it != basketComponents.end(); ++it)
    {
        query = "UPDATE "
                + (*it).getTable()
                + " SET quantity = quantity - "
                + QString::number((*it).getQuantity())
                + " WHERE code = "
                + "\"" + (*it).getCode() + "\""
                + ";";
        queryModel->setQuery(query);
        query = "";
        //basketComponents.erase(basketComponents.begin(), basketComponents.end());
    }
}


