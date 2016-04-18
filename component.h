#ifndef COMPONENT_H
#define COMPONENT_H

#include <QString>
#include "dbconnector.h"

class Component
{
public:
    enum class componentType {
        RESISTOR,
        CAPACITOR,
        TRANSISTOR
    };

    Component() = default;
    Component(QString _code,
              QString _package,
              QString _packageCase,
              int _quantity,
              QString _moreInfo)
        : code(_code),
          package(_package),
          packageCase(_packageCase),
          quantity(_quantity),
          moreInfo(_moreInfo) {}
    ~Component() {}

    componentType getType() const;
    void setType(const componentType &value);

    QString getModel() const;
    void setModel(const QString &value);

    int getQuantity() const;
    void setQuantity(int value);

    QString componentTypeToString();
    QString toString();
    QString componentTypeToQuery();
    QString toQuery();

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



protected:
    componentType type;
//    QString code;
//    int quantity;
    QString code;
    QString package;
    QString packageCase;
    int quantity;
    QString moreInfo;

};

#endif // COMPONENT_H
