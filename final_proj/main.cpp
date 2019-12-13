#include "mainwindow.h"
#include"drawroute.h"
#include <QApplication>
#include<signal.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    route_drawer k;
    //k.show();
    //k2.draw_3(10, 10, QColor(20, 203, 20), 10);
    //k.draw(10, 10, QColor(20, 203, 20), 10);
    qDebug() << QColor(2, 203, 20);
    QPushButton button(&w);
    button.show();
   // QObject::connect(&w, SIGNAL(route_advicing_begin(int, int, int, int ,int , int)), &k, SLOT(close()));
   // k.draw(10, 30, 0, 200, 200, 10);
    //k.draw(100, 100, 0, 2, 200, 10);
    QObject::connect(&button, SIGNAL(clicked()),&k, SLOT(show()));
    return a.exec();
}
