#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    coin = new Coin();
    connect(coin, SIGNAL(heads()), this, SLOT(on_heads()));
    connect(coin, SIGNAL(tails()), this, SLOT(on_tails()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete coin;
}

void MainWindow::on_pushButton_clicked()
{
    coin->flip();
}

void MainWindow::on_heads()
{
    ui->textEdit->append("HEADS!");

}

void MainWindow::on_tails()
{
    ui->textEdit->append("TAILS!");
}
