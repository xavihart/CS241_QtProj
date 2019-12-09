#include "mainwindow.h"
#include "ui_mainwindow.h"
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


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(1000, 1000);
    load_adjacency_map();
    solving_route(1, 81);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::load_adjacency_map(){
    QVector<QStringList> data;
    qDebug() << "Begin to load adjancency map-----" << "\n";
    QFile file_pth("../dataset_CS241/adjacency_adjacency/Metro_roadMap.csv");
    if (!file_pth.open(QIODevice::ReadOnly))
        qDebug() << "Failed to load adjacency file-----\n";
    else
        qDebug() << "Success loading adjacency file-----\n";
    QTextStream* out = new QTextStream(&file_pth);
    QStringList tmp = out -> readAll().split("\n");
    //qDebug() << tmp.count()<<endl;

    for(int i = 0; i < tmp.count(); ++i)
         data.append(tmp.at(i).split(","));
    //int data_w = data.count() - 1, data_len = data[2].count() - 1;
    //qDebug() << data_w << data_len << endl;
// transfer data to type bool
    for (int i = 0;i < 81;++i)
        for (int j = 0;j < 81;++j)
            adjmap[i][j] = bool(data.at(i + 2).at(j + 1).toInt());


}
void MainWindow::dfs(int now, int des, vector<int> rec){
    if (now == des) {
        solving_number ++;
        qDebug() <<"the" << solving_number << "th route:";
        for (unsigned int i = 0;i < rec.size();++i)
            qDebug() << rec[i] << " ";
        cout << "\n";
    }else{
        for(int i = 0;i < 81;++i){
            if (i == now)
                continue;
            if(used[now][i] || used[i][now])
                continue;
            if(adjmap[now][i] == 0)
                continue;
            else{
                cout << i << endl;
                vector<int> new_rec = rec;
                new_rec.push_back(i + 1);
                used[now][i] = 1;
                used[i][now] = 1;
                dfs(i, des, new_rec);
            }
            used[now][i] = 0;
            used[i][now] = 0;
        }
    }
    return;
}

void MainWindow::solving_route(int s,int d){
    for (int i = 0;i < 90;++i)
        for (int j = 0;j < 90;++j)
             used[i][j] = 0;

    solving_number = 0;
    s --;
    d--;
    vector<int> rec;
    rec.push_back(s + 1);
    dfs(0, d, rec);
    if(solving_number == 0) cout << "cannot find a possible route!"
}


