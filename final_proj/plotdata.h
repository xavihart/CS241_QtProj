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
public slots:

    void plot_passflow();

};



#endif // PLOTDATA_H
