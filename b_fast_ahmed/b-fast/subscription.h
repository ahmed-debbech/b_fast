#ifndef SUBSCRIPTION_H
#define SUBSCRIPTION_H

#include <iostream>
#include <QString>
#include <QSqlQueryModel>
class Subscription{
    int m_id;
    QString m_name;
    QString m_date_exp;
    QString m_date_deb;
    QString m_descr;
    int m_id_ligne;
    int m_id_sub;
public:
    Subscription(int,QString, QString, QString, QString, int, int);
    Subscription(int);
    Subscription();
    void addSubs();
    void modSubs();
    void delSubs();
    QSqlQueryModel * showSubs(int);
};

#endif // SUBSCRIPTION_H
