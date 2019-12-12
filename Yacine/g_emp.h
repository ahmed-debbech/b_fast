#ifndef G_EMP_H
#define G_EMP_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class g_emp
{
public:
g_emp();
g_emp(int,QString,QString,QString,QString);
QString get_Date();
QString get_Departement();
QString get_nom();
QString get_prenom();
int get_id();
bool ajouter();
QSqlQueryModel * afficher();
bool update();
bool supprimer(int);
QSqlQueryModel * chercher(int);
QSqlQueryModel * afficher_tri();
QSqlQueryModel * afficher_tri_depart();
QSqlQueryModel * afficher_tri_Nom();
private:
QString nom,prenom,departement,Date;
int id;
};

#endif // G_EMP_H
