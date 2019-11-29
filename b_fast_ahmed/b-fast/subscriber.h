#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

#include <vector>
#include <QString>
#include "subscription.h"
#include <QSqlQueryModel>

class Subscriber
{
    int m_id;
    QString m_name;
    QString m_surname;
    QString m_sex;
    int m_pin;
    int m_nb_of_use;
    std::vector <Subscription> v;
    bool exists();
public:
    Subscriber(int, QString, QString, QString, int, int );
    Subscriber(int id);
    Subscriber();
    QSqlQueryModel * showSubscriber();
    bool addSubscriber();
    bool delSubscriber();
    bool modSubscriber();
    QSqlQueryModel * sort(int type);
    QSqlQueryModel * search (int type, QString key);

};

#endif // SUBSCRIBER_H
