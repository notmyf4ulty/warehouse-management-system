#ifndef DBFROMFILE_H
#define DBFROMFILE_H

#include <QFile>

class dbFromFile
{
public:
    dbFromFile();
    bool addToTable(QFile file);
};

#endif // DBFROMFILE_H
