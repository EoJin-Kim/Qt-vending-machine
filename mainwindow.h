#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int money {0};
    void changeMoney(int diff);
    void buy(int diff);
    void ResetMoney();
    void enableButton();

private slots:
    void on_pb10_clicked();

    void on_pb50_clicked();

    void on_pb100_clicked();

    void on_pb500_clicked();

    void on_pbCoffe_clicked();

    void on_pbTee_clicked();

    void on_pbMilk_clicked();

    void on_pbReset_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
