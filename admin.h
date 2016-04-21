#ifndef ADMIN_H
#define ADMIN_H

#include <QString>

//!  Klasa zajmująca się obsługą trybu admina.
/*!
  Możliwe jest zalogowanie się (podanie odpowiedniego hasła) oraz zapytanie o stan trybu.
  Klasa stworzona wg wzorca Singleton.
*/
class Admin
{
public:
    //! Funkcja zwracająca instancję klasy.
    /*!
      Wzorzec nie pozwala na stworzenie więcej niż jednej instancji klasy - konstruktor jest niedostępny publicznie.
      Jedyna możliwość skorzystania z klasy to odwołanie się do opisywanej funkcji.
    */
    static Admin &getInstance() { static Admin instance; return instance;}

    //! Funkcja logująca.
    /*!
      Po podaniu odpowiedniego hasła zwraca "true" oraz zmienia stan trybu admina na włączony.
    */
    /*!
      \param _password Hasło do logowania.
    */
    bool login(QString _password);

    //! Funkcja zwracająca stan trybu admina.
    bool getPass();

private:
    Admin() {password = "1234", pass = false;}
    ~Admin() {}
    QString password;
    bool pass;
};

#endif // ADMIN_H
