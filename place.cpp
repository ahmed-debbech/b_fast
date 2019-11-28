#include "place.h"
#include<QDebug>
#include<QTableView>

Place::Place()
{
id=-1;
etatp=0;
Zone="0";
}

Place ::Place(int n,int e,QString Z)
{
    id=n;
    etatp=e;
   Zone=Z;

}

void Place :: set_etat(int e)
{
    etatp=e;
}


int Place :: get_id() {return id; }


int Place :: get_etat() {return etatp;}


QSqlQueryModel *Place::get_zone(QString Zone)
    {
        QSqlQueryModel *model=new QSqlQueryModel();
        QSqlQuery *q=new QSqlQuery();
        q->prepare("SELECT * FROM place WHERE ZONE LIKE '%"+Zone+"%' ");
        q->exec();
        model->setQuery(*q);
        return model;
    }

bool Place :: ajouter_place()
{
    QSqlQuery query;
    QString res=QString::number(id);
    QString res1=QString::number(etatp);
    query.prepare("INSERT INTO PLACE(NUMERO, ETAT, ZONE) VALUES ( :num, :etat, :Zone)");
    query.bindValue(":num",QVariant(res).toInt());
    query.bindValue(":etat",QVariant(res1).toInt());
    query.bindValue(":Zone",Zone);



    return query.exec();

}
QSqlQueryModel * Place :: afficher_place()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from PLACE");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("NUMERO"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("ETAT"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("ZONE"));
    return model;
}

bool Place :: supprimer_place(int n)
{
    QSqlQuery query;
    QString res=QString::number(n);
    query.prepare("Delete from PLACE where NUMERO = :n");
    query.bindValue(":n",res);
    return query.exec();
}

bool Place :: modifier_etat_place(int n,int e)
{
    QSqlQuery query;
    QString res1=QString::number(n);
    QString res2=QString::number(e);
     query.prepare("Update PLACE set ETAT = :e where NUMERO = :n");
     query.bindValue(":e",QVariant(res2).toInt());
     query.bindValue(":n",QVariant(res1).toInt());
     return query.exec();
}


QSqlQueryModel * Place::afficher_tri_etat()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from PLACE order by etat asc ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUMERO"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ETAT"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("ZONE "));
    return model;

}
QSqlQueryModel *Place::afficher_tri_id()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from PLACE order by etat asc ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUMERO"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ETAT"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("ZONE "));
    return model;

}
QSqlQueryModel *Place::afficher_tri_Zone()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from PLACE order by ZONE asc ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUMERO"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ETAT"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("ZONE "));
    return model;




}

void Place::recherche_id_place(QTableView *table, int n)
{
QString res=QString::number(n);
QSqlQueryModel *model=new QSqlQueryModel() ;
QSqlQuery qry ;
qry.prepare("Select * from PLACE where (regexp_like(NUMERO,:id))");
qry.bindValue(":id",res);
qry.exec() ;
model->setQuery(qry) ;
table->setModel(model) ;
table->show() ;
}

QSqlQueryModel * Place::load_comboboxPLA()
{
    QSqlQueryModel* model=new QSqlQueryModel() ;
    model->setQuery("select NUMERO from PLACE ") ;
    return model ;
    }



