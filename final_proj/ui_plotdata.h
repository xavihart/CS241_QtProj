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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_plotdata
{
public:
    QWidget *centralwidget;
    QDateTimeEdit *dateTimeEdit;
    QDateTimeEdit *dateTimeEdit_2;
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
        dateTimeEdit->setGeometry(QRect(30, 50, 194, 26));
        dateTimeEdit_2 = new QDateTimeEdit(centralwidget);
        dateTimeEdit_2->setObjectName(QStringLiteral("dateTimeEdit_2"));
        dateTimeEdit_2->setGeometry(QRect(280, 50, 194, 26));
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
    } // retranslateUi

};

namespace Ui {
    class plotdata: public Ui_plotdata {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLOTDATA_H
