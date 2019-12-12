#include "client.h"
#include <QString>
#include <QDebug>
#include <QSqlRecord>
Client::Client()
{

}

Client::Client(int id1_,QString Name)
{
ID= id1_;
nom=Name;
}

Client::Client(int id1)
{
ID= id1;

}
int Client:: get_id(){return ID;}
QString Client:: get_nom() {return nom;}

bool Client::ajouter_client()
{

    QSqlQuery query1;
    query1.prepare("INSERT INTO CLIENTS (ID,NOM) VALUES (:ID,:NOM)");
    query1.bindValue(":ID",ID);
    query1.bindValue(":NOM",nom);
    return query1.exec();
}

QSqlQueryModel * Client::afficher_client()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from CLIENTS");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));


    return model;
}

QSqlQueryModel * Client::trier_client()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("SELECT * from CLIENTS ORDER BY ID DESC");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));


    return model;
}

QSqlQueryModel * Client::trier_client2()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("SELECT * from CLIENTS ORDER BY NOM ASC");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
return model;
}


QSqlQueryModel * Client::chercher_client(int idd){
QSqlQuery q;
q.prepare("select * from CLIENTS where ID=:idd");
q.bindValue(":idd", idd);
q.exec();
QSqlQueryModel * model = new QSqlQueryModel;
model->setQuery(q);
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
QSqlRecord rec = model->record(0);
int id = rec.value("ID").toInt();
if( id == idd){
    return model;
  }
    return nullptr;
}

bool Client::supprimer_client(int idc)
{
QSqlQuery query;
QString ident1= QString::number(idc);
query.prepare("Delete from CLIENTS where ID = :id ");
query.bindValue(":id",ident1);
return    query.exec();
}



bool Client::modifier_client(int id ,QString nom)
{

    QString idcc= QString::number(id);
    QSqlQuery query;

    query.prepare("UPDATE CLIENTS SET NOM= :nom WHERE ID = :id");
    query.bindValue(":id", idcc);
    query.bindValue(":nom",nom);

            return    query.exec();

}

