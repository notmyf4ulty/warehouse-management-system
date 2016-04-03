#ifndef COMPONENT_H
#define COMPONENT_H

#include <QString>

class Component
{
public:
    enum componentType {
        RESISTOR,
        CAPACITOR,
        TRANSISTOR
    };

    Component();
    Component(componentType _type, QString _model, int _quantity)
        : type(_type), model(_model), quantity(_quantity) {}
    Component(const Component &component)
        : type(component.getType()), model(component.getModel()), quantity(component.getQuantity()) {}

    componentType getType() const;
    void setType(const componentType &value);

    QString getModel() const;
    void setModel(const QString &value);

    int getQuantity() const;
    void setQuantity(int value);

private:
    componentType type;
    QString model;
    int quantity;
};



#endif // COMPONENT_H
