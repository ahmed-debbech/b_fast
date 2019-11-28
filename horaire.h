#ifndef HORAIRE_H
#define HORAIRE_H

#include <QDialog>

namespace Ui {
class horaire;
}

class horaire : public QDialog
{
    Q_OBJECT

public:
    explicit horaire(QWidget *parent = nullptr);
    ~horaire();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_11_clicked();

private:
    Ui::horaire *ui;
};

#endif // HORAIRE_H
