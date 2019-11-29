#include "subscriber.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QString>
#include <QDebug>
#include <QSqlQueryModel>
#include <QSqlRecord>
#include <iostream>
Subscriber::Subscriber(int id, QString name, QString surname
                       , QString sex, int id_card, int nb_of_use ){
    m_id = id;
    m_name =name;
    m_surname = surname;
    m_sex = sex;
    m_pin = id_card;
    m_nb_of_use = nb_of_use;
}
Subscriber :: Subscriber (int id){
    m_id = id;
}
Subscriber :: Subscriber(){

}
bool Subscriber :: exists(){
    QSqlQuery query;
     query.prepare("Select * from abonne where ID_ABONNEE= :id");
     query.bindValue(":id", m_id);
    QSqlQueryModel *model = new QSqlQueryModel();
    query.exec();
    model->setQuery(query);
    QSqlRecord rec = model->record(0);
    if(rec.value("ID_ABONNEE").toInt() == m_id){
        std::cout << "rr" << std::endl;
        return true;
    }
    return false;
}
bool Subscriber :: addSubscriber(){
    QSqlQuery query;
    if(exists() == true){
        return false;
    }else{
        if(((m_id< 1000) || (m_id > 9999)) || ((m_pin <0) || (m_pin > 9999))){
            return false;
        }else{
            QString res= QString::number(m_id);
            query.prepare("INSERT INTO ABONNE (ID_ABONNEE, NOM, PRENOM, SEXE, PIN, NB_UTIL) "
                          "VALUES (:id, :nom, :prenom, :sexe, :pin, :nb_util)");
            query.bindValue(":id", m_id);
            query.bindValue(":nom", m_name);
            query.bindValue(":prenom", m_surname);
            query.bindValue(":sexe", m_sex);
            if(m_pin >= 1000){
                 query.bindValue(":pin", m_pin);
            }else{
                QString res = QString::number(m_pin);
                int count= 0;
                for(int i = 0; i<=res.size()-1; i++){
                    if((res[i]>='0') && (res[i]<='9')){
                        count++;
                    }
                }
                for(int i=1; i<= 4-count; i++){
                    res = '0' + res;
                }
                std::cout <<res.toStdString() << std::endl;
                int pin  = res.toInt();
                std::cout << pin << std::endl;
                 query.bindValue(":pin", res);
            }
            query.bindValue(":nb_util", m_nb_of_use);
            query.exec();
        }
    }
    return true;
}
bool Subscriber :: delSubscriber(){
    QSqlQuery query;
    query.prepare("DELETE FROM abonne WHERE ID_ABONNEE= :id");
    query.bindValue(":id", m_id);
    return    query.exec();
}
bool Subscriber :: modSubscriber(){
    QSqlQuery query;
    query.prepare("UPDATE ABONNE SET NOM= :name, PRENOM= :surname, SEXE= :sex, PIN= :pin WHERE ID_ABONNEE= :id ;");
    query.bindValue(":name", m_name);
    query.bindValue(":surname", m_surname);
    query.bindValue(":sex", m_sex);
    query.bindValue(":pin", m_pin);
    query.bindValue(":id", m_id);
    return query.exec();
}
QSqlQueryModel * Subscriber :: showSubscriber(){
    QSqlQuery query;
     query.prepare("Select * from abonne");
    QSqlQueryModel *model = new QSqlQueryModel();
    query.exec();
    model->setQuery(query);
    return model;
}
QSqlQueryModel * Subscriber :: sort (int type){
    QSqlQuery query;
    QSqlQueryModel *model = new QSqlQueryModel();
    switch(type){
        case 1: //sort by name
        query.prepare("Select * from abonne order by nom ASC");
       query.exec();
       model->setQuery(query);
        break;
    case 2: //sort by id
        query.prepare("Select * from abonne order by id_abonnee ASC");
       query.exec();
       model->setQuery(query);
        break;
    case 3: //sort by nb of use
        query.prepare("Select * from abonne order by nb_util ASC");
       query.exec();
       model->setQuery(query);
        break;
     default:
        model = showSubscriber();
        break;
    }
    return model;
}
QSqlQueryModel * Subscriber :: search (int type, QString key){
    QSqlQuery query;
    QSqlQueryModel *model = new QSqlQueryModel();
    int k ;
    switch(type){
        case 0:
            k = key.toInt();
            query.prepare("Select * from abonne where ID_ABONNEE = :id");
            query.bindValue(":id", k);
           query.exec();
           model->setQuery(query);
           if(model->record(0).isEmpty() == true){ return model = nullptr;}
        break;
    case 1:
        query.prepare("Select * from abonne where NOM = :nom");
        query.bindValue(":nom", key);
       query.exec();
       model->setQuery(query);
       if(model->record(0).isEmpty() == true){ return model = nullptr;}
        break;
    case 2:
        query.prepare("Select * from abonne where prenom = :prenom");
        query.bindValue(":prenom", key);
       query.exec();
       model->setQuery(query);
       if((model->record(0)).isEmpty() == true){return model = nullptr;}
        break;
    default:
        model = nullptr;
        break;
    }
    return model;
}
