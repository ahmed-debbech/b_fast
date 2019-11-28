#include "g_ligne.h"
#include <QDebug>
#include<QString>
g_ligne::g_ligne()
{

}
g_ligne::g_ligne( QString t,QString a,QString z,int n)
{
 this->nom=t;
  this->source=a;
    this->destination=z;
    this->ID_LIGNE=n;
}
QString  g_ligne::get_nom(){return (nom);}
QString  g_ligne::get_source(){return (source);}
QString  g_ligne::get_destination(){return (destination);}
int g_ligne::get_ID_LIGNE(){return (ID_LIGNE);}
bool g_ligne::ajouter()
{
QSqlQuery query;
QString res= QString::number(ID_LIGNE);
query.prepare("INSERT INTO LIGNE (nom,source,destination,ID_LIGNE) "
                    "VALUES ( :nom,:source,:destination,:ID_LIGNE)");
query.bindValue(":nom",nom );
query.bindValue(":source",source );
query.bindValue(":destination",destination );
query.bindValue(":ID_LIGNE", res);

return    query.exec();
}
QSqlQueryModel * g_ligne::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from LIGNE");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("source "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("destination "));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID_LIGNE "));
    return model;
}
bool g_ligne::supprimer(int ID_LIGNE )
{
QSqlQuery query;
QString res= QString::number(ID_LIGNE);
query.prepare("Delete from LIGNE where ID_LIGNE = :ID_LIGNE ");
query.bindValue(":ID_LIGNE", res);
return    query.exec();
}
bool  g_ligne::  modifier_ligne(int n,QString e)
{
    QSqlQuery query;
    QString res1=QString::number(n);
     query.prepare("Update ligne set nom = :e where  ID_LIGNE= :n");
     query.bindValue(":e",QVariant(e));
     query.bindValue(":n",QVariant(res1).toInt());
     return query.exec();
}
QSqlQueryModel * g_ligne::afficher_tri_nom()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from LIGNE order by nom asc ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_LIGNE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("source "));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr(" destination"));
    return model;

}




