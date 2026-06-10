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
    string result = game->go("west");
    if (result != "direction null") {
        game->getCharacter().consumeStamina();
    }
    updateRoomInfo();
}

void MainWindow::on_btnNorth_clicked()
{
    string result = game->go("north");
    if (result != "direction null") {
        game->getCharacter().consumeStamina();
    }
    updateRoomInfo();
}

void MainWindow::on_btnEast_clicked()
{
    string result = game->go("east");
    if (result != "direction null") {
        game->getCharacter().consumeStamina();
    }
    updateRoomInfo();
}

void MainWindow::on_btnSouth_clicked()
{
    string result = game->go("south");
    if (result != "direction null") {
        game->getCharacter().consumeStamina();
    }
    updateRoomInfo();
}

void MainWindow::on_btnTeleport_clicked()
{
    game->teleport();
    game->getCharacter().consumeStamina();
    updateRoomInfo();
}

void MainWindow::on_btnTakeTreasure_clicked()
{
    string result = game->takeAllTreasures();
    QString info = QString::fromStdString(result);
    ui->textEdit->setText(info);
    updateRoomInfo();
}

void MainWindow::on_btnMap_clicked()
{
    string map = game->getMap();
    QString info = QString::fromStdString(map);
    ui->textEdit->setText(info);
}


void MainWindow::updateRoomInfo()
{
    QString info = QString::fromStdString(game->getCurrentRoomDescription());
    ui->textEdit->setText(info);
    
    int stamina = game->getStamina();
    ui->staminaBar->setMaximum(30);
    ui->staminaBar->setValue(stamina);
    
    int collected = game->getCollectedTreasureCount();
    ui->progressBar->setMaximum(9);
    ui->progressBar->setValue(collected);
    
    QString treasureInfo = QString::fromStdString(game->getCollectedTreasures());
    ui->treasureList->setText(treasureInfo);
    
    if (game->checkWin()) {
        ui->textEdit->setText("恭喜！你收集了所有宝物并到达了终点j房间，你赢了！");
    }
    
    if (stamina <= 0) {
        ui->textEdit->setText("体力耗尽！游戏结束！");
    }
}
