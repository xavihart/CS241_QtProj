#include "mainwindow.h"
#include "ui_mainwindow.h"




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    clock = new QTime();
    this->setFixedSize(850, 478);
    load_adjacency_map();

    QStringList file_names = get_file_name("../dataset_CS241/dataset/");

    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(ask_for_route_advicing()));
    QPixmap pix_tmp("../dataset_CS241/pic/hzlog.jpg"), pix2("../dataset_CS241/pic/map.jpg");
    ui->logo->setPixmap(pix_tmp);
    ui->logo->setScaledContents(true);
    ui->logo->show();

    //QIcon icon1;
    //icon1.addFile("../dataset_CS241/pic/button1.png");
    ui->pushButton->setStyleSheet("border-image:url(../dataset_CS241/pic/button1.png)");
    QPixmap bkg_pic("../dataset_CS241/pic/xue.jpg");
    ui->bkg->setPixmap(bkg_pic);
    ui->bkg->setScaledContents(true);
    ui->bkg->lower();
    ui->bkg->show();

    //----RegEXp----------------------------
    QRegExp regExp2("[0-9]{1,2}");
    QRegExpValidator *pRegExpValidator2 = new QRegExpValidator(regExp2,this);
    ui->dest->setValidator(pRegExpValidator2);
    ui->start->setValidator(pRegExpValidator2);
    ui->showroute->setReadOnly(true);
    //--------------------------------------


    //progressdig = new QProgressDialog(tr("Downloading Progress"), tr("Cancel"), 0,100, this);
    //progressdig->setWindowTitle("Downloading Files");
    //progressdig->show();
    //progressdig->setValue(10);
    //load_record_data();
    //solving_route(1, 81);
    //paintEvent();

    //test code:
    //
   


}

void MainWindow::paintEvent(QPaintEvent*){
    painter = new QPainter(this);
    painter->setRenderHint(QPainter::Antialiasing, true);
    painter->setPen(QColor(0, 160, 230));
    painter->drawLine(QPointF(0, height()), QPointF(width() ,height()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::load_record_data(){
    for (int i = 0;i < 100;++i){
        QFile file_pth("../dataset_CS241/dataset/" + record_file_name[i]);
        cout << file_pth<<endl;
        if (!file_pth.open(QIODevice::ReadOnly))
            qDebug() << "Failed to load file-----\n";
        else
            qDebug() << "Success loading file-----\n";
        QTextStream* out = new QTextStream(&file_pth);
        QStringList tmp = out -> readAll().split("\n");
        QStringList t;
        for (int i = 0;i < tmp.count();++i){
            t = tmp.at(i).split(",");
            tmp_var = t;
        }
        progressdig->setValue(i);
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
    for(int i = 0; i < tmp.count(); ++i)
         data.append(tmp.at(i).split(","));
    //int data_w = data.count() - 1, data_len = data[2].count() - 1;

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
        route.push_back(rec);
    }else{
        for(int i = 0;i < 81;++i){
            if (i == now)
                continue;
            if(used[now][i] || used[i][now])
                continue;
            if(adjmap[now][i] == 0)
                continue;
            else{
                //cout << i << endl;
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

}

void MainWindow::solving_route(){
    int s, d;
    route.clear();
    if(ui->start->text().isEmpty() || ui->dest->text().isEmpty())
    {
        input_right = 0;
        ui->showroute->setTextColor(Qt::red);
        ui->showroute->setText("PLease input both the departure and destination!");
        return;
    }
    s = ui->start->text().toInt();
    d = ui->dest->text().toInt();
    if(s > 81 || d > 81 || s == 0 || d == 0){
        input_right = 0;
        ui->showroute->setTextColor(Qt::red);
        ui->showroute->setText("PLease input the right station ID!");
        return;
    }

    input_right = 1;
    ui->showroute->setTextColor(QColor(0, 192, 255));

    for (int i = 0;i < 90;++i)
        for (int j = 0;j < 90;++j)
             used[i][j] = 0;
    solving_number = 0;
    s --;
    d--;
    vector<int> rec;
    rec.push_back(s + 1);
    dfs(s, d, rec);
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

void MainWindow::draw_3(int x, int y, QColor c, int w)
{
     QPainter Painter(this);

     Painter.setPen(QPen(QColor(2, 203, 20), 100));

     Painter.drawPoint(10, 10);

     qDebug() << "get signal 3" << x << y << c << w;

}





vector<vector<int>> MainWindow::find_the_best_route(vector<vector<int>> routes){
    int num = routes.size();
    vector<double> scores, tmp;
    // the number of station changes
    for(int i = 0;i < num;++i){
       scores.push_back(routes[i].size() * weight_changes);
    }
    // the length
    for(int i = 0;i < num;++i){
        int tmp = 0;
        for(int j = 0;j < routes[i].size() - 1;++j){
            tmp += abs(routes[i][j+1] - routes[i][j]);
        }
        scores[i] += tmp * weight_length;
    }
    for(int i = 0;i < num;++i)
        scores[i] += (avg_flow[i] / 100000.0) * weight_crowed;
    vector<vector<int>> ans;
    vector<int> index = my_sort(scores);
    for(int i =0 ;i < min(3, num);++i){
        if (i >= 1){
             if(scores[index[i]] > 2 * scores[index[i - 1]])
                 break;
        }else{
        ans.push_back(routes[index[i]]);
        }
    }
    return ans;  
}



void MainWindow::ask_for_route_advicing(){
    solving_route();
    if (input_right == 0) return;
    vector<vector<int>> a = find_the_best_route(route);
    QString d="";
    for(int i =0 ;i < a.size();++i){
        if(a.size() > 1)
          d.append("The " + QString::number(i+1) +"th possible route:\n");
        else
          d.append("Optimized Possible Route:\n");
        for(int j = 0;j < a[i].size();++j){
            d += QString::number(a[i][j]);
            if(j != a[i].size() - 1)
                d += " -> ";
        }
        d+="\n";
    }
    ui->showroute->setText(d);
}

template<class T>
vector<int> MainWindow::my_sort(vector<T> a){
    vector<int> index;
    int n = a.size();
    for(int i =0 ;i < n;++i)
        index.push_back(i);

    for(int j = n - 1;j >=0;--j){
        int f = 0;
        for(int i =0 ;i < j;++i){
            if(a[i] > a[i+1]){
                f = 1;
                int dtmp, itmp;
                dtmp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = dtmp;
                itmp = index[i];
                index[i] = index[i + 1];
                index[i + 1] = itmp;
            }
        }
        if(f == 0) break;
    }

    for(int i =0 ;i < a.size();++i)
         cout << a[index[i]] << "\n";
    return index;
}


void MainWindow::show_(){
    if(!data_ready){
        QMessageBox::information(NULL, "Warning", "Data not prepared for route advicing!!",
                                 QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    }else{
        this->show();
    }
}
