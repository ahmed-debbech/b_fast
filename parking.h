#ifndef PARKING_H
#define PARKING_H

#include <QDialog>
#include"places.h"
#include"lampes.h"
#include"poubelle.h"

namespace Ui {
class Parking;
}

class Parking : public QDialog
{
    Q_OBJECT

public:
    explicit Parking(QWidget *parent = nullptr);
    ~Parking();

private slots:
    void on_places_clicked();

    void on_lampes_clicked();

    void on_pushButton_clicked();

private:
    Ui::Parking *ui;
    Places *P ;
    Lampes *L ;
    Poubelle *PL ;



};

#endif // PARKING_H
