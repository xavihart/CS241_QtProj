#include "mainwindow.h"
#include "ui_mainwindow.h"




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    clock = new QTime();
    this->setFixedSize(1000, 1000);
    load_adjacency_map();
    QStringList file_names = get_file_name("../dataset_CS241/dataset/");
    progressdig = new QProgressDialog(tr("Downloading Progress"), tr("Cancel"), 0, record_file_name.count(), this);
    progressdig->setWindowTitle("Downloading Files");
    progressdig->show();
    load_record_data();

    //solving_route(1, 81);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::load_record_data(){
    for (int i = 0;i < record_file_name.count();++i){
        QFile file_pth("../dataset_CS241/dataset/" + record_file_name[i]);
        cout << file_pth<<endl;
        if (!file_pth.open(QIODevice::ReadOnly))
            qDebug() << "Failed to load file-----\n";
        else
            qDebug() << "Success loading file-----\n";
        QTextStream* out = new QTextStream(&file_pth);
        QStringList tmp = out -> readAll().split("\n");
        QStringList t;
        for(int i = 0;i < tmp.count();++i)
            t = tmp.at(i).split(",");
        //progressdig->setValue(i);
    }

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
    if(solving_number == 0) cout << "cannot find a possible route!";
}


QStringList MainWindow::get_file_name(const QString &path){
    QDir dir(path);
    QStringList namefilters;
    namefilters << "*.csv";
    QStringList files = dir.entryList(namefilters, QDir::Files|QDir::Readable, QDir::Name);
    record_file_name = files;
    return files;
}




