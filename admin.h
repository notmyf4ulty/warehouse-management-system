#ifndef ADMIN_H
#define ADMIN_H

#include <QString>

class Admin
{
public:
    static Admin &getInstance() { static Admin instance; return instance;}
    bool login(QString _password);
    bool getPass();

private:
    Admin() {password = "1234", pass = false;}
    ~Admin() {}
    QString password;
    bool pass;
};

#endif // ADMIN_H
