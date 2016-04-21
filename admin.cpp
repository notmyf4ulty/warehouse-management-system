#include "admin.h"

bool Admin::login(QString _password)
{
    bool result = false;
    if (_password  == password)
    {
        pass = true;
        result = true;
    }
    return result;
}

bool Admin::getPass()
{
    return pass;
}
