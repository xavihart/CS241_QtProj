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
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *plotdata)
    {
        if (plotdata->objectName().isEmpty())
            plotdata->setObjectName(QStringLiteral("plotdata"));
        plotdata->resize(800, 600);
        centralwidget = new QWidget(plotdata);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        dateTimeEdit = new QDateTimeEdit(centralwidget);
        dateTimeEdit->setObjectName(QStringLiteral("dateTimeEdit"));
        dateTimeEdit->setGeometry(QRect(20, 20, 171, 26));
        dateTimeEdit->setDate(QDate(2019, 1, 1));
        dateTimeEdit->setMinimumDateTime(QDateTime(QDate(2019, 1, 1), QTime(0, 0, 0)));
        dateTimeEdit->setMaximumDate(QDate(2019, 1, 13));
        dateTimeEdit->setMinimumDate(QDate(2019, 1, 1));
        dateTimeEdit->setMinimumTime(QTime(0, 0, 0));
        dateTimeEdit_2 = new QDateTimeEdit(centralwidget);
        dateTimeEdit_2->setObjectName(QStringLiteral("dateTimeEdit_2"));
        dateTimeEdit_2->setGeometry(QRect(210, 20, 161, 26));
        dateTimeEdit_2->setDate(QDate(2019, 1, 1));
        dateTimeEdit_2->setMaximumDate(QDate(2019, 1, 13));
        dateTimeEdit_2->setMinimumDate(QDate(2019, 1, 1));
        plt = new QPushButton(centralwidget);
        plt->setObjectName(QStringLiteral("plt"));
        plt->setGeometry(QRect(640, 20, 89, 25));
        step_hour = new QLineEdit(centralwidget);
        step_hour->setObjectName(QStringLiteral("step_hour"));
        step_hour->setGeometry(QRect(450, 20, 51, 25));
        step_min = new QLineEdit(centralwidget);
        step_min->setObjectName(QStringLiteral("step_min"));
        step_min->setGeometry(QRect(450, 60, 51, 25));
        step_sec = new QLineEdit(centralwidget);
        step_sec->setObjectName(QStringLiteral("step_sec"));
        step_sec->setGeometry(QRect(450, 100, 51, 25));
        label_hour = new QLabel(centralwidget);
        label_hour->setObjectName(QStringLiteral("label_hour"));
        label_hour->setGeometry(QRect(510, 20, 67, 17));
        label_min = new QLabel(centralwidget);
        label_min->setObjectName(QStringLiteral("label_min"));
        label_min->setGeometry(QRect(510, 60, 71, 17));
        label_sec = new QLabel(centralwidget);
        label_sec->setObjectName(QStringLiteral("label_sec"));
        label_sec->setGeometry(QRect(510, 100, 67, 17));
        stationnumber = new QLineEdit(centralwidget);
        stationnumber->setObjectName(QStringLiteral("stationnumber"));
        stationnumber->setGeometry(QRect(450, 140, 51, 25));
        label_station = new QLabel(centralwidget);
        label_station->setObjectName(QStringLiteral("label_station"));
        label_station->setGeometry(QRect(520, 140, 67, 17));
        plotdata->setCentralWidget(centralwidget);
        menubar = new QMenuBar(plotdata);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
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
        plt->setText(QApplication::translate("plotdata", "plot", nullptr));
        label_hour->setText(QApplication::translate("plotdata", "hour(s)", nullptr));
        label_min->setText(QApplication::translate("plotdata", "minutes(s)", nullptr));
        label_sec->setText(QApplication::translate("plotdata", "second(s)", nullptr));
        label_station->setText(QApplication::translate("plotdata", "station", nullptr));
    } // retranslateUi

};

namespace Ui {
    class plotdata: public Ui_plotdata {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLOTDATA_H
