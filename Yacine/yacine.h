#ifndef YACINE_H
#define YACINE_H

#include <QMainWindow>
#include "g_emp.h"
#include "g_pre.h"
#include <QSystemTrayIcon>
#include <QPropertyAnimation>
QT_BEGIN_NAMESPACE
namespace Ui { class Yacine; }
QT_END_NAMESPACE

class Yacine : public QMainWindow
{
    Q_OBJECT

public:
    Yacine(QWidget *parent = nullptr);
    ~Yacine();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_7_clicked();

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_17_clicked();

    void on_radioButton_3_clicked();

    void on_radioButton_5_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_21_clicked();

    void on_pushButton_22_clicked();

    void on_pushButton_23_clicked();

    void on_pushButton_24_clicked();

    void on_pushButton_25_clicked();

    void on_pushButton_26_clicked();

    void on_radioButton_6_clicked();

    void on_radioButton_4_clicked();

private:
    Ui::Yacine *ui;
    QSystemTrayIcon * mysystem;
    g_emp tmpemp;
    g_pre tmppre;
    QPropertyAnimation * animation;
};
#endif // YACINE_H
