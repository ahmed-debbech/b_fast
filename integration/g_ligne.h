#ifndef G_LIGNE_H
#define G_LIGNE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class g_ligne
{
public:
    g_ligne();
    g_ligne( QString,QString,QString,int);
    QString get_nom();
    QString get_source();
    QString get_destination();
    int get_ID_LIGNE();
     bool ajouter();
     QSqlQueryModel * afficher();
     bool supprimer(int);
     bool modifier_ligne(int ,QString );
     void set_nom(QString){QString n;nom=n;}
      void set_destination(QString){QString n;destination=n;}
    QSqlQueryModel * afficher_tri_nom();
    QSqlQueryModel * afficher_tri_ID_ligne();
    QSqlQueryModel * afficher_source();
     private:
    QString nom,source,destination;
    int ID_LIGNE;

};

#endif // G_LIGNE_H

