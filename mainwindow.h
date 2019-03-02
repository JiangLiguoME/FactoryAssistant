#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMap>
#include <QString>
#include <QKeyEvent>
#include <QMessageBox>
#include <QLabel>

#include "product.h"
#include "database.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    bool load_data();
    void judge(QString input);

private slots:
    void on_pushButton_2_clicked();
    void keyPressEvent(QKeyEvent *event);
    void on_pushButton_clicked();
    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::MainWindow *ui;
    QString m_work_path;
    QMap<QString,Product> product_container;
    QMap<QString,Goods> goods_container;
    Product product;
    QStringList goods_code_list;
    Database db;
    QString state;
    QString input;
    QString confirm_code;
    QMessageBox * warn;
    QMap<QString,QLabel *> label_map;
};

#endif // MAINWINDOW_H
