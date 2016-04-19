#include "basketcomponent.h"

int BasketComponent::getQuantity() const
{
    return quantity;
}

void BasketComponent::setQuantity(int value)
{
    quantity = value;
}

QString BasketComponent::toString()
{
    return "" + code + ": " + QString::number(quantity);
}

QString BasketComponent::getCode() const
{
    return code;
}

void BasketComponent::setCode(const QString &value)
{
    code = value;
}

QString BasketComponent::getTable() const
{
    return table;
}

void BasketComponent::setTable(const QString &value)
{
    table = value;
}





