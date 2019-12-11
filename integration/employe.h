#ifndef EMPLOYE_H
#define EMPLOYE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class employe
{public:
    employe();
    employe(int,QString,QString,QString,QString);
    QString get_Date();
    QString get_Departement();
    QString get_nom();
    QString get_prenom();
    int get_id();
    bool ajouter();
    QSqlQueryModel * afficher();
    QSqlQueryModel * afficher_tri();
    QSqlQueryModel * chercher(int);
    bool supprimer(int);
    bool update();
private:
    QString nom,prenom,departement,Date;
    int id;
};


#endif // EMPLOYE_H
