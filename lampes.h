#ifndef LAMPES_H
#define LAMPES_H

#include <QDialog>
#include"lampe.h"

namespace Ui {
class Lampes;
}

class Lampes : public QDialog
{
    Q_OBJECT

public:
    explicit Lampes(QWidget *parent = nullptr);
    ~Lampes();

private slots:
    void on_AjouterLampe_clicked();

    void on_AfficherLampe_clicked();

    void on_pushButton_2_clicked();

    void on_SupprimerLampe_clicked();

    void on_ModifierLampe_clicked();

private:
    Ui::Lampes *ui;
    Lampe tmplampe ;
};

#endif // LAMPES_H
