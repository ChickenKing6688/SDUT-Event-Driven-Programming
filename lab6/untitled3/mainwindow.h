#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include<QMainWindow>
#include<QPushButton>
#include "ZorkUL.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void updateRoomInfo();

private slots:
    void on_btnNorth_clicked();
    void on_btnSouth_clicked();
    void on_btnEast_clicked();
    void on_btnWest_clicked();
    void on_btnTeleport_clicked();
    void on_btnTakeTreasure_clicked();
    void on_btnMap_clicked();

private:
    void print(const QString& message);
    void println(const QString& message);

    Ui::MainWindow *ui;
    ZorkUL         *game;
    bool           dead;
};

#endif // MAINWINDOW_H
