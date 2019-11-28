#ifndef LIGNE_H
#define LIGNE_H

#include <QDialog>

namespace Ui {
class ligne;
}

class ligne : public QDialog
{
    Q_OBJECT

public:
    explicit ligne(QWidget *parent = nullptr);
    ~ligne();

private slots:
    void on_pushButton_19_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_21_clicked();

private:
    Ui::ligne *ui;
};

#endif // LIGNE_H
