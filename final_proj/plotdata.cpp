#include "plotdata.h"
#include "ui_plotdata.h"

plotdata::plotdata(QWidget * parent):
QMainWindow(parent),
ui(new Ui::plotdata)
{
  ui->setupUi(this);
  this->setWindowTitle("Visualize Hanzhou Metro Traffic Flow");
  connect(ui->plt, SIGNAL(clicked(bool)), this, SLOT(plot_passflow()));
  this->setFixedHeight(314);
  this->setFixedWidth(822);
  QPixmap bkg_pic("../dataset_CS241/pic/hz2.jpg");
  ui->bkg->setPixmap(bkg_pic);
  ui->bkg->setScaledContents(true);
  ui->bkg->lower();
  ui->bkg->show();
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
        station_num = ui->stationnumber->text().toInt() - 1;
     QDateTime tmp = stime;
     int num_in=0, num_out=0;
     if((step_hour * 60 * 60 +  step_min * 60 + step_sec) == 0){
         QMessageBox::information(NULL, "Warning", "Time step cannot be zero!",
                                  QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
         return;
     }
     if(station_num >= 81 || station_num < 0){
         QMessageBox::information(NULL, "Warning", "Please input the right station number!",
                                  QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
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
         num_in = num_in / ((tmp_r.toMSecsSinceEpoch()  - tmp.toMSecsSinceEpoch()) / 60000.0);
         num_out = num_out / ((tmp_r.toMSecsSinceEpoch()  - tmp.toMSecsSinceEpoch()) / 60000.0);
         cout << num_in << num_out;
         in_flow.push_back(num_in);
         out_flow.push_back(num_out);
         tmp = tmp_r;
        // cout << "out" << num_out;
         max1=max(max1, num_in);
         max2=max(max2, num_out);
     }

     int point_number=0;
     point_number = x_stick.count();

   // ------------------------draw plot---------------
   if(point_number > 15){
     series = new QLineSeries();
     series2 =  new QLineSeries();
     for(int i = 0;i < in_flow.size();++i){
         series->append(x_stick.at(i) - 111631000, in_flow.at(i));
         series2->append(x_stick.at(i) - 111631000, out_flow.at(i));
     }
     series->setName("In Flow");
     series2->setName("Out FLow");
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
     chart->resize(1000, 600);
     chart->setWindowTitle("Passenger FLow Chart");
     chartView->setWindowTitle("Passenger FLow Chart");
     chartView->show();
   }


   if(point_number <= 15){
       sps = new QSplineSeries();
       sps2 =  new QSplineSeries();
       for(int i = 0;i < in_flow.size();++i){
           sps->append(x_stick.at(i) - 111631000, in_flow.at(i));
           sps2->append(x_stick.at(i) - 111631000, out_flow.at(i));
       }
       sps->setName("In Flow");
       sps2->setName("Out FLow");
       QChart *chart = new QChart();
       chart->addSeries(sps);
       chart->addSeries(sps2);
       chart->legend()->show();
       chart->setTitle("In-Out Flow PLot");


       QDateTimeAxis *axisX = new QDateTimeAxis;
       axisX->setTickCount(10);
       axisX->setFormat("MM-dd hh:mm");
       axisX->setTitleText("Time");
       chart->addAxis(axisX, Qt::AlignBottom);

       if(max1 > max2){
           sps->attachAxis(axisX);
           sps2->attachAxis(axisX);
       }else{
           sps2->attachAxis(axisX);
           sps->attachAxis(axisX);
       }

       QValueAxis *axisY = new QValueAxis;
       axisY->setLabelFormat("%i");
       axisY->setTitleText("Flow");
       chart->addAxis(axisY, Qt::AlignLeft);

       if(max1 > max2){
           sps->attachAxis(axisY);
           sps2->attachAxis(axisY);
       }else{
           sps2->attachAxis(axisY);
           sps->attachAxis(axisY);
       }


       chart->setAnimationOptions(QChart::AllAnimations);
       QChartView *chartView = new QChartView(chart);
       chartView->setRenderHint(QPainter::Antialiasing);
       chart->resize(1000, 600);
       chart->setWindowTitle("Passenger FLow Chart");
       chartView->setWindowTitle("Passenger FLow Chart");
       chartView->show();

   }
    //--------------------------------
    //cout << stime << etime;
   //cout << stime.toString("yyyy-MM-dd hh:mm:ss") << etime.toString("yyyy-MM-dd hh:mm:ss");
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


void plotdata::show_(){
    if(!data_ready){
        QMessageBox::information(NULL, "Warning", "Data not prepared for route advicing!!",
                                 QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    }else{
        this->show();
    }
}



