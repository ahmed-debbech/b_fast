#include "connection.h"
#include <QSqlError>

Connection::Connection(){
                      }
bool Connection::ouvrirConnection()
{bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
                           db.setDatabaseName("Hmd");
                           db.setUserName("yacine");//inserer nom de l'utilisateur
                           db.setPassword("esprit18");//inserer mot de passe de cet utilisateur

if (db.open())
    test=true;

else throw QString ("Erreur Paramétres"+db.lastError().text());
return  test;
}
void Connection::fermerConnection()
{db.close();}
