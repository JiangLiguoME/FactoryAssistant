#include "product.h"

QString Barcode::get_code()
{
    return m_code;
}

QString Barcode::get_name()
{
    return m_name;
}
QStringList Goods::get_light()
{
    return m_light_num;
}
void Goods::add_light(QString light)
{
    m_light_num.append(light);
}

void Product::add_goods(QString goods_code)
{
    m_goods_list.append(goods_code);
}
void Product::add_goods(Goods goods)
{
    m_goods_list.append(goods.get_code());
}
QStringList Product::get_goods()
{
    return m_goods_list;
}
