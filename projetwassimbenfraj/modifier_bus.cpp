#include "modifier_bus.h"
#include "ui_modifier_bus.h"
#include <QMessageBox>
#include "bus.h"

modifier_bus::modifier_bus(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modifier_bus)
{
    ui->setupUi(this);
}

modifier_bus::~modifier_bus()
{
    delete ui;
}

void modifier_bus::on_pushButton_5_clicked()
{
    int id = ui->lineEdit_id->text().toInt();
    QString type= ui->lineEdit_type->text();
    QString date_achat= ui->lineEdit_date->text();
    QString etat= ui->lineEdit_etat->text();
    QString modele= ui->lineEdit_modele->text();
  bus b(id,type,modele,date_achat,etat);
  bool test=b.update();
  if(test)
{
QMessageBox::information(nullptr, QObject::tr("Ajouter un étudiant"),
                  QObject::tr("Etudiant ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un étudiant"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}
