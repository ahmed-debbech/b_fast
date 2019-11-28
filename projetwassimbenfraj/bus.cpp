#include "bus.h"
#include <QDebug>
#include <QMessageBox>
bus::bus()
{
id=0;
type="";
modele="";
date_achat="";
etat="";

}
bus::bus(int id,QString type,QString modele,QString date_achat ,QString etat)
{
  this->id=id;
   this->type=type;
  this->modele=modele;
    this->etat=etat ;
    this->date_achat=date_achat ;


}
QString bus::get_type(){return  type;}
QString bus::get_modele(){return modele;}
QString bus::get_etat(){return etat;}
QString bus::get_date_achat(){return date_achat;}
int bus::get_id(){return  id;}

bool bus::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
bus b;
if (b.rech(id)==0)
{
query.prepare("INSERT INTO BUS (ID,TYPE,MODELE,ETAT,DATE_ACHAT) "
                    "VALUES (:id, :type, :modele, :etat, :date_achat)");
query.bindValue(":id", id);
query.bindValue(":type", type);
query.bindValue(":modele", modele);
query.bindValue(":etat", etat);
query.bindValue(":date_achat", date_achat);
}

return    query.exec();
}

QSqlQueryModel * bus::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from bus");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Type "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Modele"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Etat"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date_Achat "));
    return model;
}
QSqlQueryModel * bus::afficher_tri()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from bus order by ID asc");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Type "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Modele"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Etat"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date_Achat "));
    return model;
}

bool bus::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from bus where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}
bool bus::update()
{

    QSqlQuery query;
    int first=0 ;
        QString res1=QString::number(id);
         QString editer="Update BUS set" ;
        query.bindValue(":type",type);
        if(type!="")
        {
            editer+=" TYPE = :type" ;
            first=1 ;
        }

        query.bindValue(":modele",modele);
        if(modele!=""&& first!=0)
            editer+=" ,MODELE= :modele" ;
        else if (modele!=""&&first==0)
          {
            editer+=" MODELE= :modele" ;
            first=1 ;
          }
             query.bindValue(":etat",etat);
             if(etat!=""&& first!=0)
                 editer+=" ,ETAT = :etat" ;
             else if (etat!="" && first==0)
             {
                editer+=" ETAT = :etat" ;
                first=1 ;
             }

               query.bindValue(":date_achat",date_achat);
               if(date_achat!=""&& first!=0)
                   editer+=" ,DATE_ACHAT = :date_achat" ;
               else if (date_achat!=""&&first==0)
               {
                 editer+=" DATE_ACHAT = :date_achat" ;
                 first=1 ;
               }

               editer+=" where ID = :id" ;



               QByteArray chaine = editer.toLocal8Bit();
               const char *final = chaine.data();

             /*  QMessageBox::information(nullptr, QObject::tr("Supprimer un étudiant"),
                           QObject::tr(final
                                       ), QMessageBox::Cancel); */

            query.prepare(final);

               //query.prepare("Update BUS set MODELE= :modele,ETAT = :etat,DATE_ACHAT = :date_achat  where ID = :id");

         query.bindValue(":id",QVariant(res1).toInt());
         query.bindValue(":type",type);
        query.bindValue(":modele",modele);
             query.bindValue(":etat",etat);
               query.bindValue(":date_achat",date_achat);

         return query.exec();
}
QSqlQueryModel * bus::chercher(int id)
 {

     QSqlQueryModel * model = new QSqlQueryModel();
     QSqlQuery query;
     query.prepare(QString("select * from bus WHERE ID=:id"));

     query.bindValue(":id",id);

      query.exec();
     model->setQuery(query);
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("Type "));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("Modele"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("Etat"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date_Achat "));

return model;
 }
int bus ::rech(int id)
{

    QSqlQuery query;
        int count=0;
        bool test=0;
        QString num_string=QString::number(id);
        if(query.exec("select ID from bus where  ID='" +num_string +"'"))
        {
        while(query.next())
            count++;
        if(count>=1)
            test=1;

        }
        return test;
}
