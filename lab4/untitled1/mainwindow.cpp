#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    game = new ZorkUL();
    updateRoomInfo();

}

MainWindow::~MainWindow()
{
    delete ui;
    delete game;
}


void MainWindow::on_btnWest_clicked()
{
    game->go("west");
    updateRoomInfo();
}

void MainWindow::on_btnNorth_clicked()
{
    game->go("north");
    updateRoomInfo();
}

void MainWindow::on_btnEast_clicked()
{
    game->go("east");
    updateRoomInfo();
}

void MainWindow::on_btnSouth_clicked()
{
    game->go("south");
    updateRoomInfo();
}

void MainWindow::on_btnTeleport_clicked()
{
    game->teleportRandom();
    updateRoomInfo();
}


void MainWindow::updateRoomInfo()
{
    QString info = QString::fromStdString(game->currentRoom->longDescription());
    ui->textEdit->setText(info);
}
