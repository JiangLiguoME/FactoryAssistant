#ifndef INPUTPROCESS_H
#define INPUTPROCESS_H

#include <QString>
#include <QStringList>

#include "database.h"

class InputProcess
{
public:
    InputProcess()
    {
        ;
    }
    InputProcess(Database database)
    {
        db = database;
    }
    void judge(QString input_string);
private:
    Database db;
    Product product;
    QStringList goods_code_list;
    QString code_type(QString input_string);
};

#endif // INPUTPROCESS_H
