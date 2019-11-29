#include "dialog.h"
#include "ui_dialog.h"
#include<QMessageBox>
#include <iostream>
#include <QDialog>
#include "client.h"
#include <QSystemTrayIcon>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    sys=new QSystemTrayIcon(this);
    sys->setIcon(QIcon(":/icon.png"));
    sys->setVisible(true);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    int ID=ui->lineEdit_a_3->text().toInt();

    QString nom = ui->lineEdit_a_2->text();

    Client c(ID,nom);
    bool test=c.ajouter_client();
    if(test)
  {ui->tableView->setModel(temp.afficher_client());
        sys->showMessage(tr("notification"),tr("Ajouter"));
  QMessageBox::information(nullptr, QObject::tr("Ajouter un client"),
                    QObject::tr("client ajouté.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

  }
    else
        QMessageBox::critical(nullptr, QObject::tr("Ajouter un client"),
                    QObject::tr("Erreur , échec d'ajout !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void Dialog::on_pushButton_2_clicked()
{
    int ID = ui->lineEdit_a_4->text().toInt();
    bool test=temp.supprimer_client(ID);
    if(test)
    {ui->tableView->setModel(temp.afficher_client());
        QMessageBox::information(nullptr, QObject::tr("Supprimer un client"),
                    QObject::tr("client supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un client"),
                    QObject::tr("Erreur , echec de suppression !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}




void Dialog::on_pushButton_3_clicked()
{
    int ID = ui->lineEdit_a_7->text().toInt();
    QSqlQueryModel * test=temp.chercher_client(ID);
    if(test != nullptr)
    {
        QMessageBox::information(nullptr, QObject::tr("chercher un client"),
                    QObject::tr("client trouvé.\n"
                                "Click Cancel to get informations."), QMessageBox::Cancel);
            ui->tableView_2->setModel(test);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("chercher un client"),
                    QObject::tr("Erreur , client introuvable !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}
}

void Dialog::on_pushButton_6_clicked()
{
ui->tableView->setModel( temp.trier_client());
}

void Dialog::on_pushButton_7_clicked()
{
   ui->tableView->setModel( temp.trier_client2());
}

void Dialog::on_pushButton_8_clicked()
{
    ui->tableView->setModel( temp.afficher_client());
}

void Dialog::on_pushButton_5_clicked()
{
    int id = ui->lineEdit_a_5->text().toInt();
   QString nom= ui->lineEdit_a_6->text();

         bool test = temp.modifier_client(id,nom);

             if (test)

             {

                  ui->tableView->setModel( temp.afficher_client());



                 QMessageBox::information(nullptr, QObject::tr("modification effectuee avec sucess !"),

                             QObject::tr( "Click Cancel to exit."), QMessageBox::Cancel);

             }

             else

                 QMessageBox::critical(nullptr, QObject::tr("modification echouée !"),

                             QObject::tr( "Click Cancel to exit."), QMessageBox::Cancel);
}
