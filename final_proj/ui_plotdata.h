/********************************************************************************
** Form generated from reading UI file 'plotdata.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLOTDATA_H
#define UI_PLOTDATA_H

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
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLabel *step_hour;
    QLabel *step_min;
    QLabel *step_sec;
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
        dateTimeEdit_2 = new QDateTimeEdit(centralwidget);
        dateTimeEdit_2->setObjectName(QStringLiteral("dateTimeEdit_2"));
        dateTimeEdit_2->setGeometry(QRect(210, 20, 161, 26));
        plt = new QPushButton(centralwidget);
        plt->setObjectName(QStringLiteral("plt"));
        plt->setGeometry(QRect(640, 20, 89, 25));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(450, 20, 51, 25));
        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(450, 60, 51, 25));
        lineEdit_3 = new QLineEdit(centralwidget);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(450, 100, 51, 25));
        step_hour = new QLabel(centralwidget);
        step_hour->setObjectName(QStringLiteral("step_hour"));
        step_hour->setGeometry(QRect(510, 20, 67, 17));
        step_min = new QLabel(centralwidget);
        step_min->setObjectName(QStringLiteral("step_min"));
        step_min->setGeometry(QRect(510, 60, 71, 17));
        step_sec = new QLabel(centralwidget);
        step_sec->setObjectName(QStringLiteral("step_sec"));
        step_sec->setGeometry(QRect(510, 100, 67, 17));
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
        dateTimeEdit->setDisplayFormat(QApplication::translate("plotdata", "yyyy-MM-dd hh::mm::ss", nullptr));
        dateTimeEdit_2->setDisplayFormat(QApplication::translate("plotdata", "yyyy-MM-dd hh::mm::ss", nullptr));
        plt->setText(QApplication::translate("plotdata", "plot", nullptr));
        step_hour->setText(QApplication::translate("plotdata", "hour(s)", nullptr));
        step_min->setText(QApplication::translate("plotdata", "minutes(s)", nullptr));
        step_sec->setText(QApplication::translate("plotdata", "second(s)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class plotdata: public Ui_plotdata {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLOTDATA_H
