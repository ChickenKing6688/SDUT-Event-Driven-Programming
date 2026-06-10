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
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
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
    QPushButton *btnMap;
    QLabel *label;
    QProgressBar *staminaBar;
    QLabel *label_2;
    QProgressBar *progressBar;
    QTextEdit *treasureList;
    QPushButton *btnTakeTreasure;
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
        btnTeleport->setGeometry(QRect(700, 280, 151, 51));
        btnMap = new QPushButton(centralwidget);
        btnMap->setObjectName("btnMap");
        btnMap->setGeometry(QRect(700, 330, 151, 51));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(200, 390, 101, 21));
        staminaBar = new QProgressBar(centralwidget);
        staminaBar->setObjectName("staminaBar");
        staminaBar->setGeometry(QRect(300, 390, 401, 23));
        staminaBar->setValue(30);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(200, 430, 101, 21));
        progressBar = new QProgressBar(centralwidget);
        progressBar->setObjectName("progressBar");
        progressBar->setGeometry(QRect(300, 430, 401, 23));
        progressBar->setValue(0);
        treasureList = new QTextEdit(centralwidget);
        treasureList->setObjectName("treasureList");
        treasureList->setGeometry(QRect(200, 460, 501, 81));
        treasureList->setReadOnly(true);
        btnTakeTreasure = new QPushButton(centralwidget);
        btnTakeTreasure->setObjectName("btnTakeTreasure");
        btnTakeTreasure->setGeometry(QRect(200, 540, 501, 31));
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
        btnWest->setText(QCoreApplication::translate("MainWindow", "\350\245\277", nullptr));
        btnNorth->setText(QCoreApplication::translate("MainWindow", "\345\214\227", nullptr));
        btnEast->setText(QCoreApplication::translate("MainWindow", "\344\270\234", nullptr));
        btnSouth->setText(QCoreApplication::translate("MainWindow", "\345\215\227", nullptr));
        btnTeleport->setText(QCoreApplication::translate("MainWindow", "\351\232\217\346\234\272\344\274\240\351\200\201", nullptr));
        btnMap->setText(QCoreApplication::translate("MainWindow", "\346\230\276\347\244\272\345\234\260\345\233\276", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\344\275\223\345\212\233:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\345\256\235\347\211\251\346\224\266\351\233\206\350\277\233\345\272\246:", nullptr));
        btnTakeTreasure->setText(QCoreApplication::translate("MainWindow", "\346\213\276\345\217\226\345\275\223\345\211\215\346\210\277\351\227\264\347\232\204\345\256\235\347\211\251", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
