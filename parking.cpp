#include "parking.h"
#include "ui_parking.h"

Parking::Parking(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Parking)
{
    ui->setupUi(this);
}

Parking::~Parking()
{
    delete ui;
}


void Parking::on_places_clicked()
{
    P=new Places ;
    this->hide();
    P->show() ;

}

void Parking::on_lampes_clicked()
{
    L=new Lampes ;
    this->hide();
    L->show() ;
}

void Parking::on_pushButton_clicked()
{
    PL=new Poubelle ;
    this->hide();
    PL->show() ;
}
