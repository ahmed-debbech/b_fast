#include "ajoutbus.h"
#include "ui_ajoutbus.h"
#include <QMessageBox>
#include "bus.h"
#include <QSystemTrayIcon>
#include "mailing/SmtpMime"

ajoutbus::ajoutbus(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ajoutbus)
{
    ui->setupUi(this);
    mysystem = new QSystemTrayIcon(this);
    mysystem->setIcon(QIcon(":/icon.png"));
    mysystem->setVisible(true);
}

ajoutbus::~ajoutbus()
{
    delete ui;
}

void ajoutbus::on_pushButton_5_clicked()
{
    SmtpClient smtp("smtp.gmail.com", 465, SmtpClient::SslConnection);

    smtp.setUser("wassimbenfraaj@gmail.com");
    smtp.setPassword("21232168waS");


    MimeMessage message;

    message.setSender(new EmailAddress("wassimbenfraaj@gmail.com", "WASSIM BEN FRAJ"));
    message.addRecipient(new EmailAddress("wassim.benfraj@esprit.tn", "Yassine"));
    message.setSubject("TEST _MAILINF");

    MimeText text;

    text.setText("Hi,\nyaaatek aasba yassine \n");

    message.addPart(&text);

    smtp.connectToHost();
    smtp.login();
    smtp.sendMail(message);
    smtp.quit();
    int id = ui->lineEdit_id->text().toInt();
    QString type= ui->comboBox->currentText();
    QString date_achat= ui->lineEdit_date->text();
    QString etat= ui->lineEdit_etat->text();
    QString modele= ui->lineEdit_modele->text();
  bus b(id,type,modele,date_achat,etat);
  bool test=b.ajouter();
  if(test)
{
      mysystem->showMessage(tr("notification"),tr("ajout avec succes"));
QMessageBox::information(nullptr, QObject::tr("Ajouter un étudiant"),
                  QObject::tr("Etudiant ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un étudiant"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);



}
