#ifndef BASKET_H
#define BASKET_H

#include <QVector>
#include <QStringList>
#include <QStringListModel>
#include <QtAlgorithms>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include "basketcomponent.h"
#include <QDebug>

//!  Klasa tworząca tzw. "koszyk zakupów".
/*!
  Tworzy "koszyk", w którym umieszczać można wybrane komponenty. Klasa stworzona wg wzorca Singleton.
  Posiada kontener typu "vector", w którym przechowywane są dodane przez użytkownika komponenty, a także kontener typu
  "list" przechowujący obiekty typu QString (QStringList - specjalny kontener Qt).
*/
class Basket
{
public:
    //! Funkcja zwracająca instancję klasy.
    /*!
      Wzorzec nie pozwala na stworzenie więcej niż jednej instancji klasy - konstruktor jest niedostępny publicznie.
      Jedyna możliwość skorzystania z klasy to odwołanie się do opisywanej funkcji.
    */
    static Basket &getInstance() { static Basket instance; return instance;}

    //! Funkcja dodająca komponent do koszyka. Podczas dodawania sprawdzany jest typ komponentu -
    //! jeżeli takowy znajduje się już w koszyku, doliczana jest tylko kolejna ilość.
    /*!
      \param component Obiekt klasy "Component", który zostanie dodany do koszyka.
    */
    void addToBasket(const BasketComponent &component);

    //! Funkcja kończąca zamówienie. Do modelu bazy danych wysyłane jest zapytanie zmieniające ilosć określonych w koszyku komponentów.
    void proceedOrder();

    void clearBasket();

    //! Funkcja zwracająca referencję do koszyka (wektora) z komponentami.
    QVector<BasketComponent> &getBasketComponents() {return basketComponents;}

private:
    Basket();
    ~Basket() {}
    bool inBasket (const BasketComponent &component);
    QVector<BasketComponent> basketComponents;
    QStringList basketComponentsStringList;
    QStringListModel basketComponentsModel;
    QSqlQueryModel *queryModel;
};

#endif // BASKET_H
