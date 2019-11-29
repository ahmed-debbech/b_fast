#include "dcherche.h"
#include "ui_dcherche.h"

dcherche::dcherche(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dcherche)
{
    ui->setupUi(this);
}

dcherche::~dcherche()
{
    delete ui;
}
