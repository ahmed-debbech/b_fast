#include "ajoutrappel.h"
#include "ui_ajoutrappel.h"

ajoutrappel::ajoutrappel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ajoutrappel)
{
    ui->setupUi(this);
}

ajoutrappel::~ajoutrappel()
{
    delete ui;
}
