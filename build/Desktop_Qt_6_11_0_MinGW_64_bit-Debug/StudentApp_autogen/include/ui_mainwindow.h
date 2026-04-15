/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_6;
    QPushButton *Add;
    QPushButton *Delete;
    QPushButton *Search;
    QPushButton *Exit;
    QPushButton *Update;
    QPushButton *ViewAll;
    QTableWidget *tableWidget;
    QPushButton *refresh;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1835, 895);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(120, 20, 521, 131));
        label->setStyleSheet(QString::fromUtf8("QLabel{\n"
"font-size:30px;\n"
"}"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(80, 200, 81, 31));
        label_2->setStyleSheet(QString::fromUtf8("QLabel{\n"
"font-size:20px;\n"
"}"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(80, 260, 81, 31));
        label_3->setStyleSheet(QString::fromUtf8("QLabel{\n"
"font-size:20px;\n"
"}"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(80, 320, 81, 31));
        label_4->setStyleSheet(QString::fromUtf8("QLabel{\n"
"font-size:20px;\n"
"}"));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(80, 380, 81, 31));
        label_5->setStyleSheet(QString::fromUtf8("QLabel{\n"
"font-size:20px;\n"
"}"));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(80, 440, 81, 31));
        label_6->setStyleSheet(QString::fromUtf8("QLabel{\n"
"font-size:20px;\n"
"}"));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(80, 500, 81, 31));
        label_7->setStyleSheet(QString::fromUtf8("QLabel{\n"
"font-size:20px;\n"
"}"));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(220, 210, 251, 21));
        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(220, 270, 251, 21));
        lineEdit_3 = new QLineEdit(centralwidget);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(220, 330, 251, 21));
        lineEdit_4 = new QLineEdit(centralwidget);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(220, 390, 251, 21));
        lineEdit_5 = new QLineEdit(centralwidget);
        lineEdit_5->setObjectName("lineEdit_5");
        lineEdit_5->setGeometry(QRect(220, 450, 251, 21));
        lineEdit_6 = new QLineEdit(centralwidget);
        lineEdit_6->setObjectName("lineEdit_6");
        lineEdit_6->setGeometry(QRect(220, 510, 251, 21));
        Add = new QPushButton(centralwidget);
        Add->setObjectName("Add");
        Add->setGeometry(QRect(550, 210, 93, 29));
        Delete = new QPushButton(centralwidget);
        Delete->setObjectName("Delete");
        Delete->setGeometry(QRect(550, 430, 93, 29));
        Search = new QPushButton(centralwidget);
        Search->setObjectName("Search");
        Search->setGeometry(QRect(550, 350, 93, 29));
        Exit = new QPushButton(centralwidget);
        Exit->setObjectName("Exit");
        Exit->setGeometry(QRect(180, 620, 93, 29));
        Update = new QPushButton(centralwidget);
        Update->setObjectName("Update");
        Update->setGeometry(QRect(550, 500, 93, 29));
        ViewAll = new QPushButton(centralwidget);
        ViewAll->setObjectName("ViewAll");
        ViewAll->setGeometry(QRect(550, 280, 93, 29));
        tableWidget = new QTableWidget(centralwidget);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(700, 140, 651, 631));
        refresh = new QPushButton(centralwidget);
        refresh->setObjectName("refresh");
        refresh->setGeometry(QRect(410, 620, 93, 29));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1835, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Student Record Management System", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Name:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Roll:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Father:", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Mother:", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Class:", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Batch:", nullptr));
        Add->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        Delete->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        Search->setText(QCoreApplication::translate("MainWindow", "Search", nullptr));
        Exit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        Update->setText(QCoreApplication::translate("MainWindow", "Update", nullptr));
        ViewAll->setText(QCoreApplication::translate("MainWindow", "View All", nullptr));
        refresh->setText(QCoreApplication::translate("MainWindow", "Refresh", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
