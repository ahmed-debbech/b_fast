#include "gestion.h"
#include "ui_gestion.h"
#include "stati.h"
#include "mailing/SmtpMime"
Gestion::Gestion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Gestion)
{
    ui->setupUi(this);
}

Gestion::~Gestion()
{
    delete ui;
}

void Gestion::on_pushButton_clicked()
{

    P=new Parking ;
    this->hide();
    P->show() ;

}

void Gestion::on_pushButton_2_clicked()
{
    SmtpClient smtp("smtp.gmail.com", 465, SmtpClient::SslConnection);

    smtp.setUser("yassine.kochat@esprit.tn");
    smtp.setPassword("yassine123");


    MimeMessage message;

    message.setSender(new EmailAddress("yassine.kochat@esprit.tn", "KOCHAT YASSINE"));
    message.addRecipient(new EmailAddress("zied.razouane@esprit.tn", "Yassine"));
    message.setSubject("SmtpClient for Qt - Demo");

    MimeText text;

    text.setText("Hi,\nSAHBY KOCHAT WAHDOU SEC.\n");

    message.addPart(&text);

    smtp.connectToHost();
    smtp.login();
    smtp.sendMail(message);
    smtp.quit();
}

void Gestion::on_pushButton_3_clicked()
{
    this->hide();
    stati* pp=new stati();
    pp->show();
}
