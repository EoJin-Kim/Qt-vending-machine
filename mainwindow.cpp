#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <stdio.h>
#include <QString>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pbCoffe->setEnabled(false);
    ui->pbTee->setEnabled(false);
    ui->pbMilk->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;

}
void MainWindow::buy(int diff)
{
    money-=diff;
    ui->lcdNumber->display(money);
    enableButton();
}
void MainWindow::enableButton()
{
    if (money>=100)
    {
        ui->pbCoffe->setEnabled(true);
    }
    else
    {
        ui->pbCoffe->setEnabled(false);
    }
    if (money>=150)
    {
        ui->pbTee->setEnabled(true);
    }
    else
    {
        ui->pbTee->setEnabled(false);
    }
    if (money>=200)
    {
        ui->pbMilk->setEnabled(true);
    }
    else
    {
        ui->pbMilk->setEnabled(false);
    }
}

void MainWindow::ResetMoney()
{
    QString Reset_string;
    int money_500 = money/500;
    int money_100 = money%500/100;
    int money_50 = money%500%100/50;
    int money_10 = money%500%100%50/10;
    Reset_string=QString("500 : %1\n100 : %2\n50 : %3\n10 : %4").arg(money_500).arg(money_100).arg(money_50).arg(money_10);

    QMessageBox m;
    m.information(nullptr,"aaaa",Reset_string);
    money=0;
    ui->lcdNumber->display(money);

}
void MainWindow::changeMoney(int diff)
{

    money+=diff;
    ui->lcdNumber->display(money);
    enableButton();
}
void MainWindow::on_pb10_clicked()
{
    MainWindow::changeMoney(10);
    //money+=10;
    //ui->lcdNumber->display(money);
}

void MainWindow::on_pb50_clicked()
{
    MainWindow::changeMoney(50);
}

void MainWindow::on_pb100_clicked()
{
    MainWindow::changeMoney(100);
}


void MainWindow::on_pb500_clicked()
{
    MainWindow::changeMoney(500);
}

void MainWindow::on_pbCoffe_clicked()
{
    buy(100);
}

void MainWindow::on_pbTee_clicked()
{
    buy(150);
}


void MainWindow::on_pbMilk_clicked()
{
    buy(200);
}

void MainWindow::on_pbReset_clicked()
{
    ResetMoney();
    enableButton();
    //QMessageBox m;
    //m.information(nullptr,"aaaasd","bbbb");
}
