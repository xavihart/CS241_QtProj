#ifndef PLOTDATA_H
#define PLOTDATA_H
#include<QMainWindow>
#include<QWidget>
#include<QThread>
#include<QStringList>
#include"mainwindow.h"
#include <QSqlDatabase>
#include<QSqlQuery>
#include<QSqlError>
#include<QVariantList>
namespace Ui {
  class plotdata;
}

class plotdata:public QMainWindow{
    Q_OBJECT

public:
    explicit plotdata(QWidget *parent = 0);
    ~plotdata();
    Ui::plotdata *ui;
    bool data_downloaded = 0;

};



#endif // PLOTDATA_H
