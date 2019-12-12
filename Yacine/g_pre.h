#ifndef G_PRE_H
#define G_PRE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class g_pre
{

public:
    g_pre();
    g_pre(int,QString,QString,QString);
    QString get_DateEnt();
    QString get_DateSor();
    QString get_Date();
    int get_id();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool update();
    bool supprimer(int);
    QSqlQueryModel * chercher(int);
    QSqlQueryModel * afficher_tri();
    QSqlQueryModel * afficher_tri_DateEnt();
    QSqlQueryModel * afficher_tri_DateSort();
private:
    QString DateEnt,DateSor,Date;
    int id;
};

#endif // G_PRE_H
