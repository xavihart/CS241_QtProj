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
#include<QSqlQueryModel>
#include<QDateTime>
#include  <QtCharts>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCore/QDateTime>
#include <QtCharts/QDateTimeAxis>
#include <QtCore/QFile>
#include <QtCore/QTextStream>
#include <QtCore/QDebug>
#include <QtCharts/QValueAxis>
#include<QVector>
#include<QMessageBox>

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
    QString generate_exe(QDateTime startingtime, QDateTime endingtime, int stationID, int status);
    QLineSeries *series, *series2;
    QSplineSeries *sps, *sps2;
    QVector<double> in_flow;
    QVector<double> out_flow;
    QVector<int> x_stick;
    int data_ready=0;

public slots:

    void plot_passflow();
    void data_prepared(){data_ready = 1;}
    void show_();


};



#endif // PLOTDATA_H
