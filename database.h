#ifndef DATABASE_H
#define DATABASE_H

#include <QString>
#include <QMap>
#include <QFile>
#include "product.h"

class Database
{
public:
    Database()
    {
        m_workdir = "";
    }
    Database(QString workdir)
    {
        m_workdir = workdir;
    }
    QString get_file_name();
    void load_function();
    void load_products();
    void load_rules();
    void load_goods();
    void data_init();
    Product select_product_by_name(QString name);
    Product select_product_by_code(QString code);
    Goods select_goods_by_name(QString name);
    Goods select_goods_by_code(QString code);
    QString confirm_code;
private:
    QString m_workdir;
    QMap<QString,Product> product_container_by_name;
    QMap<QString,Product> product_container_by_code;
    QMap<QString,Goods> goods_container_by_name;
    QMap<QString,Goods> goods_container_by_code;
    QMap<QString,QString> function;
};

#endif // DATABASE_H
