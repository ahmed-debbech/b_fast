#include "client.h"
#include <QString>
#include <QDebug>
#include "dialog.h"
#include <QSqlRecord>
Client::Client()
{

}

Client::Client(int id1_,QString Name)
{
ID= id1_;
nom=Name;
}

int Client:: get_id(){return ID;}
QString Client:: get_nom() {return nom;}

bool Client::ajouter_client()
{
    QSqlQuery query;
    QString id= QString::number(ID);
    query.prepare("INSERT INTO CLIENTS (ID,NOM) "
                        "VALUES (:ID,:NOM)");
    query.bindValue(":ID",id);
    query.bindValue(":NOM",nom);

    return    query.exec();


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

    query.prepare("UPDATE CLIENTS SET NOM= :nom, WHERE ID = :id");
    query.bindValue(":ID", idcc);
    query.bindValue(":NOM",nom);

            return    query.exec();

}

