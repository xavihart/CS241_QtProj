/********************************************************************************
** Form generated from reading UI file 'plotdata.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLOTDATA_H
#define UI_PLOTDATA_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_plotdata
{
public:
    QWidget *centralwidget;
    QDateTimeEdit *dateTimeEdit;
    QDateTimeEdit *dateTimeEdit_2;
    QPushButton *plt;
    QLineEdit *step_hour;
    QLineEdit *step_min;
    QLineEdit *step_sec;
    QLabel *label_hour;
    QLabel *label_min;
    QLabel *label_sec;
    QLineEdit *stationnumber;
    QLabel *label_station;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_station_2;
    QLabel *label_station_3;
    QLabel *bkg;
    QPushButton *plotstation;
    QLabel *label_hour_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *plotdata)
    {
        if (plotdata->objectName().isEmpty())
            plotdata->setObjectName(QStringLiteral("plotdata"));
        plotdata->resize(642, 314);
        centralwidget = new QWidget(plotdata);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        dateTimeEdit = new QDateTimeEdit(centralwidget);
        dateTimeEdit->setObjectName(QStringLiteral("dateTimeEdit"));
        dateTimeEdit->setGeometry(QRect(60, 60, 191, 26));
        dateTimeEdit->setDate(QDate(2019, 1, 7));
        dateTimeEdit->setMinimumDateTime(QDateTime(QDate(2019, 1, 1), QTime(0, 0, 0)));
        dateTimeEdit->setMaximumDate(QDate(2019, 1, 13));
        dateTimeEdit->setMinimumDate(QDate(2019, 1, 1));
        dateTimeEdit->setMinimumTime(QTime(0, 0, 0));
        dateTimeEdit_2 = new QDateTimeEdit(centralwidget);
        dateTimeEdit_2->setObjectName(QStringLiteral("dateTimeEdit_2"));
        dateTimeEdit_2->setGeometry(QRect(60, 90, 191, 26));
        dateTimeEdit_2->setDate(QDate(2019, 1, 8));
        dateTimeEdit_2->setMaximumDate(QDate(2019, 1, 13));
        dateTimeEdit_2->setMinimumDate(QDate(2019, 1, 1));
        plt = new QPushButton(centralwidget);
        plt->setObjectName(QStringLiteral("plt"));
        plt->setGeometry(QRect(320, 140, 171, 25));
        step_hour = new QLineEdit(centralwidget);
        step_hour->setObjectName(QStringLiteral("step_hour"));
        step_hour->setGeometry(QRect(350, 50, 51, 21));
        step_min = new QLineEdit(centralwidget);
        step_min->setObjectName(QStringLiteral("step_min"));
        step_min->setGeometry(QRect(350, 80, 51, 21));
        step_sec = new QLineEdit(centralwidget);
        step_sec->setObjectName(QStringLiteral("step_sec"));
        step_sec->setGeometry(QRect(350, 110, 51, 21));
        label_hour = new QLabel(centralwidget);
        label_hour->setObjectName(QStringLiteral("label_hour"));
        label_hour->setGeometry(QRect(410, 50, 67, 17));
        label_hour->setStyleSheet(QStringLiteral("color: rgb(252, 233, 79);"));
        label_min = new QLabel(centralwidget);
        label_min->setObjectName(QStringLiteral("label_min"));
        label_min->setGeometry(QRect(410, 80, 71, 17));
        label_min->setStyleSheet(QStringLiteral("color: rgb(252, 233, 79);"));
        label_sec = new QLabel(centralwidget);
        label_sec->setObjectName(QStringLiteral("label_sec"));
        label_sec->setGeometry(QRect(410, 110, 67, 17));
        label_sec->setStyleSheet(QStringLiteral("color: rgb(252, 233, 79);"));
        stationnumber = new QLineEdit(centralwidget);
        stationnumber->setObjectName(QStringLiteral("stationnumber"));
        stationnumber->setGeometry(QRect(220, 220, 41, 31));
        label_station = new QLabel(centralwidget);
        label_station->setObjectName(QStringLiteral("label_station"));
        label_station->setGeometry(QRect(200, 220, 21, 17));
        label_station->setStyleSheet(QStringLiteral("color: rgb(252, 233, 79);"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(320, 20, 171, 21));
        QFont font;
        font.setPointSize(15);
        font.setBold(true);
        font.setWeight(75);
        label_3->setFont(font);
        label_3->setStyleSheet(QStringLiteral("color: rgb(252, 233, 79);"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(30, 220, 151, 21));
        label_4->setFont(font);
        label_4->setStyleSheet(QStringLiteral("color: rgb(252, 233, 79);"));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 20, 271, 21));
        label_5->setFont(font);
        label_5->setStyleSheet(QStringLiteral("color: rgb(252, 233, 79);"));
        label_station_2 = new QLabel(centralwidget);
        label_station_2->setObjectName(QStringLiteral("label_station_2"));
        label_station_2->setGeometry(QRect(20, 50, 41, 17));
        label_station_2->setStyleSheet(QStringLiteral("color: rgb(252, 233, 79);"));
        label_station_3 = new QLabel(centralwidget);
        label_station_3->setObjectName(QStringLiteral("label_station_3"));
        label_station_3->setGeometry(QRect(30, 80, 21, 17));
        label_station_3->setStyleSheet(QStringLiteral("color: rgb(252, 233, 79);"));
        bkg = new QLabel(centralwidget);
        bkg->setObjectName(QStringLiteral("bkg"));
        bkg->setGeometry(QRect(0, 0, 841, 291));
        plotstation = new QPushButton(centralwidget);
        plotstation->setObjectName(QStringLiteral("plotstation"));
        plotstation->setGeometry(QRect(320, 230, 171, 25));
        label_hour_2 = new QLabel(centralwidget);
        label_hour_2->setObjectName(QStringLiteral("label_hour_2"));
        label_hour_2->setGeometry(QRect(320, 210, 171, 17));
        label_hour_2->setStyleSheet(QStringLiteral("color: rgb(252, 233, 79);"));
        plotdata->setCentralWidget(centralwidget);
        menubar = new QMenuBar(plotdata);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 642, 22));
        plotdata->setMenuBar(menubar);
        statusbar = new QStatusBar(plotdata);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        plotdata->setStatusBar(statusbar);

        retranslateUi(plotdata);

        QMetaObject::connectSlotsByName(plotdata);
    } // setupUi

    void retranslateUi(QMainWindow *plotdata)
    {
        plotdata->setWindowTitle(QApplication::translate("plotdata", "MainWindow", nullptr));
        dateTimeEdit->setDisplayFormat(QApplication::translate("plotdata", "2019-01-dd hh::mm::ss", nullptr));
        dateTimeEdit_2->setDisplayFormat(QApplication::translate("plotdata", "2019-01-dd hh::mm::ss", nullptr));
        plt->setText(QApplication::translate("plotdata", "PLot in-out flow", nullptr));
        label_hour->setText(QApplication::translate("plotdata", "hour(s)", nullptr));
        label_min->setText(QApplication::translate("plotdata", "minutes(s)", nullptr));
        label_sec->setText(QApplication::translate("plotdata", "second(s)", nullptr));
        label_station->setText(QApplication::translate("plotdata", "ID", nullptr));
        label_3->setText(QApplication::translate("plotdata", "Time Step Setting", nullptr));
        label_4->setText(QApplication::translate("plotdata", "Station Setting", nullptr));
        label_5->setText(QApplication::translate("plotdata", "Query Time Area Setting", nullptr));
        label_station_2->setText(QApplication::translate("plotdata", "From", nullptr));
        label_station_3->setText(QApplication::translate("plotdata", "To", nullptr));
        bkg->setText(QString());
        plotstation->setText(QApplication::translate("plotdata", "Plot", nullptr));
        label_hour_2->setText(QApplication::translate("plotdata", "Station Crowding Degree", nullptr));
    } // retranslateUi

};

namespace Ui {
    class plotdata: public Ui_plotdata {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLOTDATA_H
