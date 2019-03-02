#include "inputprocess.h"

void InputProcess::judge(QString input_string)
{
    switch ((code_type(input_string))) {
    case 'product':
        product = db.select_product_by_code(input_string);
        goods_code_list = product.get_goods();
        break;
    case "goods":
        break;
    default:
        break;
    }
}

QString InputProcess::code_type(QString input_string)
{
    if(db.select_product_by_code(input_string))
    {
        return "product";
    }
    if(db.select_goods_by_code(input_string))
    {
        return "goods";
    }
}
