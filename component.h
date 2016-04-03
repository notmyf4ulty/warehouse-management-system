#ifndef COMPONENT_H
#define COMPONENT_H

#include <QString>

class Component
{
public:
    enum class componentType {
        RESISTOR,
        CAPACITOR,
        TRANSISTOR
    };

    Component() = default;
    Component(componentType _type, QString _code, int _quantity)
        : type(_type), code(_code), quantity(_quantity) {}
//    Component(const Component &component)
//        : type(component.getType()),
//          code(component.getModel()),
//          quantity(component.getQuantity()) {}
    ~Component() {}

    componentType getType() const;
    void setType(const componentType &value);

    QString getModel() const;
    void setModel(const QString &value);

    int getQuantity() const;
    void setQuantity(int value);

    QString componentTypeToString();
    QString toString();

    inline bool operator==(const Component& rhs) {
        return ((type == rhs.type) && (code == rhs.code)) ? true : false;}

    inline Component& operator+=(const Component& rhs) {
        quantity += rhs.getQuantity();
        return *this;
    }

    inline Component& operator+=(const int value) {
        quantity += value;
        return *this;
    }



private:
    componentType type;
    QString code;
    int quantity;
};

#endif // COMPONENT_H
