#include "openwindow.h"
#include"ui_openwindow.h"
openwindow::openwindow(QWidget * parent):
QMainWindow(parent),
ui(new Ui::openwindow)
{
  ui->setupUi(this);
  this->setWindowTitle("Welcome to HanZhou Metro System");
}

openwindow::~openwindow(){delete ui;}

QStringList my_thread::get_file_name(const QString &path){
    QDir dir(path);
    QStringList namefilters;
    namefilters << "*.csv";
    QStringList files = dir.entryList(namefilters, QDir::Files|QDir::Readable, QDir::Name);
    file_names = files;
    return files;
}

void my_thread::run(){
    cout << "run called-------";
    for (int i = 0;i < 200;++i){
        QFile file_pth("../dataset_CS241/dataset/" + file_names[i]);
        cout << file_pth<<endl;
        if (!file_pth.open(QIODevice::ReadOnly))
            qDebug() << "Failed to load file-----\n";
        else
            qDebug() << "Success loading file-----\n";

        QTextStream* out = new QTextStream(&file_pth);
        QStringList tmp = out -> readAll().split("\n");
        // omit the first line ---
        cout << tmp.count() << "lines"<<"\n";
        for (int k = 1;k < tmp.count();++k){
            data[i / 30].push_back(tmp.at(k).split(","));
        }
        emit progress_changed(i);
    }
return;
}







