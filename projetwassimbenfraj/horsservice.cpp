#include "horsservice.h"
#include "ui_horsservice.h"
#include <QMessageBox>

horsservice::horsservice(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::horsservice)
{
    ui->setupUi(this);
}

horsservice::~horsservice()
{
    delete ui;
}

void horsservice::on_pushButton_5_clicked()
{
    int id = ui->lineEdit->text().toInt();
    bool test=tmpbus.supprimer(id);
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("Supprimer un étudiant"),
                    QObject::tr("Etudiant supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un étudiant"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


}
