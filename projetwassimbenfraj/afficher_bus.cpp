#include "afficher_bus.h"
#include "ui_afficher_bus.h"
#include "stati.h"

afficher_bus::afficher_bus(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::afficher_bus)
{
    ui->setupUi(this);
    ui->tableView->setModel(tmpbus.afficher());
}

afficher_bus::~afficher_bus()
{
    delete ui;
}

void afficher_bus::on_pushButton_clicked()
{
    ui->tableView->setModel(tmpbus.afficher_tri());
}

void afficher_bus::on_pushButton_2_clicked()
{
    int id = ui->lineEdit->text().toInt();
    ui->tableView->setModel(tmpbus.chercher(id));

}

void afficher_bus::on_pushButton_3_clicked()
{
    stati s;
    s.exec();
}
