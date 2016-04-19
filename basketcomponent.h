#ifndef COMPONENT_H
#define COMPONENT_H

#include <QString>
#include "dbconnector.h"

class BasketComponent
{
public:
    BasketComponent() = default;
    BasketComponent(QString _code, QString _table, int _quantity) :
        code(_code), table(_table), quantity(_quantity) {}
    ~BasketComponent() {}

    QString toString();

    inline bool operator==(const BasketComponent& rhs) {
        return (code == rhs.getCode()) ? true : false;
    }

    inline BasketComponent& operator+=(const BasketComponent& rhs) {
        quantity += rhs.getQuantity();
        return *this;
    }

    inline BasketComponent& operator+=(const int value) {
        quantity += value;
        return *this;
    }

    QString getCode() const;
    void setCode(const QString &value);

    QString getTable() const;
    void setTable(const QString &value);

    int getQuantity() const;
    void setQuantity(int value);

private:
    QString code;
    QString table;
    int quantity;
};

#endif // COMPONENT_H
