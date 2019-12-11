#ifndef BUS_H
#define BUS_H


#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QTableView>
class bus
{public:
   bus();
  bus(int,QString,QString,QString,QString);
    QString get_type();
    QString get_modele();
    QString get_date_achat();
    QString get_etat();
    int get_id();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool update();
     QSqlQueryModel * afficher_tri();
     QSqlQueryModel * chercher(int);
     int rech(int);
     void recherche_id_place(QTableView *, int);
private:
    QString type,modele,date_achat,etat;
    int id;
};

#endif // BUS_H
