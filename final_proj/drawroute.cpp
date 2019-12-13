#include<drawroute.h>
#include<ui_drawroute.h>
#define WIN_WIGHT   800
#define WIN_HEIGHT  600
#define WIN_TITLE   "画图测试"
#include<QDebug>
#include<QMainWindow>
route_drawer::route_drawer(QWidget *parent):
    QMainWindow(parent), ui(new Ui::route_drawer){
    ui->setupUi(this);
    setWindowTitle("demo");
    connect(ui->start, SIGNAL(clicked()), this, SLOT(start()));
}

route_drawer::~route_drawer(){
    delete ui;
}

void route_drawer::paintEvent(QPaintEvent *) {
    QPainter Painter(this);
    Painter.setRenderHint(QPainter::Antialiasing, true);
    Painter.setPen(QColor(0, 160, 230));
    Painter.drawLine(QPointF(0, 500/k), QPointF(400/k, 300/k));
}

void route_drawer::draw(int x, int y, int c1, int c2, int c3, int w)
{
     QPainter Painter(&Pix);

     Painter.setPen(QPen(QColor(c1, c2, c3), 100));

     Painter.drawPoint(x, y);

     qDebug() << "get signal 2" << x << y << c1 << c2 << c3  << w;

}

void route_drawer::start(){
    qDebug() << "start update!";
    k ++;
    update();
}
