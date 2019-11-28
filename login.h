#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include<QMainWindow>
#include"gestion.h"

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_Login_2_clicked();

private:
    Ui::Login *ui;
    Gestion *G;
};

#endif // LOGIN_H
