#include "mainwindow.h"
#include <QMessageBox>
#include <QApplication>
#include <QSqlDatabase>
int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("cc");
    db.setUserName("ahmeddeb");
    db.setPassword("ahmed");
    int ex = 0;
    if (db.open()){
        QMessageBox::information(nullptr, QObject::tr("Database status"),
                           QObject::tr("Connection is successful.\n"
                                       "Click Ok to continue."), QMessageBox::Ok);
        MainWindow w;
        w.show();
        ex = a.exec();
    }else{
        QMessageBox::critical(nullptr, QObject::tr("Database status"),
                          QObject::tr("Connection is failed.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);

    }
    return ex;
}
