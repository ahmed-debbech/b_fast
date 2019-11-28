#ifndef PLACES_H
#define PLACES_H

#include <QDialog>
#include "place.h"


namespace Ui {
class Places;
}
class QSystemTrayIcon;
class Places : public QDialog
{
    Q_OBJECT

public:
    explicit Places(QWidget *parent = nullptr);
    ~Places();

private slots:
    void on_AjouterPlaces_clicked();

    void on_AfficherPlaces_clicked();

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();

    void on_ModifierPlaces_clicked();

    void on_pushButton_clicked();

    void on_SupprimerPlaces_clicked();

    void on_lineEditRechercher_2_textChanged(const QString &arg1);

    void on_Rechercherlampe_2_clicked();

private:
    Ui::Places *ui;
    Place tmpplace ;
    QSystemTrayIcon * mysytem;



};

#endif // PLACES_H
