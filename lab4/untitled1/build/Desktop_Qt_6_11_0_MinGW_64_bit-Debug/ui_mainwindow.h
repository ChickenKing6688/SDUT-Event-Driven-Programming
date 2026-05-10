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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTextEdit *textEdit;
    QPushButton *btnWest;
    QPushButton *btnNorth;
    QPushButton *btnEast;
    QPushButton *btnSouth;
    QPushButton *btnTeleport;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1068, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(200, 10, 651, 271));
        btnWest = new QPushButton(centralwidget);
        btnWest->setObjectName("btnWest");
        btnWest->setGeometry(QRect(200, 280, 171, 101));
        btnNorth = new QPushButton(centralwidget);
        btnNorth->setObjectName("btnNorth");
        btnNorth->setGeometry(QRect(370, 280, 161, 51));
        btnEast = new QPushButton(centralwidget);
        btnEast->setObjectName("btnEast");
        btnEast->setGeometry(QRect(530, 280, 171, 101));
        btnSouth = new QPushButton(centralwidget);
        btnSouth->setObjectName("btnSouth");
        btnSouth->setGeometry(QRect(370, 330, 161, 51));
        btnTeleport = new QPushButton(centralwidget);
        btnTeleport->setObjectName("btnTeleport");
        btnTeleport->setGeometry(QRect(700, 280, 151, 101));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1068, 18));
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
        btnWest->setText(QCoreApplication::translate("MainWindow", "West", nullptr));
        btnNorth->setText(QCoreApplication::translate("MainWindow", "North", nullptr));
        btnEast->setText(QCoreApplication::translate("MainWindow", "East", nullptr));
        btnSouth->setText(QCoreApplication::translate("MainWindow", "South", nullptr));
        btnTeleport->setText(QCoreApplication::translate("MainWindow", "Teleport", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
