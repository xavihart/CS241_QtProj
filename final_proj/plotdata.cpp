#include "plotdata.h"
#include "ui_plotdata.h"

plotdata::plotdata(QWidget * parent):
QMainWindow(parent),
ui(new Ui::plotdata)
{
  ui->setupUi(this);
  this->setWindowTitle("Plot data");
  cout << ui->dateTimeEdit->dateTime();
}

plotdata::~plotdata(){delete ui;}
