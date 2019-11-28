#include "ligne.h"
#include "ui_ligne.h"
#include <QtWidgets>
#include "g_ligne.h"
#include"QSqlQueryModel"
ligne::ligne(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ligne)
{
    ui->setupUi(this);
}

ligne::~ligne()
{
    delete ui;
}



void ligne::on_pushButton_11_clicked()
{
    int ID_LIGNE = ui->lineEdit_10->text().toInt();
  QString nom = ui->lineEdit_11->text();
      QString source =ui->lineEdit_13->text();
       QString destination= ui->lineEdit_12->text();


     g_ligne e( nom, source,destination,ID_LIGNE);
    bool test=e.ajouter();
    if(test)
    {
  //{ui->tabetudiant->setModel(tmpetudiant.afficher());//refresh
  QMessageBox::information(nullptr, QObject::tr("Ajouter une ligne "),
                    QObject::tr("Etudiant ajouté.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}
}
void ligne::on_pushButton_13_clicked()
{
    int ID_LIGNE = ui->lineEdit_16->text().toInt();
    g_ligne e;
      bool test=e.supprimer(ID_LIGNE);
      if(test)
      {//ui->e->setModel(tmpetudiant.afficher());//refresh
          QMessageBox::information(nullptr, QObject::tr("Supprimer ligne"),
                      QObject::tr("ligne supprimé.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

      }
      else
          QMessageBox::critical(nullptr, QObject::tr("Supprimer ligne"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
}

void ligne::on_pushButton_16_clicked()
{
    g_ligne e;
        ui->tableView_3->setModel(e.afficher());
}

void ligne::on_pushButton_17_clicked()
{
    QString n;

            int ID_LIGNE = ui->lineEdit_17->text().toInt();

            QString nom=ui->lineEdit_18->text();
      g_ligne e;
            e.set_nom(nom);


             bool test=e. modifier_ligne(ID_LIGNE,nom);

             if(test)
           {QMessageBox::information(this,tr("MODIFICATION"),tr("ETAT MODIFIE"));

           }
             else{QMessageBox::information(this,tr("MODIFICATION"),tr("ETAT NON MODIFIE"));}
}


void ligne::on_pushButton_19_clicked()
{
    g_ligne e;
        ui->tableView_4->setModel(e.afficher_tri_nom());
}

void ligne::on_pushButton_21_clicked()
{QString res =ui->lineEdit_19->text();
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from LIGNE where ID_LIGNE='"+res+"' ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_LIGNE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("source "));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr(" destination"));
    ui->tableView_5->setModel(model);

}
