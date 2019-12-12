#include "yacine.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include <QtDebug>
#include <QSystemTrayIcon>
int main(int argc, char *argv[])
{  QApplication a(argc, argv);

    Connection c;
  QApplication::setWindowIcon(QIcon(":/img/logo APP-01.png"));
  bool test=c.ouvrirConnection();
  Yacine w;
  if(test)
  {w.show();

      QMessageBox::critical(nullptr, QObject::tr("Debut de travail de yacine"),
                  QObject::tr("connection avec succés.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

  }
  else
      QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                  QObject::tr("connection failed.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

    return a.exec();}
