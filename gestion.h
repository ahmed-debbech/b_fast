#ifndef GESTION_H
#define GESTION_H

#include <QDialog>
#include"parking.h"
#include "mail.h"

namespace Ui {
class Gestion;
}

class Gestion : public QDialog
{
    Q_OBJECT

public:
    explicit Gestion(QWidget *parent = nullptr);
    ~Gestion();

private slots:
    void on_pushButton_clicked();



    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Gestion *ui;
    Parking *P ;
    Mail *M;


};

#endif // GESTION_H
