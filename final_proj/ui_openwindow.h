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
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
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
    QProgressBar *progressBar;
    QLabel *label;
    QLabel *bkg;
    QLabel *label_2;
    QLabel *label_4;
    QCheckBox *checkBox_12;
    QCheckBox *checkBox_13;
    QCheckBox *checkBox_14;
    QCheckBox *checkBox_15;
    QCheckBox *checkBox_16;
    QCheckBox *checkBox_9;
    QCheckBox *checkBox_10;
    QCheckBox *checkBox_11;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayout_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *openwindow)
    {
        if (openwindow->objectName().isEmpty())
            openwindow->setObjectName(QStringLiteral("openwindow"));
        openwindow->resize(769, 390);
        QIcon icon;
        icon.addFile(QStringLiteral("../dataset_CS241/pic/logo.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        openwindow->setWindowIcon(icon);
        centralwidget = new QWidget(openwindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        advicing_route = new QPushButton(centralwidget);
        advicing_route->setObjectName(QStringLiteral("advicing_route"));
        advicing_route->setGeometry(QRect(40, 120, 151, 41));
        advicing_route->setCursor(QCursor(Qt::PointingHandCursor));
        advicing_route->setStyleSheet(QLatin1String("QPushButton { background-color: rgb(30, 144, 252\n"
"); border-radius: 3px; color: rgb(255, 255, 255); } QPushButton:hover { background-color: rgb(245, 69, 234); }"));
        data_plotting = new QPushButton(centralwidget);
        data_plotting->setObjectName(QStringLiteral("data_plotting"));
        data_plotting->setGeometry(QRect(40, 230, 151, 41));
        data_plotting->setStyleSheet(QLatin1String("QPushButton { background-color: rgb(30, 144, 250\n"
"); border-radius: 3px; color: rgb(255, 255, 255); } QPushButton:hover { background-color: rgb(245, 69, 234); }"));
        download_data = new QPushButton(centralwidget);
        download_data->setObjectName(QStringLiteral("download_data"));
        download_data->setGeometry(QRect(530, 210, 201, 41));
        download_data->setCursor(QCursor(Qt::PointingHandCursor));
        download_data->setStyleSheet(QLatin1String("QPushButton { background-color: rgb(30, 144, 255\n"
"); border-radius: 3px; color: rgb(255, 255, 255); } QPushButton:hover { background-color: rgb(245, 69, 234); }"));
        progressBar = new QProgressBar(centralwidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(30, 320, 691, 16));
        progressBar->setValue(0);
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(150, 0, 501, 41));
        QFont font;
        font.setFamily(QStringLiteral("Ubuntu"));
        font.setPointSize(20);
        font.setBold(true);
        font.setItalic(false);
        font.setWeight(75);
        label->setFont(font);
        bkg = new QLabel(centralwidget);
        bkg->setObjectName(QStringLiteral("bkg"));
        bkg->setGeometry(QRect(-20, 0, 791, 471));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(260, 30, 231, 31));
        QFont font1;
        font1.setPointSize(20);
        font1.setBold(true);
        font1.setWeight(75);
        label_2->setFont(font1);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(300, 290, 311, 31));
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        label_4->setFont(font2);
        label_4->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        checkBox_12 = new QCheckBox(centralwidget);
        checkBox_12->setObjectName(QStringLiteral("checkBox_12"));
        checkBox_12->setGeometry(QRect(650, 180, 92, 23));
        QFont font3;
        font3.setBold(true);
        font3.setWeight(75);
        checkBox_12->setFont(font3);
        checkBox_12->setStyleSheet(QStringLiteral("color: rgb(211, 215, 207);"));
        checkBox_13 = new QCheckBox(centralwidget);
        checkBox_13->setObjectName(QStringLiteral("checkBox_13"));
        checkBox_13->setGeometry(QRect(650, 120, 81, 23));
        checkBox_13->setFont(font3);
        checkBox_13->setStyleSheet(QStringLiteral("color: rgb(211, 215, 207);"));
        checkBox_14 = new QCheckBox(centralwidget);
        checkBox_14->setObjectName(QStringLiteral("checkBox_14"));
        checkBox_14->setGeometry(QRect(530, 160, 92, 23));
        checkBox_14->setFont(font3);
        checkBox_14->setStyleSheet(QLatin1String("\n"
"color: rgb(186, 189, 182);"));
        checkBox_14->setChecked(true);
        checkBox_15 = new QCheckBox(centralwidget);
        checkBox_15->setObjectName(QStringLiteral("checkBox_15"));
        checkBox_15->setGeometry(QRect(650, 160, 92, 23));
        checkBox_15->setFont(font3);
        checkBox_15->setStyleSheet(QStringLiteral("color: rgb(211, 215, 207);"));
        checkBox_16 = new QCheckBox(centralwidget);
        checkBox_16->setObjectName(QStringLiteral("checkBox_16"));
        checkBox_16->setGeometry(QRect(530, 180, 92, 23));
        checkBox_16->setFont(font3);
        checkBox_16->setStyleSheet(QLatin1String("\n"
"color: rgb(186, 189, 182);"));
        checkBox_16->setChecked(true);
        checkBox_9 = new QCheckBox(centralwidget);
        checkBox_9->setObjectName(QStringLiteral("checkBox_9"));
        checkBox_9->setGeometry(QRect(530, 120, 92, 23));
        checkBox_9->setFont(font3);
        checkBox_9->setStyleSheet(QLatin1String("\n"
"color: rgb(186, 189, 182);"));
        checkBox_9->setChecked(true);
        checkBox_10 = new QCheckBox(centralwidget);
        checkBox_10->setObjectName(QStringLiteral("checkBox_10"));
        checkBox_10->setGeometry(QRect(530, 140, 92, 23));
        checkBox_10->setFont(font3);
        checkBox_10->setStyleSheet(QLatin1String("\n"
"color: rgb(186, 189, 182);"));
        checkBox_10->setChecked(true);
        checkBox_11 = new QCheckBox(centralwidget);
        checkBox_11->setObjectName(QStringLiteral("checkBox_11"));
        checkBox_11->setGeometry(QRect(650, 140, 71, 23));
        checkBox_11->setFont(font3);
        checkBox_11->setStyleSheet(QStringLiteral("color: rgb(211, 215, 207);"));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 100, 241, 17));
        QFont font4;
        font4.setFamily(QStringLiteral("Noto Serif CJK SC"));
        font4.setBold(true);
        font4.setItalic(false);
        font4.setWeight(75);
        label_5->setFont(font4);
        label_5->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(0, 210, 281, 17));
        label_6->setFont(font4);
        label_6->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(530, 100, 221, 17));
        QFont font5;
        font5.setFamily(QStringLiteral("Noto Serif CJK SC"));
        font5.setPointSize(12);
        font5.setBold(true);
        font5.setItalic(false);
        font5.setWeight(75);
        label_7->setFont(font5);
        label_7->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        formLayoutWidget = new QWidget(centralwidget);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(10, -1, 741, 91));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        gridLayoutWidget_3 = new QWidget(centralwidget);
        gridLayoutWidget_3->setObjectName(QStringLiteral("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(10, 280, 741, 61));
        gridLayout_3 = new QGridLayout(gridLayoutWidget_3);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        openwindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(openwindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 769, 22));
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
        advicing_route->setText(QApplication::translate("openwindow", "Route Planning", nullptr));
        data_plotting->setText(QApplication::translate("openwindow", "Traffic Visualization", nullptr));
        download_data->setText(QApplication::translate("openwindow", "Download Data", nullptr));
        label->setText(QApplication::translate("openwindow", "Welcome to Hangzhou Metro Traffic ", nullptr));
        bkg->setText(QString());
        label_2->setText(QApplication::translate("openwindow", "Analysing System", nullptr));
        label_4->setText(QApplication::translate("openwindow", "Data loading progress", nullptr));
        checkBox_12->setText(QApplication::translate("openwindow", "DeviceID", nullptr));
        checkBox_13->setText(QApplication::translate("openwindow", "Paytype", nullptr));
        checkBox_14->setText(QApplication::translate("openwindow", "Status", nullptr));
        checkBox_15->setText(QApplication::translate("openwindow", "UserID", nullptr));
        checkBox_16->setText(QApplication::translate("openwindow", "Adjmap", nullptr));
        checkBox_9->setText(QApplication::translate("openwindow", "Time", nullptr));
        checkBox_10->setText(QApplication::translate("openwindow", "StaionID", nullptr));
        checkBox_11->setText(QApplication::translate("openwindow", "LineID", nullptr));
        label_5->setText(QApplication::translate("openwindow", "Make metro route advicing", nullptr));
        label_6->setText(QApplication::translate("openwindow", "Make visualization of traffic flow", nullptr));
        label_7->setText(QApplication::translate("openwindow", "Choose the data you want", nullptr));
    } // retranslateUi

};

namespace Ui {
    class openwindow: public Ui_openwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPENWINDOW_H
