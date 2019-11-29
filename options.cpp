#include "options.h"
#include "ui_options.h"

Options::Options(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Options)
{
    ui->setupUi(this);
}

Options::~Options()
{
    delete ui;
}
