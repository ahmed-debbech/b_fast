#include "g_horaire.h"
#include <QDebug>
g_horaire::g_horaire()
{

}
g_horaire::g_horaire( int j, int m ,int a , int h,int mi,int id)
{
this->jour=j;
this->mois=m;
this->annee=a;
this->heure=h;
    this->minute=mi;
    this->ID_LIGNE1=id;
}
int g_horaire::get_jour(){return jour;}
int g_horaire::get_mois(){return mois;}
int g_horaire::get_annee(){return annee;}
int g_horaire::get_heure(){return heure;}
int g_horaire::get_minute(){return minute;}
int g_horaire::get_ID_LIGNE1(){return ID_LIGNE1;}
bool g_horaire::ajouter()
{
QSqlQuery query;
QString res0= QString::number(ID_LIGNE1);
QString res= QString::number(jour);
QString res1= QString::number(mois);
QString res2= QString::number(annee);
QString res3= QString::number(heure);
QString res4= QString::number(minute);
query.prepare("INSERT INTO HORAIRE (ID_LIGNE1,JOUR, MOIS, ANNEE,HEURE,MINUTE) "
                    "VALUES (:ID_LIGNE1,:JOUR, :MOIS, :ANNEE,:HEURE,:MINUTE)");
query.bindValue(":ID_LIGNE1", res0);
query.bindValue(":JOUR", res);
query.bindValue(":MOIS", res1);
query.bindValue(":ANNEE", res2);
query.bindValue(":HEURE", res3);
query.bindValue(":MINUTE", res4);

return    query.exec();
}
QSqlQueryModel * g_horaire::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from  g_horaire");
model->setHeaderData(0, Qt::Horizontal, QObject::tr(""));
model->setHeaderData(0, Qt::Horizontal, QObject::tr("JOUR"));
model->setHeaderData(0, Qt::Horizontal, QObject::tr("MOIS"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("ANNEE "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("HEURE"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("MINUTE"));
    return model;
}
bool g_horaire::supprimer(int ID_LIGNE1 )
{
QSqlQuery query;
QString res= QString::number(ID_LIGNE1);
query.prepare("Delete from HORAIRE where ID_LIGNE1 = :ID_LIGNE1 ");
query.bindValue(":ID_LIGNE1", res);
return    query.exec();
}
bool  g_horaire::  modifier_horaire(int n,int e)
{
    QSqlQuery query;
    QString res1=QString::number(n);
    QString res=QString::number(e);
     query.prepare("Update horaire set heure = :e where  ID_LIGNE1= :n");
     query.bindValue(":e",QVariant(res).toInt());
     query.bindValue(":n",QVariant(res1).toInt());
     return query.exec();
}
QSqlQueryModel * g_horaire::afficher_trie_heure()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from Horaire order by heure asc ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_LIGNE1"));
model->setHeaderData(0, Qt::Horizontal, QObject::tr("JOUR"));
model->setHeaderData(0, Qt::Horizontal, QObject::tr("MOIS"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("ANNEE "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("HEURE"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("MINUTE"));
    return model;
}


