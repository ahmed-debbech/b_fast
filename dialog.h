#ifndef DIALOG_H
#define DIALOG_H
#include<QSystemTrayIcon>
#include <QDialog>
#include "client.h"
namespace Ui {
class Dialog;
}
class QSystemTrayIcon;
class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::Dialog *ui;
    Client temp;
    QSystemTrayIcon *sys;
};

#endif // DIALOG_H
