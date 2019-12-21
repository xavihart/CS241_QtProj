#include "openwindow.h"
#include"ui_openwindow.h"
#include<QTime>
openwindow::openwindow(QWidget * parent):
QMainWindow(parent),
ui(new Ui::openwindow)
{
  ui->setupUi(this);
  this->setWindowTitle("Welcome to HanZhou Metro System");
  connect(&mt, SIGNAL(progress_changed(int)), this, SLOT(change_progbar(int)));

}

openwindow::~openwindow(){delete ui;}
void openwindow::change_progbar(int p){
    cout << "receive changing signals" << p;
    ui->progressBar->setMaximum(209);
    ui->progressBar->setValue(p);
}
QStringList my_thread::get_file_name(const QString &path){
    QDir dir(path);
    QStringList namefilters;
    namefilters << "*.csv";
    QStringList files = dir.entryList(namefilters, QDir::Files|QDir::Readable, QDir::Name);
    file_names = files;
    return files;
}

void my_thread::run(){
    QSqlDatabase database;
    QTime tot_time;
    tot_time.start();
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("../MetroRecord.db");
    database.open();
    QSqlQuery sql_query;
    // check whether the file is existing---
    sql_query.exec(QString("select count(*) from sqlite_master where type='table' and name='%1'").arg("record"));
    sql_query.next();
    bool isTableExist = (sql_query.value(0).toInt() != 0);
    cout << isTableExist << "!";
    if(isTableExist){
      cout << "Table exist, no need creating!---";
    }else{
      QString create_m = "create table record (time varchar(22), lineID int, stationID int, status int, paytype int)";
      sql_query.prepare(create_m);
      if(sql_query.exec()){
          //cout << "table created successfully in my_thread";
      }else{
          //cout << "table created unsuccessfully in my_thread";
      }
    }
     sql_query.exec("select count(*) from record");
     sql_query.next();
     int number=  sql_query.value(0).toInt();
     cout << number;
     int f = 1;
     if(number >15800000){
         cout << "data ready!";
         f = 0;
         emit progress_changed(209);
     }
if(f){
    for (int j = 0;j < file_names.count();++j){
        QTime time_each;
        time_each.start();
        if(already_downloaded[j] == 1) continue;
        QFile file_pth("../dataset_CS241/dataset/" + file_names[j]);
        //cout << "prepare " << file_pth <<endl;
        if (!file_pth.open(QIODevice::ReadOnly))
            qDebug() << "Failed to load file-----\n";
        else{}
            //qDebug() << "Success loading file-----\n";
        QTextStream* out = new QTextStream(&file_pth);
        QStringList tmp = out -> readAll().split("\n");
        QStringList t;
 // INSERT DATA INTO DB
        database.transaction();
        for (int i = 1;i < tmp.count() - 1;++i){

            //time, lineID, stationID, status, paytype
            //cout << tmp.count() << i;
            sql_query.prepare("INSERT INTO record (time, lineID, stationID, status, paytype) VALUES(?, ?, ?, ?, ?)");
            t = tmp.at(i).split(",");
            sql_query.bindValue(0, t[0]);
            sql_query.bindValue(1, t[1].toInt());
            sql_query.bindValue(2, t[2].toInt());
            sql_query.bindValue(3, t[4].toInt());
            sql_query.bindValue(4, t[6].toInt());
            if (!sql_query.exec()){
                //cout << "failed to insert data of file" << j << "\n"  << sql_query.lastError();
            }else{
                //cout << "Successfullt insert data:file[" << j << "], " << "line[" << i << "]\n";
            }
        }

        emit progress_changed(j);
        already_downloaded[j] = 1;
        cout << "time cmd of file" << j + 1  << "["<< time_each.elapsed() / 1000.0 << "]" << "s";
    }

    cout << "file downloaded successfully !" << "total time cmd is:[" << tot_time.elapsed() / 1000.0 / 60.0 << "]min";
    database.commit();
}
QTime indextime;
indextime.start();
    sql_query.exec("select count(*) from sqlite_master where type = 'index'");
    sql_query.next();
    if(!sql_query.value(0).toInt()){
        if(sql_query.exec("create index time_station_status_index on record(time, stationID, status)")){
            cout << "index created successfully!";
        }else{
            cout << "faliled to create index for database"  << sql_query.lastError();
        }
    }else{
        cout << "index already exist!";
    }
cout << "creating index tool about" << indextime.elapsed() / 1000.0/ 60 << "min";

    database.close();
    return;
}



void openwindow::data_loading_thread_begin(){
    mt.start();
}




