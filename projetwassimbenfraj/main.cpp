#include "mainwindow.h"

#include <QApplication>
#include "connexion.h"
#include <QtDebug>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    connexion c ;
    try {
        c.createconnect();
        w.show();

    } catch (QString s) {
       qDebug()<<s; }

    return a.exec();
}
