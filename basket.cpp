#include "basket.h"

Basket::Basket()
{
}

void Basket::addToBasket(const Component &component)
{
    if (basketComponents.contains(component)) {
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

//QVector<Component> &Basket::getBasketComponents()
//{
//    return basketComponents;
//}

