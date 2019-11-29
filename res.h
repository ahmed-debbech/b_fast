#ifndef RES_H
#define RES_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class res
{
private:
    int Id;
    QString Type;
    QString date;
    QString horaire;
    int id_ligne;

public:
    res();
    res(int,QString,QString,QString,int);
    int get_id();
    QString get_type();
    QString get_date();
    QString get_horaire();
    int get_id_ligne();
    void set_ident (int ids) {Id= ids;}
    void set_type (QString tp) {Type= tp;}
    void set_date (QString dt) {date= dt;}
    void set_hor (QString hr) {horaire= hr;}
    void set_Idligne (int idl) {id_ligne= idl;}
    bool ajouter_res();
    QSqlQueryModel * trier_res();
    QSqlQueryModel * afficher_res();
    QSqlQueryModel * chercher_res(int);
    bool supprimer_res(int);
    bool  modifier_res(int,QString,QString,QString,int);

};

#endif // RES_H
