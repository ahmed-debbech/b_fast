#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QtDebug>
#include <QDialog>

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

