#include "places.h"
#include "ui_places.h"
#include<QMessageBox>
#include "place.h"
#include<QDebug>
#include <QSystemTrayIcon>
Places::Places(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Places)
{
    ui->setupUi(this);
    mysytem=new QSystemTrayIcon(this);
    mysytem->setIcon(QIcon(":/icon.png"));
    mysytem->setVisible(true);


}

Places::~Places()
{
    delete ui;
}


void Places::on_AjouterPlaces_clicked()
{
    int id= ui->lineEdit_NUM->text().toInt();
        int etat= ui->lineEdit_Etat->text().toInt();
        QString Zone= ui->lineEdit_Zone->text();
      Place p(id,etat,Zone);
      bool test=p.ajouter_place();
      if(test)
   {
          ////refresh
    mysytem->showMessage(tr("notification"),tr("ajout avec succes"));
          QMessageBox::information(nullptr, QObject::tr("Ajouter une place"),
                      QObject::tr("PLace ajoutée.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

    }
      else
      {QMessageBox::critical(nullptr, QObject::tr("Ajouter une place"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);}
      ui->tableViewPlaces->setModel(tmpplace.afficher_place());
}

void Places::on_AfficherPlaces_clicked()
{
    ui->tableViewPlaces->setModel(tmpplace.afficher_place());
}

void Places::on_radioButton_clicked()
{
    ui->tableViewPlaces->setModel(tmpplace.afficher_tri_id());
}


void Places::on_radioButton_2_clicked()
{
     ui->tableViewPlaces->setModel(tmpplace.afficher_tri_etat());
}

void Places::on_radioButton_3_clicked()
{
    ui->tableViewPlaces->setModel(tmpplace.afficher_tri_Zone());
}

void Places::on_ModifierPlaces_clicked()
{
    int id = ui->comboBoxPLACE->currentText().toInt();

    int etat=ui->lineEdit_Etat_2->text().toInt();

     tmpplace.set_etat(etat);


     bool test=tmpplace.modifier_etat_place(id,etat);

     if(test)
   {QMessageBox::information(this,tr("MODIFICATION"),tr("ETAT MODIFIE"));

   }
     else{QMessageBox::information(this,tr("MODIFICATION"),tr("ETAT NON MODIFIE"));}
}

void Places::on_pushButton_clicked()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select NUMERO from PLACE");
    ui->comboBoxPLACE->setModel(model);
    qDebug()<<(model->rowCount());
}

void Places::on_SupprimerPlaces_clicked()
{
    int id = ui->lineEdit_NUM_3->text().toInt();
       bool test=tmpplace.supprimer_place(id);
       if(test)
       {
           QMessageBox::information(nullptr, QObject::tr("Supprimer une place"),
                       QObject::tr("place supprimée.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);

       }
       else{
           QMessageBox::critical(nullptr, QObject::tr("Supprimer une place"),
                       QObject::tr("cette place n'existe pas !.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);}
}

void Places::on_lineEditRechercher_2_textChanged(const QString &)
{
    Place P ;
  int id=ui->lineEditRechercher_2->text().toInt();
   P.recherche_id_place(ui->tableView_2,id) ;
}

void Places::on_Rechercherlampe_2_clicked()
{
    int id_place;

    id_place=ui->lineEditRechercher_2->text().toInt();
    QSqlQueryModel *model=new QSqlQueryModel();
    QSqlQuery* query=new QSqlQuery();
    query->prepare("Select * from PLACE where NUMERO=:id_place ");
    query->bindValue(":id_place",id_place);


    query->exec();
    model->setQuery(*query);

    qDebug()<<(model->rowCount());
   if( (model->rowCount()!=0))
       QMessageBox::information(nullptr, QObject::tr("Rechercher une place "),
                   QObject::tr(" la place existe \n"
                               "Click Cancel to exit."), QMessageBox::Cancel);

  else

   QMessageBox::information(nullptr, QObject::tr("Rechercher une PLACE "),
               QObject::tr(" Cette place n'existe pas .\n"
                           "Click Cancel to exit."), QMessageBox::Cancel);
}
