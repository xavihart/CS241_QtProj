#ifndef OPENWINDOW_H
#define OPENWINDOW_H
#include<QAction>
#include<QMenuBar>
#include<QMessageBox>
#include<QStatusBar>
#include<QToolBar>
#include<QPushButton>
#include<QIODevice>
#include<QDebug>
#include<QTextStream>
#include<QDir>
#include<QFile>
#include<QColor>
#include<QPainter>
#include<QTime>
#include<QPushButton>
#include<QFileDialog>
#include <QMainWindow>
#include<QSqlDatabase>
#include<QSqlError>
#include<QSqlQuery>
#include<vector>
#include<algorithm>
#include<QProgressDialog>
#include<QTimer>
#include<mythread.h>
#include<QPainter>
#include<QPen>
#include<QPushButton>
#include<QPixmap>
#include<QString>
#include<cmath>
#include<QRegExp>
#include<QRegExpValidator>
#include<QIcon>
#include<QThread>

#define cout qDebug()
namespace Ui {
  class openwindow;
}

class openwindow:public QMainWindow{
    Q_OBJECT
public:
    explicit openwindow(QWidget *parent = 0);
    ~openwindow();
    Ui::openwindow *ui;
};

class my_thread:public QThread{
  Q_OBJECT
public:
    my_thread(QObject * parent=0){cout << this->currentThreadId();file_names = get_file_name("../dataset_CS241/dataset/");}
    ~my_thread(){}
    void run();
    QStringList file_names;
    QStringList get_file_name(const QString& path);
    QVector<QStringList> data[7];    // data[0]~data[6] represent data for 7 days

signals:
    void progress_changed(int );

};



#endif // OPENWINDOW_H
