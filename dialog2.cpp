#include "dialog2.h"
#include "ui_dialog2.h"
#include<QMessageBox>
#include <iostream>
#include <QDialog>
#include "res.h"

Dialog2::Dialog2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog2)
{
    ui->setupUi(this);
    ui->tableView_2->setModel(tempr.afficher_res());

}

Dialog2::~Dialog2()
{
    delete ui;
}


void Dialog2::on_pushButton_clicked()
{

    int Id = ui->lineEdit->text().toInt();
    QString Type = ui->lineEdit_2->text();
    QString date = ui->lineEdit_3->text();
    QString horaire = ui->lineEdit_7->text();
    int id_ligne = ui->lineEdit_4->text().toInt();


  res rs(Id,Type,date,horaire,id_ligne);

  bool test=rs.ajouter_res();
  if(test)
{ui->tableView_2->setModel(tempr.afficher_res());
QMessageBox::information(nullptr, QObject::tr("Ajouter une reservation"),
                  QObject::tr("reservation ajoutée.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}
  else{
      QMessageBox::critical(nullptr, QObject::tr("Ajouter une reservation"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

  }
}

void Dialog2::on_pushButton_3_clicked()
{
    int Id = ui->lineEdit_5->text().toInt();
    bool test=tempr.supprimer_res(Id);
    if(test)
    {ui->tableView_2->setModel(tempr.afficher_res());
        QMessageBox::information(nullptr, QObject::tr("Supprimer une reservation"),
                    QObject::tr("Reservation supprimée.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer une reservation"),
                    QObject::tr("Erreur , Echec de suppression !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void Dialog2::on_pushButton_2_clicked()
{
    int ID = ui->lineEdit_6->text().toInt();
    QSqlQueryModel * test=tempr.chercher_res(ID);
    if(test != nullptr)
    {
        QMessageBox::information(nullptr, QObject::tr("chercher une reservation"),
                    QObject::tr("reservation trouvé.\n"
                                "Click Cancel to get informations."), QMessageBox::Cancel);
            ui->tableView_3->setModel(test);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("chercher une reservation"),
                    QObject::tr("Erreur , reservation introuvable !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}
}

void Dialog2::on_pushButton_6_clicked()
{
    ui->tableView_2->setModel( tempr.trier_res());
}

void Dialog2::on_pushButton_5_clicked()
{
    ui->tableView_2->setModel( tempr.afficher_res());
}

void Dialog2::on_pushButton_4_clicked()
{
    int id = ui->lineEdit_8->text().toInt();


         bool test = tempr.modifier_res(id);

             if (test)

             {

                  ui->tableView_2->setModel( tempr.afficher_res());



                 QMessageBox::information(nullptr, QObject::tr("modification effectuee avec sucess !"),

                             QObject::tr( "Click Cancel to exit."), QMessageBox::Cancel);

             }

             else

                 QMessageBox::critical(nullptr, QObject::tr("modification echouée !"),

                             QObject::tr( "Click Cancel to exit."), QMessageBox::Cancel);
}
