#include "poubelle.h"
#include "ui_poubelle.h"

Poubelle::Poubelle(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Poubelle)
{
    ui->setupUi(this);
}

Poubelle::~Poubelle()
{
    delete ui;
}
