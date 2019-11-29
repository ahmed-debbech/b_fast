#include "diagoptions.h"
#include "ui_diagoptions.h"
#include"dialog2.h"
#include"dialog.h"
#include <iostream>
//#include <QDebug>
Diagoptions::Diagoptions(QWidget *parent) :
    QDialog(parent),
    ui1(new Ui::Diagoptions)
{
    ui1->setupUi(this);

     QPixmap pix("C:/Users/amdouni/Desktop/redbkg.png");
         int w = ui1->label_8->width();
         int h=ui1->label_8->height();
         ui1->label_8->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
}

Diagoptions::~Diagoptions()
{
    delete ui1;
}

void Diagoptions::on_pushButton_clicked()
{
    Dialog dg1;
    dg1.setModal(true);
    //qDebug() << "Hello World";

    dg1.exec();
   // qDebug() << "Hello World";

}

void Diagoptions::on_pushButton_2_clicked()
{
    Dialog2 dg2;
    dg2.setModal(true);

    dg2.exec();

}
