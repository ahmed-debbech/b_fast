#include "poubelles.h"

Poubelles::Poubelles()
{
     id_poubelle=-1;
    etat_poubelle=0;


}
Poubelles::Poubelles(int id ,int e)
{
    id_poubelle=id;
   etat_poubelle=e;


}
QSqlQueryModel * Poubelles :: afficher_poubelles()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from POUBELLE");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_POUB"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("ETAT"));
    return model;
}
bool Poubelles:: supprimer_poubelles(int n)
{
    QSqlQuery query;
    QString res=QString::number(n);
    query.prepare("Delete from POUBELLE where ID_POUB= :n");
    query.bindValue(":n",res);
    return query.exec();
}

bool Poubelles :: ajouter_poubelles()
{
    QSqlQuery query;
    QString res=QString::number(id_poubelle);
    QString res1=QString::number(etat_poubelle);
    query.prepare("INSERT INTO POUBELLE(ID_POUB, ETAT) VALUES ( :id_poubelle, :etat)");
    query.bindValue(":id_poubelle",id_poubelle);
    query.bindValue(":etat",etat_poubelle);


    return query.exec();

}
void Poubelles :: set_etat_pou(int e)
{
    etat_poubelle=e;
}


bool Poubelles::modifier_etat_poubelles(int n, int e)
{
    QSqlQuery query;
    QString res1=QString::number(n);
    QString res2=QString::number(e);
     query.prepare("Update POUBELLE set ETAT = :e where ID_POUB = :n");
     query.bindValue(":e",QVariant(res2).toInt());
     query.bindValue(":n",QVariant(res1).toInt());
     return query.exec();

}
