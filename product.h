#ifndef PRODUCT_H
#define PRODUCT_H

#include <QString>
#include <QMap>
#include <QStringList>

class Barcode
{
public:
    Barcode()
    {
        m_code = "";
        m_name = "";
    }
    Barcode(QString code)
    {
        m_code = code;
        m_name = "";
    }
    Barcode(QString name, QString code)
    {
        m_code = code;
        m_name = name;
    }
    QString get_name();
    QString get_code();

private:
    QString m_name;
    QString m_code;
};

class Goods:public Barcode
{
public:
    Goods():Barcode(){}
    Goods(QString code):Barcode(code){}
    Goods(QString name,QString code):Barcode(name,code){}
    QStringList get_light();
    void add_light(QString light);

private:
    QStringList m_light_num;
};

class Product:public Barcode
{
public:
    Product():Barcode() {}
    Product(QString code):Barcode(code){}
    Product(QString name,QString code):Barcode(name,code){}
    void add_goods(QString goods_code);
    void add_goods(Goods goods);
    QStringList get_goods();

private:
    QStringList m_goods_list;
};

#endif // PRODUCT_H
