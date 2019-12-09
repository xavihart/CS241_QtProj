#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<vector>
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
    bool adjmap[90][90];
    bool used[90][90]={0};
    void load_adjacency_map();
    void dfs(int stationID_now, int destination_ID, vector<int> record_list);
    void load_record_data();
    int solving_number = 0;
};

#endif // MAINWINDOW_H
