#ifndef COMPONENT_H
#define COMPONENT_H

#include <QString>
#include "dbconnector.h"

//!  Klasa komponentu elektronciznego, który przechowywany będzie w koszyku.
/*!
  Zapewnia wszystkie niezbędne operacje do poprawnego działania aplikacji.
*/
class BasketComponent
{
public:
    //! Domyślny konstruktor.
    BasketComponent() = default;

    //! Konstruktor tworzący obiekt z określonych parametrów.
    BasketComponent(QString _code, QString _table, int _quantity) :
        code(_code), table(_table), quantity(_quantity) {}

    //! Domyślny destruktor.
    ~BasketComponent() {}

    /*!
     * \brief Funkcja zwracająca komponent w postaci QString'a.
     * \return postać QString.
     */
    QString toString();

    /*!
     * \brief Przeciążony operator porównujący
     * \param rhs Element, z którym komponent będzie porównywany.
     * \return "true" jeśli się zgadzają, "false" jeśli nie.
     */
    inline bool operator==(const BasketComponent& rhs) {
        return (code == rhs.getCode()) ? true : false;
    }

    /*!
     * \brief Przeciążony jednostronny operator dodawania.
     * \param rhs Komponent, który jest dodawany.
     * \return Referencja do aktualnego komponentu (this).
     */
    inline BasketComponent& operator+=(const BasketComponent& rhs) {
        quantity += rhs.getQuantity();
        return *this;
    }

    /*!
     * \brief Przeciążony jednostronny operator dodawania.
     * \param value wartość typu int, która dodana zostanie do ilości komponentów.
     * \return Referencja do aktualnego komponentu (this).
     */
    inline BasketComponent& operator+=(const int value) {
        quantity += value;
        return *this;
    }

    /*!
     * \brief Zwraca kod komponentu.
     * \return  Kod komponentu.
     */
    QString getCode() const;

    /*!
     * \brief Zmienia kod komponentu.
     * \param value Nowy kod komponentu.
     */
    void setCode(const QString &value);

    /*!
     * \brief zwraca nazwę tabeli, w której istnieje komponent.
     * \return nazwa tabeli komponentu.
     */
    QString getTable() const;

    /*!
     * \brief Zmienia nazwę tabeli, do której należy komponent.
     * \param value Nowa nazwa tabeli.
     */
    void setTable(const QString &value);

    /*!
     * \brief Zwraca ilość komponentów w koszyku.
     * \return Liczba komponentów w koszyku.
     */
    int getQuantity() const;

    /*!
     * \brief Zmienia ilość komponentów.
     * \param value Nowa ilość komponentów.
     */
    void setQuantity(int value);

private:
    QString code;
    QString table;
    int quantity;
};

#endif // COMPONENT_H
