#include "horaire.h"
#include "ui_horaire.h"
#include"g_horaire.h"
#include <QtWidgets>
#include "stati.h"
#include "mailing/SmtpMime"
horaire::horaire(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::horaire)
{
    ui->setupUi(this);
}

horaire::~horaire()
{
    delete ui;
}

void horaire::on_pushButton_clicked()
{






    SmtpClient smtp("smtp.gmail.com", 465, SmtpClient::SslConnection);


    smtp.setUser("melek.abid@esprit.tn");
    smtp.setPassword("Se7lihawi");



    MimeMessage message;

    message.setSender(new EmailAddress("melek.abid@esprit.tn", "MELEK ABID"));
    message.addRecipient(new EmailAddress("yassine.kochat@esprit.tn", "YASSINE"));
    message.setSubject("SmtpClient for Qt - Demo");



    MimeText text;

    text.setText("Hi,\n TEST MAILING.\n");



    message.addPart(&text);


    smtp.connectToHost();
    smtp.login();
    smtp.sendMail(message);
    smtp.quit();


    int ID_LIGNES1 = ui->lineEdit->text().toInt();
    int JOUR = ui->lineEdit_2->text().toInt();
  int MOIS = ui->lineEdit_3->text().toInt();
      int ANNEE =ui->lineEdit_4->text().toInt();
       int HEURE= ui->lineEdit_5->text().toInt();
        int MINUTE= ui->lineEdit_6->text().toInt();

     g_horaire e( JOUR, MOIS,ANNEE,HEURE,MINUTE,ID_LIGNES1);
    bool test=e.ajouter();
    if(test)
    {
  //{ui->tabetudiant->setModel(tmpetudiant.afficher());//refresh
  QMessageBox::information(nullptr, QObject::tr("Ajouter horaire"),
                    QObject::tr("Etudiant ajouté.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}
}

void horaire::on_pushButton_3_clicked()
{
    int ID_LIGNE1 = ui->lineEdit_8->text().toInt();
    g_horaire e;
      bool test=e.supprimer(ID_LIGNE1);
      if(test)
      {//ui->e->setModel(tmpetudiant.afficher());//refresh
          QMessageBox::information(nullptr, QObject::tr("Supprimer horaire"),
                      QObject::tr("ligne supprimé.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

      }
      else
          QMessageBox::critical(nullptr, QObject::tr("Supprimer un horaire"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
}

void horaire::on_pushButton_6_clicked()
{
    g_horaire e;
        ui->tableView->setModel(e.afficher());
}

void horaire::on_pushButton_9_clicked()
{
    g_horaire e;
        ui->tableView_2->setModel(e.afficher_trie_heure());
}

void horaire::on_pushButton_7_clicked()
{
    int ID_LIGNE1 = ui->lineEdit_7->text().toInt();

                int heure=ui->lineEdit_9->text().toInt();
          g_horaire e;
                e.set_heure(heure);


                 bool test=e. modifier_horaire(ID_LIGNE1,heure);

                 if(test)
               {QMessageBox::information(this,tr("MODIFICATION"),tr("ETAT MODIFIE"));

               }
                 else{QMessageBox::information(this,tr("MODIFICATION"),tr("ETAT NON MODIFIE"));}
}

void horaire::on_pushButton_11_clicked()
{
    stati s;
    s.exec();
}
