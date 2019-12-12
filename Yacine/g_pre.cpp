#include "g_pre.h"
#include <QDebug>
#include<QString>
#include <QSqlQuery>
#include "QSqlQueryModel"
#include <QSystemTrayIcon>
g_pre::g_pre()
{
    id=0;
    DateEnt="";
    DateSor="";
    Date="";
}
g_pre::g_pre(int id,QString DateEnt,QString DateSor,QString Date)
{
  this->id=id;
  this->DateEnt=DateEnt;
  this->DateSor=DateSor;
  this->Date=Date;
}
int g_pre::get_id(){return  id;}
QString g_pre::get_DateEnt(){return  DateEnt;}
QString g_pre::get_DateSor(){return DateSor;}
QString g_pre::get_Date(){return Date;}


bool g_pre::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("INSERT INTO PRES_ABS (ID_EMP, H_ENTR, H_SORT,DATEE) "
                    "VALUES (:id, :DateEnt, :DateSor,:Date)");
query.bindValue(":id", res);
query.bindValue(":DateEnt", DateEnt);
query.bindValue(":DateSor", DateSor);
query.bindValue(":Date", Date);


return    query.exec();
}

QSqlQueryModel * g_pre::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from PRES_ABS");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("H_ENTR "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("H_SORT"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATEE"));

    return model;
}

bool g_pre :: update()
{
    QSqlQuery query;
    int first=0 ;
        QString res1=QString::number(id);
         QString editer="Update PRES_ABS set" ;
        query.bindValue(":DateEnt",DateEnt);
        if(DateEnt!="")
        {
            editer+=" H_ENTR = :DateEnt" ;
            first=1 ;
        }

        query.bindValue(":DateSor",DateSor);
        if(DateSor!=""&& first!=0)
            editer+=" ,H_SORT= :DateSor" ;
        else if (DateSor!=""&&first==0)
          {
            editer+=" H_SORT= :DateSor" ;
            first=1 ;
          }
        query.bindValue(":Date",Date);
        if(Date!=""&& first!=0)
            editer+=" ,DATEE= :Date" ;
        else if (Date!=""&&first==0)
          {
            editer+=" DATEE= :Date" ;
            first=1 ;
          }

               editer+=" where ID_EMP = :id" ;



               QByteArray chaine = editer.toLocal8Bit();
               const char *final = chaine.data();

             /*  QMessageBox::information(nullptr, QObject::tr("Supprimer un employé"),
                           QObject::tr(final
                                       ), QMessageBox::Cancel); */

            query.prepare(final);

         query.bindValue(":id",QVariant(res1).toInt());
         query.bindValue(":id", res1);
         query.bindValue(":DateEnt", DateEnt);
         query.bindValue(":DateSor", DateSor);
         query.bindValue(":Date", Date);
         return query.exec();
}
bool g_pre::supprimer(int id)
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("Delete from PRES_ABS where ID_EMP = :id ");
query.bindValue(":id", res);
return    query.exec();
}

QSqlQueryModel * g_pre::chercher(int id)
 {

     QSqlQueryModel * model = new QSqlQueryModel();
     QSqlQuery query;
     query.prepare(QString("select * from PRES_ABS WHERE ID_EMP=:id"));

     query.bindValue(":id",id);

      query.exec();
     model->setQuery(query);
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("DateEnt "));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("DateSor"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATEE"));


return model;
 }

QSqlQueryModel * g_pre::afficher_tri()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from PRES_ABS order by ID_EMP asc ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("DateEnt"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("DateSor"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATEE"));

    return model;
}
QSqlQueryModel * g_pre::afficher_tri_DateEnt()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from PRES_ABS order by H_ENTR asc ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("DateEnt"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("DateSor"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATEE"));

    return model;
}

QSqlQueryModel * g_pre::afficher_tri_DateSort()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from PRES_ABS order by H_SORT asc ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("DateEnt"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("DateSor"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATEE"));
    return model;

}
