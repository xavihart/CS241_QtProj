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
    int step_hour = QString::number(ui->step_hour->text()),  \
        step_min = QString::number(ui->step_min->text()), \
        step_sec = QString::number(ui->step_sec->text());






    //--------------------------------


    cout << stime << etime;
    cout << stime.toString("yyyy-MM-dd hh:mm:ss") << etime.toString("yyyy-MM-dd hh:mm:ss");
   /* QString p = "select count(*) from record where time between '" + stime.toString("yyyy-MM-dd hh:mm:ss") \
            + "' and '" + etime.toString("yyyy-MM-dd hh:mm:ss") + "'";
    cout << p;
    */
    sql_query.prepare(p);
    if(!sql_query.exec())
        cout << "error!" << sql_query.lastError();
    sql_query.next();
    cout << sql_query.value(0).toInt() << "in the given scope";
    database.close();

}



QString plotdata::generate_exe(QDateTime stime, QDateTime etime, int stationID, int status){
    QString p = "select count(*) from record where time between '" + stime.toString("yyyy-MM-dd hh:mm:ss") \
          +  "' and '" + etime.toString("yyyy-MM-dd hh:mm:ss") + "' " + "and stationID = " + \
            QString::number(stationID)+  " and status = " + QString::number(status);
    return p;
}


