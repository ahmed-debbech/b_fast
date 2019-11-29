#include "mainwindow.h"
#include<QtDebug>
#include <QSqlError>
#include <QSqlQuery>
#include <QApplication>
#include "client.h"
#include "res.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setHostName("localhost");
    db.setDatabaseName("qtbase");
    db.setUserName("aziz");
    db.setPassword("esprit18");
    if (db.open())
    {
        qDebug()<<"Connected Succesfully, DataBase open.";
    }
    else
    {
        qDebug()<<"Unvalid DataBase or Existing Errors.";
    }


    return a.exec();



}
