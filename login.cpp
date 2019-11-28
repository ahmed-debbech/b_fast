#include "login.h"
#include "ui_login.h"
#include<QMessageBox>

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::on_Login_2_clicked()
{
    QString username = ui->username->text();
    QString password = ui->password->text();
    if((username=="admin")&&(password=="admin"))
{

        G=new Gestion ;
        this->hide();
        G->show() ;

}
    else
    {
        QMessageBox::information(this,"Erreur","Verifier vos informations");

    }


}
