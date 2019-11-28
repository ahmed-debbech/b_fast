#ifndef PLACE_H
#define PLACE_H


#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QTableView>

class Place
{
public:
    Place();
    Place(int,int,QString);
    void set_etat(int);
    void set_id(int);
    int get_id();
    int get_etat();
    QSqlQueryModel* get_zone(QString Zone);
    bool ajouter_place();
    QSqlQueryModel * afficher_place();
    QSqlQueryModel * load_comboboxPLA();
    bool supprimer_place(int);
    bool modifier_etat_place(int,int);
    void recherche_id_place(QTableView*,int);
    QSqlQueryModel * afficher_tri_etat();
    QSqlQueryModel * afficher_tri_id();
    QSqlQueryModel * afficher_tri_Zone();




private:
    int etatp,id;
    QString Zone ;

};

#endif // PLACE_H
