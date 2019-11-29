#ifndef CLIENT_H
#define CLIENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Client
{
private:
    int ID ;
    QString nom ;


public:
    Client();
    Client(int,QString);
    int get_id();
    QString get_nom();
    void set_id (int ids) {ID= ids;}
    void set_nom (QString name) {nom = name;}
    bool ajouter_client();
    QSqlQueryModel * afficher_client();
     QSqlQueryModel * trier_client();
     QSqlQueryModel * trier_client2();
    QSqlQueryModel *chercher_client(int);
    bool supprimer_client(int);
    bool modifier_client (int,QString);



};

#endif // CLIENT_H
