#include "component.h"

QString Component::getModel() const
{
    return model;
}

void Component::setModel(const QString &value)
{
    model = value;
}
int Component::getQuantity() const
{
    return quantity;
}

void Component::setQuantity(int value)
{
    quantity = value;
}



