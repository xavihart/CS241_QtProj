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
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>




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
    // for 3bars:
    QBarSet *set;
    // prior crowding data for visualization:
    int crd_A[81] = {0 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
                     0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0
                     ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0
                     ,0 ,0 ,0 ,91569 ,84772 ,140092 ,133120 ,88041 ,55007 ,150987 ,43841
                     ,179889 ,212531 ,197171 ,229642 ,85172 ,62573};  // [68-81]

    int crd_B[81] = {139296 ,88578 ,243299 ,179594 ,461105 ,279908 ,135871 ,435084 ,324189
                     ,661224 ,376001 ,363729 ,349504 ,289158 ,276662 ,1220184 ,302524 ,96323
                     ,227420 ,138612 ,339404 ,89499 ,308374 ,141455 ,256796 ,237685 ,136480
                     ,124585 ,59294 ,136859 ,104796 ,55756 ,109320 ,306643 ,0 ,0 ,0 ,0 ,0 ,0
                     ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0
                     ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0}; //[1-35]

    int crd_C[81] = {0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0
                     ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,100192 ,59836 ,82046 ,143671 ,147416 ,168705
                     ,86439 ,136015 ,173726 ,141314 ,143200 ,159894 ,262003 ,229947 ,154908
                     ,205755 ,170004 ,165801 ,207225 ,249493 ,0 ,218979 ,257684 ,216234
                     ,191423 ,195679 ,137824 ,156259 ,151691 ,159064 ,73405 ,116270 ,83548 ,0
                     ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0}; //[35-69]
    template<class T>
        vector<int> my_sort(vector<T> );
    template<class T>
        QVector<T> filter(QVector<T>);
    int filterlen=60;
    double coef1[16] = {-0.03252796, -0.81560961,  0.26367753,  1.56807106,  0.77953809,
                        0.26451983,  0.46030562, -1.64902383, -1.55571303,  1.44245154,
                       -0.03054342};
    double coef2[16] = {0.0};
    double lr = 0.00001;
    int poly = 5;
    double st = 500;
    double d = 0;
    QVector<double> y;
    void regresstion(int iteration){
        for(int i = 0;i < iteration; ++i)
        {   cout << "iter" << i;
            iter();
        }
    }
    void iter(){
        int num = qrand() % poly;
        double sum = 0.0;
        for(int k = 0;k < y.size();++k){
            double sum_ = 0.0;
            for(int i =0 ; i < poly;++i){
                sum_ +=  coef1[i] * pow(k / st, i);
            }

            if(y.at(k) == 0)
                sum_ *= d;
            sum += sum_ * 2.0 * pow(k / st, 1.0*num);
        }
        double loss=0.0;
        for(int i =0 ;i < y.size();++i){
            double loss_ = pow((cal_f(i/st) - y.at(i)), 2);
            if(y.at(i) == 0)
                loss_ *= d;
            loss+=loss_;
        }

            cout << "loss" << loss;
            coef1[num] -= lr * sum;
    }

    double cal_f(double x){
        double sum = 0.0;
        for(int i =0 ;i < poly;++i){
            sum += pow(x / st, i) * coef1[i];
        }
        return sum;
    }


public slots:

    void plot_passflow();
    void plot_line_station_total_flow();
    void data_prepared(){data_ready = 1;}
    void show_();


};
#endif // PLOTDATA_H
