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
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QProgressBar>
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
    QPushButton *pushButton_2;
    QLineEdit *start;
    QLineEdit *dest;
    QTextEdit *showroute;
    QPlainTextEdit *plainTextEdit;
    QLabel *map;
    QLabel *label_2;
    QPlainTextEdit *plainTextEdit_2;
    QPlainTextEdit *plainTextEdit_3;
    QLabel *logo;
    QProgressBar *pgb;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1000, 500);
        QFont font;
        font.setPointSize(11);
        MainWindow->setFont(font);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(790, 360, 121, 41));
        pushButton->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton->setStyleSheet(QStringLiteral("color: rgb(238, 238, 236);"));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(80, 380, 89, 25));
        pushButton_2->setFont(font);
        start = new QLineEdit(centralWidget);
        start->setObjectName(QStringLiteral("start"));
        start->setGeometry(QRect(300, 170, 81, 31));
        dest = new QLineEdit(centralWidget);
        dest->setObjectName(QStringLiteral("dest"));
        dest->setGeometry(QRect(830, 170, 81, 31));
        showroute = new QTextEdit(centralWidget);
        showroute->setObjectName(QStringLiteral("showroute"));
        showroute->setGeometry(QRect(100, 210, 811, 141));
        QFont font1;
        font1.setPointSize(15);
        font1.setBold(true);
        font1.setWeight(75);
        showroute->setFont(font1);
        showroute->setStyleSheet(QLatin1String("background-color: rgb(211, 215, 207);\n"
"color: rgb(32, 74, 135);"));
        plainTextEdit = new QPlainTextEdit(centralWidget);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(340, 50, 351, 71));
        QFont font2;
        font2.setFamily(QStringLiteral("Source Code Pro"));
        font2.setPointSize(30);
        font2.setBold(true);
        font2.setItalic(false);
        font2.setUnderline(false);
        font2.setWeight(75);
        font2.setStyleStrategy(QFont::PreferDefault);
        plainTextEdit->setFont(font2);
        plainTextEdit->viewport()->setProperty("cursor", QVariant(QCursor(Qt::ArrowCursor)));
        plainTextEdit->setLayoutDirection(Qt::LeftToRight);
        plainTextEdit->setStyleSheet(QStringLiteral("color: rgb(52, 101, 164);"));
        plainTextEdit->setOverwriteMode(false);
        map = new QLabel(centralWidget);
        map->setObjectName(QStringLiteral("map"));
        map->setGeometry(QRect(40, 10, 861, 431));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(90, 450, 601, 91));
        plainTextEdit_2 = new QPlainTextEdit(centralWidget);
        plainTextEdit_2->setObjectName(QStringLiteral("plainTextEdit_2"));
        plainTextEdit_2->setGeometry(QRect(100, 170, 191, 31));
        QFont font3;
        font3.setBold(true);
        font3.setItalic(false);
        font3.setUnderline(false);
        font3.setWeight(75);
        font3.setStyleStrategy(QFont::PreferAntialias);
        plainTextEdit_2->setFont(font3);
        plainTextEdit_2->setLayoutDirection(Qt::LeftToRight);
        plainTextEdit_2->setOverwriteMode(false);
        plainTextEdit_3 = new QPlainTextEdit(centralWidget);
        plainTextEdit_3->setObjectName(QStringLiteral("plainTextEdit_3"));
        plainTextEdit_3->setGeometry(QRect(620, 170, 201, 31));
        plainTextEdit_3->setFont(font3);
        plainTextEdit_3->setLayoutDirection(Qt::LeftToRight);
        plainTextEdit_3->setOverwriteMode(false);
        logo = new QLabel(centralWidget);
        logo->setObjectName(QStringLiteral("logo"));
        logo->setGeometry(QRect(20, 10, 111, 111));
        pgb = new QProgressBar(centralWidget);
        pgb->setObjectName(QStringLiteral("pgb"));
        pgb->setGeometry(QRect(870, 10, 118, 23));
        pgb->setValue(24);
        MainWindow->setCentralWidget(centralWidget);
        map->raise();
        pushButton->raise();
        pushButton_2->raise();
        start->raise();
        dest->raise();
        showroute->raise();
        plainTextEdit->raise();
        label_2->raise();
        plainTextEdit_2->raise();
        plainTextEdit_3->raise();
        logo->raise();
        pgb->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1000, 22));
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
        pushButton_2->setText(QApplication::translate("MainWindow", "PushButton", nullptr));
        showroute->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:15pt; font-weight:600; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        plainTextEdit->setDocumentTitle(QString());
        plainTextEdit->setPlainText(QApplication::translate("MainWindow", "Route Advising", nullptr));
        map->setText(QString());
        label_2->setText(QString());
        plainTextEdit_2->setDocumentTitle(QString());
        plainTextEdit_2->setPlainText(QApplication::translate("MainWindow", "DEPARTURE STATION", nullptr));
        plainTextEdit_3->setDocumentTitle(QString());
        plainTextEdit_3->setPlainText(QApplication::translate("MainWindow", "DESTINATION STATION", nullptr));
        logo->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
