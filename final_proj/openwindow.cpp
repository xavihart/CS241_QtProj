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
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("../MetroRecord.db");
    database.open();
    QSqlQuery sql_query;
    bool isTableExist = sql_query.exec(QString("select count(*) from sqlite_master where type='table' and name='%1'").arg("record"));
    if(isTableExist){
      cout << "Table exist, no need creating!---";
    }else{
      QString create_m = "create table record (time varchar(22), lineID int, stationID int, status int, paytype int)";
      sql_query.prepare(create_m);
      if(sql_query.exec()){
          cout << "table created successfully in my_thread";
      }else{
          cout << "table created unsuccessfully in my_thread";
      }
    }
    QTime mtime;
    mtime.start();
    for (int j = 0;j < 2;++j){
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
                cout << "failed to insert data of file" << j << "\n"  << sql_query.lastError();
            }else{
                cout << "Successfullt insert data:file[" << j << "], " << "line[" << i << "]\n";
            }
        }
        emit progress_changed(j);
    }
    database.commit();
    cout << "time elapsed:" << mtime.elapsed();
    database.close();
    return;
}







