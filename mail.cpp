#include "mail.h"
#include "ui_mail.h"
#include "smtp.h"

Mail::Mail(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Mail)
{
    ui->setupUi(this);
}

Mail::~Mail()
{
    delete ui;
}

void Mail::on_pushButton_clicked()
{
    Smtp * s = new Smtp( "razouanezied@gmail.com", "Eatmyhealz1998", "smtp.gmail.com", 465 );
    s->sendMail("afazfgeg",ui->lineEdit->text(),"zied.razouane@gmail.com",ui->lineEdit_2->text());
}

void Mail::on_pushButton_2_clicked()
{
    hide();
}
