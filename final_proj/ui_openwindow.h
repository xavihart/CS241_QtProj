/********************************************************************************
** Form generated from reading UI file 'openwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPENWINDOW_H
#define UI_OPENWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_openwindow
{
public:
    QWidget *centralwidget;
    QPushButton *advicing_route;
    QPushButton *data_plotting;
    QPushButton *download_data;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *openwindow)
    {
        if (openwindow->objectName().isEmpty())
            openwindow->setObjectName(QStringLiteral("openwindow"));
        openwindow->resize(460, 326);
        centralwidget = new QWidget(openwindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        advicing_route = new QPushButton(centralwidget);
        advicing_route->setObjectName(QStringLiteral("advicing_route"));
        advicing_route->setGeometry(QRect(40, 30, 121, 25));
        data_plotting = new QPushButton(centralwidget);
        data_plotting->setObjectName(QStringLiteral("data_plotting"));
        data_plotting->setGeometry(QRect(40, 70, 89, 25));
        download_data = new QPushButton(centralwidget);
        download_data->setObjectName(QStringLiteral("download_data"));
        download_data->setGeometry(QRect(40, 110, 131, 25));
        openwindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(openwindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 460, 22));
        openwindow->setMenuBar(menubar);
        statusbar = new QStatusBar(openwindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        openwindow->setStatusBar(statusbar);

        retranslateUi(openwindow);

        QMetaObject::connectSlotsByName(openwindow);
    } // setupUi

    void retranslateUi(QMainWindow *openwindow)
    {
        openwindow->setWindowTitle(QApplication::translate("openwindow", "MainWindow", nullptr));
        advicing_route->setText(QApplication::translate("openwindow", "Adiving route ", nullptr));
        data_plotting->setText(QApplication::translate("openwindow", "data ploting ", nullptr));
        download_data->setText(QApplication::translate("openwindow", "download data", nullptr));
    } // retranslateUi

};

namespace Ui {
    class openwindow: public Ui_openwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPENWINDOW_H
