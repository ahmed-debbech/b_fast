#ifndef AFFICHER_BUS_H
#define AFFICHER_BUS_H

#include <QDialog>
#include "bus.h"

namespace Ui {
class afficher_bus;
}

class afficher_bus : public QDialog
{
    Q_OBJECT

public:
    explicit afficher_bus(QWidget *parent = nullptr);
    ~afficher_bus();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::afficher_bus *ui;
    bus tmpbus;

};

#endif // AFFICHER_BUS_H
