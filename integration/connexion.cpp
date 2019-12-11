#include "connexion.h"

connexion::connexion()
{

}

bool connexion::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("PROJECT");
db.setUserName("wassim");//inserer nom de l'utilisateur
db.setPassword("esprit18");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;
else throw QString ("Erreur Paramétres"+test);
return test;
}



void connexion::fermerconnexion()
{db.close();}

