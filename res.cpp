#include "res.h"
#include <QString>
#include <QDebug>
#include "dialog2.h"
#include <QSqlRecord>
res::res()
{

}

res::res(int id_ ,QString Type_, QString date_, QString horaire_ , int id_ligne_)
{
    Id = id_;
    Type =Type_;
    date =date_;
    horaire =horaire_;
    id_ligne =id_ligne_ ;

}

int res::get_id() {return Id;}
QString res::get_type() {return Type;}
QString res::get_date() {return date;}
QString res::get_horaire() {return horaire;}
int res::get_id_ligne() {return id_ligne;}

bool res::ajouter_res()
{
 QSqlQuery query;
 query.prepare("INSERT INTO RESERVATIONS (ID,TYPE,DATE_REV,HORAIRE,ID_LIGNE) "
                     "VALUES (:ID,:TYPE,:DATE_REV,:HORAIRE,:ID_LIGNE)");
 query.bindValue(":ID", Id);
 query.bindValue(":TYPE", Type);
 query.bindValue(":DATE_REV", date);
 query.bindValue(":HORAIRE",horaire);
 query.bindValue(":ID_LIGNE",id_ligne);

 return    query.exec();
}

QSqlQueryModel * res::afficher_res()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from RESERVATIONS");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPE "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE_REV"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("HORAIRE"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("ID_LIGNE"));

    return model;
}

bool res::supprimer_res(int idr)
{
QSqlQuery query;
QString ident= QString::number(idr);
query.prepare("Delete from RESERVATIONS where ID = :id ");
query.bindValue(":id",ident);
return    query.exec();
}



bool res:: modifier_res(int id,QString Type, QString date, QString horaire, int id_ligne)
{
    QString id1 = QString :: number (id) ;
      QString idl = QString :: number (id_ligne) ;

        QSqlQuery q;
         q.prepare("UPDATE RESERVATIONS set ID =:id ,TYPE =:type , DATE_REV=:date ,HORAIRE=: horaire ,ID_LIGNE=: id_ligne");
         q.bindValue(":ID", id1);
         q.bindValue(":TYPE",Type);
         q.bindValue(":DATE_REV", date);
         q.bindValue(":HORAIRE",horaire);
         q.bindValue(":ID_LIGNE",id_ligne);

        return    q.exec();


}

QSqlQueryModel * res::trier_res()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("SELECT * from RESERVATIONS ORDER BY ID DESC");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPE "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE_REV"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("HORAIRE"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("ID_LIGNE"));
QSqlRecord rec = model->record(0);

    return model;
}



QSqlQueryModel * res::chercher_res(int ids){
QSqlQuery q;
q.prepare("select * from RESERVATIONS where ID=:ids");
q.bindValue(":ids", ids);
q.exec();
QSqlQueryModel * model = new QSqlQueryModel;
model->setQuery(q);
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPE "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE_REV"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("HORAIRE"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("ID_LIGNE"));
QSqlRecord rec = model->record(0);
int id = rec.value("ID").toInt();
if( id == ids){
    return model;
  }
    return nullptr;
}
