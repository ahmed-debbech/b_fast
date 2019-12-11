#include "stat.h"
#include "ui_stat.h"
#include "mainwindow.h"
stat::stat(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::stat)
{
    ui->setupUi(this);
}

stat::~stat()
{
    delete ui;
}

void stat::on_pushButton_18_clicked()
{
    MainWindow*mainwidow;
    mainwidow->set

}
