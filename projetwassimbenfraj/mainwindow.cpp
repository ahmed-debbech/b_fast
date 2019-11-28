#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ajoutbus.h"
#include "horsservice.h"
#include "ajoutentret.h"
#include "ajoutrappel.h"
#include "afficher_bus.h"
#include "modifier_bus.h"

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
    ajoutbus ab;
    ab.setModal(true);
    ab.exec();
}

void MainWindow::on_pushButton_2_clicked()
{
    horsservice hs;
    hs.setModal(true);
    hs.exec();
}

void MainWindow::on_pushButton_9_clicked()
{
    ajoutentret ae;
    ae.setModal(true);
    ae.exec();
}

void MainWindow::on_pushButton_7_clicked()
{
    ajoutrappel ar;
    ar.setModal(true);
    ar.exec();
}

void MainWindow::on_pushButton_3_clicked()
{
    afficher_bus a;
    a.setModal(true);
    a.exec();
}

void MainWindow::on_pushButton_4_clicked()
{
    modifier_bus m;
    m.exec();

}
