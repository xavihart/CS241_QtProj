#ifndef MAINWINDOW_H
#define MAINWINDOW_H
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
using namespace std;
namespace Ui {
  class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QTime * clock;
    QStringList record_file_name;
    bool adjmap[90][90];
    bool used[90][90]={0};
    int solving_number = 0;
    void load_adjacency_map();
    void dfs(int stationID_now, int destination_ID, vector<int> record_list);
    void load_record_data();
    QStringList get_file_name(const QString& path);
    QProgressDialog * progressdig;
    QStringList tmp_var;
    QPainter * painter;
    void paintEvent(QPaintEvent*);
    QPixmap pix;
    vector<vector<int>> route;
    QString start_text, end_text;
    int input_right = 0;
    template<class T>
        vector<int> my_sort(vector<T> );   //return the index string.
     
    
    //OPTIMIZATIO FOR ROUTE ADVISING:return the 3th best, if have;
    int weight_changes = 2;
    int weight_crowed = 3;
    int weight_length = 5;
    vector<vector<int>> find_the_best_route(vector<vector<int>>);
    void solving_route();
    QVector<QStringList> store_data[7];
signals:
    void route_advicing_begin(int x, int y, int c1, int c2, int c3 , int w);
public slots:
    void send_signal_for_routeadvicing(){
        qDebug() << "get signal!";
        emit route_advicing_begin(200, 300, 2, 202, 20, 10);
    }
    void draw_3(int, int, QColor, int);
    void ask_for_route_advicing();


    //data try:


};

#endif // MAINWINDOW_H
