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
#include<QProgressDialog>
#include<QTimer>

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
    void solving_route(int start_ID, int destination_ID);
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
};

#endif // MAINWINDOW_H
