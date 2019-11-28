#ifndef G_HORAIRE_H
#define G_HORAIREE_H
#include <QString>
#include<QDate>
#include<QTime>
#include <QSqlQuery>
#include <QSqlQueryModel>

class g_horaire
{
public:
    g_horaire();
    g_horaire( int, int,int,int,int,int);
    int get_jour();
      int get_annee();
      int get_ID_LIGNE1();
    int get_mois();
       int get_heure();
     int get_minute();
     bool ajouter();
     QSqlQueryModel * afficher();
      QSqlQueryModel * afficher_trie_heure();
     bool supprimer(int);
    bool modifier_horaire(int ,int );
    void set_heure(int){int a=0;heure=a;}
    private:
     int jour,annee,mois,heure,minute;
     int ID_LIGNE1;

};

#endif // G_HORAIRE_H
