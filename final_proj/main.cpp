#include "mainwindow.h"
#include"drawroute.h"
#include"openwindow.h"
#include"ui_plotdata.h"
#include"plotdata.h"
#include <QApplication>
#include<signal.h>
#include<ui_openwindow.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //QVector<QStringList> record_data[7];
    //MainWindow w;
   // w.show();
    //route_drawer k;
    //k.show();
    //k2.draw_3(10, 10, QColor(20, 203, 20), 10);
    //k.draw(10, 10, QColor(20, 203, 20), 10);
    //qDebug() << QColor(2, 203, 20);
    //QPushButton button(&w);
   // button.show();
   // QObject::connect(&w, SIGNAL(route_advicing_begin(int, int, int, int ,int , int)), &k, SLOT(close()));
   // k.draw(10, 30, 0, 200, 200, 10);
    //k.draw(100, 100, 0, 2, 200, 10);
    //QObject::connect(&button, SIGNAL(clicked()),&k, SLOT(show()));
    openwindow opwindow;
    opwindow.show();
    MainWindow adv_w;
    plotdata dataploting_w;
    QObject::connect(opwindow.ui->data_plotting, SIGNAL(clicked(bool)), &dataploting_w, SLOT(show()));
    QObject::connect(opwindow.ui->advicing_route, SIGNAL(clicked()), &adv_w, SLOT(show()));
    my_thread load_file_thread;
    //load_file_thread.data = record_data;
    QObject::connect(opwindow.ui->download_data, SIGNAL(clicked()), &load_file_thread, SLOT(start()));
    return a.exec();
}
