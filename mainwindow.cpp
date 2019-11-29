#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "diagoptions.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/amdouni/Desktop/allred.png");
        int w = ui->label_2->width();
        int h=ui->label_2->height();
        ui->label_2->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
     QPixmap pix1("C:/Users/amdouni/Desktop/bfast.png");
        int w1 = ui->label_3->width();
        int h1=ui->label_3->height();
        ui->label_3->setPixmap(pix1.scaled(w1,h1,Qt::KeepAspectRatio));


}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_3_clicked()
{
    Diagoptions opt;
    opt.setModal(true);
    opt.exec();
}
