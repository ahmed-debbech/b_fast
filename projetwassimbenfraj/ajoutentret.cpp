#include "ajoutentret.h"
#include "ui_ajoutentret.h"

ajoutentret::ajoutentret(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ajoutentret)
{
    ui->setupUi(this);
}

ajoutentret::~ajoutentret()
{
    delete ui;
}
