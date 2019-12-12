#include "lampe.h"
#include <QDateTime>



Lampe::Lampe()
{
id_lampe=-1;
etat=0;

}

Lampe ::Lampe(int n,int e,QString D)
{
    id_lampe=n;
    etat=e;
   Date_inst=D;

}

void Lampe :: set_etat_lampe(int e)
{
    etat=e;
}


int Lampe :: get_id() {return id_lampe; }


int Lampe :: get_etat() {return etat;}



bool Lampe :: ajouter_Lampe()
{
    QSqlQuery query;
    QString res=QString::number(id_lampe);
    QString res1=QString::number(etat);
    query.prepare("INSERT INTO LAMPE(NUMERO, ETAT, DATE_INST) VALUES ( :id_lampe , :etat, :date_inst)");
    query.bindValue(":id_lampe",QVariant(res).toInt());
    query.bindValue(":etat",QVariant(res1).toInt());
    query.bindValue(":date_inst",Date_inst);



    return query.exec();

}

QSqlQueryModel * Lampe :: afficher_lampe()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from LAMPE");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("NUMERO"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("ETAT"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("DATE_INST"));
    return model;
}


bool Lampe :: supprimer_Lampe(int n)
{
    QSqlQuery query;
    QString res=QString::number(n);
    query.prepare("Delete from LAMPE where NUMERO = :n");
    query.bindValue(":n",res);
    return query.exec();
}

bool Lampe ::  modifier_etat_Lampe(int n,int e)
{
    QSqlQuery query;
    QString res1=QString::number(n);
    QString res2=QString::number(e);
     query.prepare("Update LAMPE set ETAT = :e where NUMERO = :n");
     query.bindValue(":e",QVariant(res2).toInt());
     query.bindValue(":n",QVariant(res1).toInt());
     return query.exec();
}


QSqlQueryModel * Lampe::load_comboboxLA()
{
    QSqlQueryModel* model=new QSqlQueryModel() ;
    model->setQuery("select NUMERO from LAMPE ") ;
    return model ;
    }

void Lampe::recherche_id_Lampe(QTableView *table, int n)
{
QString res=QString::number(n);
QSqlQueryModel *model=new QSqlQueryModel() ;
QSqlQuery qry ;
qry.prepare("Select * from LAMPE where (regexp_like(NUMERO,:id))");
qry.bindValue(":id",res);
qry.exec() ;
model->setQuery(qry) ;
table->setModel(model) ;
table->show() ;
}

