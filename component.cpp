#include "component.h"

QString Component::getModel() const
{
    return code;
}

void Component::setModel(const QString &value)
{
    code = value;
}
int Component::getQuantity() const
{
    return quantity;
}

void Component::setQuantity(int value)
{
    quantity = value;
}

QString Component::componentTypeToString()
{
    QString result;
    switch (type) {
    case Component::componentType::RESISTOR:
        result = "Resistor";
        break;
    case Component::componentType::CAPACITOR:
        result = "Capacitor";
        break;
    case Component::componentType::TRANSISTOR:
        result = "Transistor";
        break;
    default:
        result = "noType";
        break;
    }
    return result;
}

QString Component::toString()
{
    return componentTypeToString() + " " + code + ": " + QString::number(quantity);
}
Component::componentType Component::getType() const
{
    return type;
}

void Component::setType(const componentType &value)
{
    type = value;
}




