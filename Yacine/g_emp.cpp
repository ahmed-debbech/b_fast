#include "g_emp.h"
#include <QDebug>
#include<QString>
#include <QSqlQuery>
#include "QSqlQueryModel"
#include <QSystemTrayIcon>
g_emp::g_emp()
{
    id=0;
    nom="";
    prenom="";
    departement="";
    Date="";
}
g_emp::g_emp(int id,QString nom,QString prenom,QString departement,QString Date)
{
  this->id=id;
  this->nom=nom;
  this->prenom=prenom;
  this->departement=departement;
  this->Date=Date;
}
QString g_emp::get_Departement(){return  departement;}
QString g_emp::get_Date(){return  Date;}
QString g_emp::get_nom(){return  nom;}
QString g_emp::get_prenom(){return prenom;}
int g_emp::get_id(){return  id;}

bool g_emp::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("INSERT INTO employe (ID_EMP, NOM, PRENOM, DEPART, DATE_NAISSANCE) "
                    "VALUES (:id, :nom, :prenom, :departement, :Date )");
query.bindValue(":id", res);
query.bindValue(":nom", nom);
query.bindValue(":prenom", prenom);
query.bindValue(":departement", departement);
query.bindValue(":Date", Date);

return    query.exec();
}


QSqlQueryModel * g_emp::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from employe");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Departement "));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date"));
    return model;
}

bool g_emp :: update()
{
    QSqlQuery query;
    int first=0 ;
        QString res1=QString::number(id);
         QString editer="Update EMPLOYE set" ;
        query.bindValue(":nom",nom);
        if(nom!="")
        {
            editer+=" NOM = :nom" ;
            first=1 ;
        }

        query.bindValue(":prenom",prenom);
        if(prenom!=""&& first!=0)
            editer+=" ,PRENOM= :prenom" ;
        else if (prenom!=""&&first==0)
          {
            editer+=" PRENOM= :prenom" ;
            first=1 ;
          }
             query.bindValue(":departement",departement);
             if(departement!=""&& first!=0)
                 editer+=" ,DEPART = :departement" ;
             else if (departement!="" && first==0)
             {
                editer+=" DEPART= :departement" ;
                first=1 ;
             }

               query.bindValue(":Date",Date);
               if(Date!=""&& first!=0)
                   editer+=" ,DATE_NAISSANCE = :Date" ;
               else if (Date!=""&&first==0)
               {
                 editer+=" DATE_NAISSANCE = :Date" ;
                 first=1 ;
               }

               editer+=" where ID_EMP = :id" ;



               QByteArray chaine = editer.toLocal8Bit();
               const char *final = chaine.data();

             /*  QMessageBox::information(nullptr, QObject::tr("Supprimer un employé"),
                           QObject::tr(final
                                       ), QMessageBox::Cancel); */

            query.prepare(final);

               //query.prepare("Update BUS set MODELE= :modele,ETAT = :etat,DATE_ACHAT = :date_achat  where ID = :id");

         query.bindValue(":id",QVariant(res1).toInt());
         query.bindValue(":id", res1);
         query.bindValue(":nom", nom);
         query.bindValue(":prenom", prenom);
         query.bindValue(":departement", departement);
         query.bindValue(":Date", Date);
         return query.exec();
}
bool g_emp::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from employe where ID_EMP = :id ");
query.bindValue(":id", res);
return    query.exec();
}
QSqlQueryModel * g_emp::chercher(int id)
 {

     QSqlQueryModel * model = new QSqlQueryModel();
     QSqlQuery query;
     query.prepare(QString("select * from employe WHERE ID_EMP=:id"));

     query.bindValue(":id",id);

      query.exec();
     model->setQuery(query);
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("Departement "));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date"));


return model;
 }
QSqlQueryModel * g_emp::afficher_tri()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from employe order by ID_EMP asc ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Departement "));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date"));
    return model;
}
QSqlQueryModel * g_emp::afficher_tri_depart()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from employe order by Depart asc ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Departement "));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date"));
    return model;

}
QSqlQueryModel * g_emp::afficher_tri_Nom()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from employe order by NOM asc ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Departement "));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date"));
    return model;

}
