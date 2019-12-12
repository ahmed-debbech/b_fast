#ifndef LAMPE_H
#define LAMPE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QTableView>
#include <QDateTime>

class Lampe
{
public:
    Lampe();
    Lampe(int,int,QString) ;
    void set_etat_lampe(int);
    int get_id();
    int get_etat();
    bool ajouter_Lampe();
    QSqlQueryModel * afficher_lampe();
    QSqlQueryModel * load_comboboxLA();
    bool supprimer_Lampe(int);
    bool modifier_etat_Lampe(int,int);
    void recherche_id_Lampe(QTableView*,int);


private:
    int id_lampe ;
    int etat ;
    QString Date_inst ;



};

#endif // LAMPE_H
