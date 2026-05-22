#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include<QMainWindow>
#include<QPushButton>
#include<ZorkUL.h>
#include<Coin.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_heads();
    void on_tails();
    void on_pushButton_clicked();

private:
    void print(const QString& message);
    void println(const QString& message);

    Ui::MainWindow *ui;
    ZorkUL         *game;
    bool           dead;
    Coin           *coin;
};

#endif // MAINWINDOW_H
