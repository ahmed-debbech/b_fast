#include "subscription.h"
#include <iostream>
#include <QSqlQuery>
#include <QString>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQueryModel>
Subscription::Subscription(int id, QString name, QString exp,
                           QString deb, QString desc, int id_ligne, int id_ab)
{
    m_id = id;
    m_name = name;
    m_date_deb = deb;
    m_date_exp = exp;
    m_descr = desc;
    m_id_ligne = id_ligne;
    m_id_sub = id_ab;
}
Subscription::Subscription(int id)
{
    m_id = id;
}
Subscription::Subscription()
{

}
void Subscription :: addSubs(){
    QSqlQuery query;
    query.prepare("INSERT INTO ABONNEMENT (ID_ABONN, NOM, DATE_EXP, DATE_DEB, DESCRIP, ID_LIGNE, ID_AB) "
                  "VALUES (:id, :nom, :ex, :deb, :dec, :id_ligne, :id_ab)");
    query.bindValue(":id", m_id);
    query.bindValue(":nom", m_name);
    query.bindValue(":ex", m_date_exp);
    query.bindValue(":deb", m_date_deb);
    query.bindValue(":dec", m_descr);
    query.bindValue(":id_ligne", m_id_ligne);
    query.bindValue(":id_ab", m_id_sub);
    query.exec();
}
void Subscription :: modSubs(){
    QSqlQuery query;
    query.prepare("UPDATE ABONNEMENT SET id_abonn= :id, NOM= :name, date_exp= :exp, date_deb= :deb, descrip = :des, id_ligne = :id_lig, id_ab= :id_ab WHERE ID_ABONN= :id ;");
    query.bindValue(":id", m_id);
    query.bindValue(":name", m_name);
    query.bindValue(":exp", m_date_exp);
    query.bindValue(":deb", m_date_deb);
    query.bindValue(":des", m_descr);
    query.bindValue(":id_lig", m_id_ligne);
    query.bindValue(":id_ab", m_id_sub);
    query.exec();
}
void Subscription :: delSubs(){
    QSqlQuery query;
    query.prepare("DELETE FROM abonnement WHERE id_abonn= :id");
    query.bindValue(":id", m_id);
    query.exec();
}
QSqlQueryModel * Subscription :: showSubs(int id_subsc){
    QSqlQuery query;
    query.prepare("Select * from abonnement where ID_AB= :id");
    query.bindValue(":id", id_subsc);
    QSqlQueryModel *model = new QSqlQueryModel();
    query.exec();
    model->setQuery(query);
    return model;
}
