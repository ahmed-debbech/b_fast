#ifndef POUBELLES_H
#define POUBELLES_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QTableView>

class Poubelles
{
public:
    Poubelles();
    Poubelles(int,int);
    QSqlQueryModel * afficher_poubelles();
    bool supprimer_poubelles(int);
    bool ajouter_poubelles();
    void recherche_etat_poubelles(QTableView*,int);
    bool modifier_etat_poubelles(int,int);
    void set_etat_pou(int);
private:
    int id_poubelle ;
    int etat_poubelle ;
};

#endif // POUBELLES_H
