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
    QObject::connect(opwindow.ui->download_data, SIGNAL(clicked()),&opwindow, SLOT(data_loading_thread_begin()));
    // ---12/19  add sql
    QSqlDatabase database;
    if(QSqlDatabase::contains("qt_sql_default_connection")){
        database = QSqlDatabase::database("qt_sql_default_connection");
        cout << "alr connected!";
    }
    else{
        database = QSqlDatabase::addDatabase("QSQLITE");
        database.setDatabaseName("../MetroRecord.db");
        database.setUserName("ChrisXue");
        database.setPassword("123456");
    }
    //cout << QSqlDatabase::contains("qt_sql_default_connection") << "2";
    if(!database.open()){
        cout << "db is not open!";
    }
    QSqlQuery sql_query;
    bool isTableExist = sql_query.exec(QString("select count(*) from sqlite_master where type='table' and name='%1'").arg("record"));
    if(isTableExist){
      cout << "Table exist, no need creating!---";
    }else{
    QString create_m = "create table record (time varchar(22), lineID int, stationID int, status int, paytype int)";

    //            OMIT userID AND deviceID to make the insertion faster...
    // time, lineID, stationID, status, paytype
    if(!sql_query.exec(create_m)){
        cout << "table failed" << sql_query.lastError();
    }else{
        cout << "table ok";
    }
    }
    cout << "table prepared";


/*
    sql_query.prepare("INSERT INTO record VALUES(\"2019-01-07\", 1, 2, 3, 4)");
    cout << sql_query.prepare("INSERT INTO record (time, lineID, stationID, status, paytype) VALUES(?, ?, ?, ?, ?)");
    cout << sql_query.lastError();


    QVariantList timelist;
    timelist << "2019-01-07" << "2019-01-08" << "2019-01-09";
    QVariantList lineIDlist;
    lineIDlist << 1 << 2 << 3;
    QVariantList stationIDlist;
    stationIDlist << 100 << 101 << 102;
    QVariantList statuslist;
    statuslist << 1  << 0 << 1;
    QVariantList paytypelist;
    paytypelist << 0 << 2 << 3;

    sql_query.bindValue(0, "2019-11-10");
    sql_query.bindValue(1, 1);
    sql_query.bindValue(2, 4);
    sql_query.bindValue(3, 8);
    sql_query.bindValue(4, 16);

    cout << sql_query.exec();

    cout << sql_query.exec("select * from record") << sql_query.lastError();
    while(sql_query.next()){
        cout << 1;
        cout << sql_query.value("time");
    }

    database.close();

 */













    return a.exec();

    /*
     * time,lineID,stationID,deviceID,status,userID,payType
2019-01-07 06:41:33,C,63,2952,1,C0453c92064c39bec91edd3dffc98e50b,2
     *
     * */

}
