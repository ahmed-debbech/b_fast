#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_login_clicked()
{
    //ui->stackedWidget->setCurrentIndex(1) ;
    QString id= ui->username->text() ;
    QString pass=ui->password->text() ;
    if(MainWindow::rech(id,pass))
    {
     ui->stackedWidget->setCurrentIndex(1) ;
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("modifier un entretien"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_employee_clicked()
{
    f = new BFast () ;

   this->hide();
    f->exec() ;


    if(f->isVisible()==false)
        this->show() ;
}

int MainWindow ::rech(QString id,QString pass)
{

    QSqlQuery query;
        int count=0;
        bool test=0;
        if(query.exec("select ID_AD  from ADMIN where  ID_AD='" +id +"' AND PASS='" +pass+ "'"))
        {
        while(query.next())
            count++;
        if(count>=1)
            test=1;

        }
        return test;
}



void MainWindow::on_pushButton_clicked()
{
   melek * m =new melek();
   m->show() ;
}
