#include "database.h"
#include <QByteArray>
#include <QTextCodec>

QString Database::get_file_name()
{
    QString file_path= m_workdir+"/功能.csv";
    QFile file(file_path);
    if(file.open(QFile::ReadOnly))
    {
        file.readLine();
        while (!file.atEnd()) {
            QString str = QTextCodec::codecForName("GBK")->toUnicode(file.readLine());
            return str;
        }
    }
    return file_path;
}

void Database::load_function()
{
    QString file_path= m_workdir+"/功能.csv";
    QFile file(file_path);
    QString line;
    QString name;
    QString code;
    QStringList data;

    if(file.open(QFile::ReadOnly))
    {
        file.readLine();
        while (!file.atEnd()) {
            line = QTextCodec::codecForName("GBK")->toUnicode(file.readLine());
            data = line.split(',');
            name = data.at(0);
            code = data.at(1);
            function.insert(name,code);
        }
    }
}

void Database::load_goods()
{
    QString file_path= m_workdir+"/物品.csv";
    QFile file(file_path);
    QString line;
    QString name;
    QString code;
    QStringList data;

    if(file.open(QFile::ReadOnly))
    {
        file.readLine();
        while (!file.atEnd()) {
            line = QTextCodec::codecForName("GBK")->toUnicode(file.readLine());
            data = line.split(',');
            name = data.at(0);
            code = data.at(1);
            Goods goods(name,code);
            goods_container_by_code.insert(code,goods);
            goods_container_by_name.insert(name,goods);
        }
    }
}

void Database::load_rules()
{
    QString file_path= m_workdir+"/对应关系.csv";
    QFile file(file_path);
    QString line;
    QString product_name;
    QString goods_name_string;
    QStringList goods_name_list;
    Product product;

    if(file.open(QFile::ReadOnly))
    {
        file.readLine();
        while (!file.atEnd()) {
            line = QTextCodec::codecForName("GBK")->toUnicode(file.readLine());
            product_name = line.split(',').at(0);
            product = select_product_by_name(product_name);
            goods_name_string = line.split(',').at(1);
            goods_name_list = goods_name_string.split('+');

            for(int i=0;i<goods_name_list.size();i++)
            {
                product.add_goods(select_goods_by_name(goods_name_list.at(i)));
            }

            product_container_by_name[product_name] = product;
            product_container_by_code[product.get_code()] = product;
        }
    }
}

void Database::load_products()
{
    QString file_path= m_workdir+"/产品.csv";
    QFile file(file_path);
    QString line;
    QString name;
    QString code;
    QStringList data;
    Product product;

    if(file.open(QFile::ReadOnly))
    {
        file.readLine();
        while (!file.atEnd()) {
            line = QTextCodec::codecForName("GBK")->toUnicode(file.readLine());
            data = line.split(',');
            name = data.at(0);
            code = data.at(1);
            product = Product(name,code);
            product_container_by_code.insert(code,product);
            product_container_by_name.insert(name,product);
        }
    }
}

void Database::data_init()
{
    load_goods();
    load_products();
    load_rules();
    load_function();
    confirm_code = function["确认"];
}

Goods Database::select_goods_by_code(QString code)
{
    return goods_container_by_code[code];
}

Goods Database::select_goods_by_name(QString name)
{
    return goods_container_by_name[name];
}

Product Database::select_product_by_code(QString code)
{
    return product_container_by_code[code];
}

Product Database::select_product_by_name(QString name)
{
    return product_container_by_name[name];
}
