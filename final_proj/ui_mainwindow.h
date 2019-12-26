/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QLineEdit *start;
    QLineEdit *dest;
    QTextEdit *showroute;
    QLabel *label_2;
    QLabel *logo;
    QLabel *label;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *bkg;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(850, 381);
        QFont font;
        font.setPointSize(11);
        MainWindow->setFont(font);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(680, 220, 161, 51));
        pushButton->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton->setStyleSheet(QStringLiteral("color: rgb(238, 238, 236);"));
        start = new QLineEdit(centralWidget);
        start->setObjectName(QStringLiteral("start"));
        start->setGeometry(QRect(190, 100, 51, 31));
        start->setStyleSheet(QStringLiteral(""));
        dest = new QLineEdit(centralWidget);
        dest->setObjectName(QStringLiteral("dest"));
        dest->setGeometry(QRect(190, 180, 51, 31));
        showroute = new QTextEdit(centralWidget);
        showroute->setObjectName(QStringLiteral("showroute"));
        showroute->setGeometry(QRect(260, 100, 581, 111));
        QFont font1;
        font1.setPointSize(15);
        font1.setBold(true);
        font1.setWeight(75);
        showroute->setFont(font1);
        showroute->setStyleSheet(QLatin1String("color: rgb(136, 138, 133);\n"
"background-color: rgb(255, 255, 255);"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(90, 450, 601, 91));
        logo = new QLabel(centralWidget);
        logo->setObjectName(QStringLiteral("logo"));
        logo->setGeometry(QRect(160, 20, 50, 50));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(230, 20, 501, 51));
        QFont font2;
        font2.setPointSize(26);
        font2.setBold(true);
        font2.setWeight(75);
        label->setFont(font2);
        label->setStyleSheet(QStringLiteral("color: rgb(32, 74, 135);"));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(30, 100, 151, 17));
        QFont font3;
        font3.setFamily(QStringLiteral("TeX Gyre Adventor"));
        font3.setBold(true);
        font3.setWeight(75);
        label_4->setFont(font3);
        label_4->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(30, 180, 161, 17));
        label_5->setFont(font3);
        label_5->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        bkg = new QLabel(centralWidget);
        bkg->setObjectName(QStringLiteral("bkg"));
        bkg->setGeometry(QRect(0, 0, 881, 421));
        bkg->setStyleSheet(QStringLiteral("color: rgb(238, 238, 236);"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 850, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "Ask For Routes", nullptr));
        showroute->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:15pt; font-weight:600; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        label_2->setText(QString());
        logo->setText(QString());
        label->setText(QApplication::translate("MainWindow", "Metro Route Planning System", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "Departure :StationID:", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "Destination :StationID:", nullptr));
        bkg->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
