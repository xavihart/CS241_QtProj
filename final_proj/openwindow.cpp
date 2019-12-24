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
  // set the image:
  QPixmap bkg_pic("../dataset_CS241/pic/Hangzhou.jpg"), button_pic("../dataset_CS241/pic/cristalbutton.jpg");
  ui->bkg->setPixmap(bkg_pic);
  ui->bkg->setScaledContents(true);
  ui->bkg->lower();
  ui->bkg->show();

  QPalette pa, pa2, pa3, pa4;
  pa.setColor(QPalette::WindowText,Qt::white);
  ui->label->setPalette(pa);
  ui->label_2->setPalette(pa);

}

openwindow::~openwindow(){delete ui;}
void openwindow::change_progbar(int p){
    //cout << "receive changing signals" << p;
    ui->progressBar->setMaximum(209);
    ui->progressBar->setValue(p);
    if(p >= 209){
        emit data_ready();
    }

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
      QString create_m = "create table record (time varchar(22), lineID varchar(3), stationID int, status int, paytype int)";
      sql_query.prepare(create_m);
      if(sql_query.exec()){
          //cout << "table created successfully in my_thread";
      }else{
          //cout << "table created unsuccessfully in my_thread";
      }
    }

    // check whether the data is already there
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

     //download data
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
            sql_query.bindValue(1, t[1]);
            //cout << t[1];
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
       // cout << "time cmd of file" << j + 1  << "["<< time_each.elapsed() / 1000.0 << "]" << "s";
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
    // filter:
    int a[8];
    a[0] = int(ui->checkBox_9->isChecked());
    a[1] = int(ui->checkBox_10->isChecked());
    a[2] = int(ui->checkBox_11->isChecked());
    a[3] = int(ui->checkBox_12->isChecked());
    a[4] = int(ui->checkBox_13->isChecked());
    a[5] = int(ui->checkBox_14->isChecked());
    a[6] = int(ui->checkBox_15->isChecked());
    a[7] = int(ui->checkBox_16->isChecked());

    int tot = 0;
    for(int i = 0;i < 8;++i)
        tot += a[i];
    if(tot == 0){
        QMessageBox::information(NULL, "Warning", "At least choose one to download!",
                                 QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        return;
    }

    if(a[7] == 0){
        QMessageBox::information(NULL, "Warning", "AdjMap not choosed, the route planning function will be unusable!",
                                 QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        return;
    }
    if(a[0] == 0 || a[1] == 0 || a[5] == 0){
        QMessageBox::information(NULL, "Warning", "Time, status, stationID is necessary for plotting traffic flow!",
                                 QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        return;
    }

    mt.start();
}




