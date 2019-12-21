#include "plotdata.h"
#include "ui_plotdata.h"

plotdata::plotdata(QWidget * parent):
QMainWindow(parent),
ui(new Ui::plotdata)
{
  ui->setupUi(this);
  this->setWindowTitle("Plot data");
  connect(ui->plt, SIGNAL(clicked(bool)), this, SLOT(plot_passflow()));

  ui->dateTimeEdit->setMaximumDate(QDate::fromString("2019-01-07 00:00:00"));
  ui->dateTimeEdit->setMinimumDate(QDate::fromString("2019-01-13 00:00:00"));
  ui->dateTimeEdit_2->setMaximumDate(QDate::fromString("2019-01-07 00:00:00"));
  ui->dateTimeEdit_2->setMinimumDate(QDate::fromString("2019-01-13 00:00:00"));

}

plotdata::~plotdata(){delete ui;}
void plotdata::plot_passflow(){
    in_flow.clear();
    out_flow.clear();
    x_stick.clear();
    QSqlDatabase database;
    QTime tot_time;
    tot_time.start();
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("../MetroRecord.db");
    QSqlQuery sql_query;
    if(!database.open())
        cout << "data base open failed in plot part!" <<sql_query.lastError();
    QSqlQueryModel qmodel;

    // get data from ui------------------
    QDateTime stime = ui->dateTimeEdit->dateTime();
    QDateTime etime = ui->dateTimeEdit_2->dateTime();
    int step_hour = ui->step_hour->text().toInt(),  \
        step_min = ui->step_min->text().toInt(), \
        step_sec = ui->step_sec->text().toInt(), \
        station_num = ui->stationnumber->text().toInt();
     QDateTime tmp = stime;
     int num_in=0, num_out=0;
     if((step_hour * 60 * 60 +  step_min * 60 + step_sec) == 0){
         return;
     }
     int max1=0, max2=0;
     for(;;){
         QDateTime tmp_r = tmp;
         tmp_r = tmp_r.addSecs(step_hour * 60 * 60 +  step_min * 60 + step_sec);
         // in
         if(tmp_r > etime) break;
         //cout << tmp_r.toMSecsSinceEpoch();
         QString command_in = generate_exe(tmp, tmp_r, station_num, 1);
         //cout << command_in;
         sql_query.exec(command_in);
         sql_query.next();
         num_in = sql_query.value(0).toInt();
         //cout << "in" << num_in;
         // out
         QString command_out = generate_exe(tmp, tmp_r, station_num, 0);
         sql_query.exec(command_out);
         sql_query.next();
         num_out = sql_query.value(0).toInt();
         x_stick.push_back(tmp.toMSecsSinceEpoch());
         in_flow.push_back(num_in);
         out_flow.push_back(num_out);
         tmp = tmp_r;
        // cout << "out" << num_out;
         max1=max(max1, num_in);
         max2=max(max2, num_out);
     }

   // ------------------------draw plot---------------
     series = new QLineSeries();
     series2 =  new QLineSeries();
     for(int i = 0;i < in_flow.size();++i){
         series->append(x_stick.at(i) - 111616000, in_flow.at(i));
         series2->append(x_stick.at(i) - 111616000, out_flow.at(i));
     }

     QChart *chart = new QChart();
     chart->addSeries(series);
     chart->addSeries(series2);
     chart->legend()->show();
     chart->setTitle("In-Out Flow PLot");


     QDateTimeAxis *axisX = new QDateTimeAxis;
     axisX->setTickCount(10);
     axisX->setFormat("MM-dd hh:mm");
     axisX->setTitleText("Time");
     chart->addAxis(axisX, Qt::AlignBottom);

     if(max1 > max2){
         series->attachAxis(axisX);
         series2->attachAxis(axisX);
     }else{
         series2->attachAxis(axisX);
         series->attachAxis(axisX);
     }

     QValueAxis *axisY = new QValueAxis;
     axisY->setLabelFormat("%i");
     axisY->setTitleText("Flow");
     chart->addAxis(axisY, Qt::AlignLeft);

     if(max1 > max2){
         series->attachAxis(axisY);
         series2->attachAxis(axisY);
     }else{
         series2->attachAxis(axisY);
         series->attachAxis(axisY);
     }


     chart->setAnimationOptions(QChart::AllAnimations);
     QChartView *chartView = new QChartView(chart);
     chartView->setRenderHint(QPainter::Antialiasing);
     chartView->show();
    //--------------------------------
    cout << stime << etime;
   cout << stime.toString("yyyy-MM-dd hh:mm:ss") << etime.toString("yyyy-MM-dd hh:mm:ss");
   /* QString p = "select count(*) from record where time between '" + stime.toString("yyyy-MM-dd hh:mm:ss") \
            + "' and '" + etime.toString("yyyy-MM-dd hh:mm:ss") + "'";
    cout << p;

    sql_query.prepare(p);
    if(!sql_query.exec())
        cout << "error!" << sql_query.lastError();
    sql_query.next();
    cout << sql_query.value(0).toInt() << "in the given scope";    */
    database.close();

}



QString plotdata::generate_exe(QDateTime stime, QDateTime etime, int stationID, int status){
    QString p = "select count(*) from record where time between '" + stime.toString("yyyy-MM-dd hh:mm:ss") \
          +  "' and '" + etime.toString("yyyy-MM-dd hh:mm:ss") + "' " + "and stationID = " + \
            QString::number(stationID)+  " and status = " + QString::number(status);
    return p;
}


