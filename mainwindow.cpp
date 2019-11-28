#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "horaire.h"
#include "ligne.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    horaire h;
    h.setWindowTitle("Gestion De Horaire ");
    h.exec();
}

void MainWindow::on_pushButton_2_clicked()
{
    ligne h;
    h.setWindowTitle("Gestion De Ligne ");
    h.exec();
}
