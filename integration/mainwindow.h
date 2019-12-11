#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include "GestionEmployes/bfast.h"
#include "melek/untitled12/melek.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>
#include "connexion.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    int rech(QString ,QString ) ;
    ~MainWindow();

private slots:
    void on_login_clicked();

    void on_employee_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    BFast *f ;
};
#endif // MAINWINDOW_H
