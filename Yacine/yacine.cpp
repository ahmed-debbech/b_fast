#include "yacine.h"
#include "ui_yacine.h"
#include <QSystemTrayIcon>
#include"QMessageBox"
#include<QDebug>
#include <QtWidgets>
#include"QSqlQueryModel"
#include "g_emp.h"
#include "g_pre.h"
#include <QMediaPlayer>
Yacine::Yacine(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Yacine)
{
    ui->setupUi(this);
    this->setWindowTitle("BFast");
    mysystem=new QSystemTrayIcon(this);
    mysystem->setIcon(QIcon(":/icon.png"));
    mysystem->setVisible(true);

}

Yacine::~Yacine()
{
    delete ui;
}


void Yacine::on_pushButton_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
            // ...
            player->setMedia(QUrl::fromLocalFile(":/img/button.wav"));
            player->setVolume(500);
            player->play();
    ui->stackedWidget->setCurrentIndex(1);
}

void Yacine::on_pushButton_2_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
            // ...
            player->setMedia(QUrl::fromLocalFile(":/img/button.wav"));
            player->setVolume(500);
            player->play();
    ui->stackedWidget->setCurrentIndex(5);
}

void Yacine::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void Yacine::on_pushButton_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void Yacine::on_pushButton_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void Yacine::on_pushButton_4_clicked()
{
    g_emp e;
        ui->tableView->setModel(e.afficher());
}

void Yacine::on_pushButton_9_clicked()
{
    int id = ui->lineEdit->text().toInt();
    QString nom= ui->lineEdit_2->text();
    QString prenom= ui->lineEdit_3->text();
    QString departement=ui->comboBox->currentText();
    QString Date=ui->dateEdit->text();
  g_emp e(id,nom,prenom,departement,Date) ;
  bool test=e.ajouter();
  if(test)
{
      ui->tableView->setModel(tmpemp.afficher());
      mysystem->showMessage(tr("Notifcation!"),tr("Ajout d'un employé avec succés"));
      QMessageBox::information(nullptr, QObject::tr("Ajouter un employé"),
                  QObject::tr("Employé ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un employé"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}


void Yacine::on_pushButton_10_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void Yacine::on_pushButton_12_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void Yacine::on_pushButton_11_clicked()
{
    int id = ui->lineEdit_4->text().toInt();
    QString nom= ui->lineEdit_5->text();
    QString prenom= ui->lineEdit_6->text();
    QString departement= ui->comboBox_2->currentText();
    QString Date= ui->dateEdit_2->text();

  g_emp e(id,nom,prenom,departement,Date);
  bool test=e.update();
  if(test)
{
      ui->tableView->setModel(tmpemp.afficher());
      mysystem->showMessage(tr("Notifcation!"),tr("Modification d'un employé avec succés"));

QMessageBox::information(nullptr, QObject::tr("modifier un employe"),
                  QObject::tr("employe modifie.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("modifier un employe"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}

void Yacine::on_pushButton_14_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void Yacine::on_pushButton_13_clicked()
{
    int id = ui->lineEdit_7->text().toInt();
    bool test=tmpemp.supprimer(id);
    if(test)
    {   ui->tableView->setModel(tmpemp.afficher());
       mysystem->showMessage(tr("Notifcation!"),tr("Supression d'un employé avec succés"));
        QMessageBox::information(nullptr, QObject::tr("Supprimer un employe"),
                    QObject::tr("employes supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un employe"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}

void Yacine::on_pushButton_7_clicked()
{
    int id=ui->lineEdit_8->text().toInt();
  ui->tableView->setModel(tmpemp.chercher(id)) ;
}

void Yacine::on_radioButton_clicked()
{
    ui->tableView->setModel(tmpemp.afficher_tri());
}

void Yacine::on_radioButton_2_clicked()
{
    ui->tableView->setModel(tmpemp.afficher_tri_depart());
}

void Yacine::on_pushButton_8_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void Yacine::on_pushButton_20_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void Yacine::on_pushButton_15_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void Yacine::on_pushButton_17_clicked()
{
    g_pre p;
     ui->tableView_2->setModel(p.afficher());
}

void Yacine::on_radioButton_3_clicked()
{
    ui->tableView_2->setModel(tmppre.afficher_tri());
}

void Yacine::on_radioButton_5_clicked()
{
    ui->tableView_2->setModel(tmppre.afficher_tri_DateEnt());
}

void Yacine::on_pushButton_18_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}


void Yacine::on_pushButton_16_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);
}

void Yacine::on_pushButton_19_clicked()
{
    int id=ui->lineEdit_9->text().toInt();
  ui->tableView_2->setModel(tmppre.chercher(id)) ;
}



void Yacine::on_pushButton_21_clicked()
{
        int id = ui->lineEdit_10->text().toInt();
        QString DateEnt= ui->timeEdit_3->text();
        QString DateSor= ui->timeEdit_4->text();
        QString Date=ui->dateEdit_3->text();
      g_pre p(id,DateEnt,DateSor,Date) ;
      bool test=p.ajouter();
      if(test)
    {
          ui->tableView_2->setModel(tmppre.afficher());
         mysystem->showMessage(tr("Notifcation!"),tr("Ajout d'une Présence avec succés"));
          QMessageBox::information(nullptr, QObject::tr("Ajouter une Présence"),
                      QObject::tr("Présence ajoutée.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);


    }
      else
          QMessageBox::critical(nullptr, QObject::tr("Ajouter une Présence"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);


}

void Yacine::on_pushButton_22_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void Yacine::on_pushButton_23_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void Yacine::on_pushButton_24_clicked()
{
    int id =ui->lineEdit_11->text().toInt();
    QString DateEnt= ui->timeEdit_5->text();
    QString DateSor= ui->timeEdit_6->text();
    QString Date=ui->dateEdit_4->text();

      g_pre p(id,DateEnt,DateSor,Date) ;
      bool test=p.update();
  if(test)
{
      ui->tableView_2->setModel(tmppre.afficher());
      mysystem->showMessage(tr("Notifcation!"),tr("Modification d'une Présence avec succés"));

QMessageBox::information(nullptr, QObject::tr("modifier une Présence"),
                  QObject::tr("Présence modifiée.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("modifier une Présence"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}

void Yacine::on_pushButton_25_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void Yacine::on_pushButton_26_clicked()
{
    int id =ui->lineEdit_12->text().toInt();
    bool test=tmppre.supprimer(id);
    if(test)
    {   ui->tableView_2->setModel(tmppre.afficher());
       mysystem->showMessage(tr("Notifcation!"),tr("Supression d'une Présence avec succés"));
        QMessageBox::information(nullptr, QObject::tr("Supprimer une Présence"),
                    QObject::tr("Présence supprimée.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer une Présence"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void Yacine::on_radioButton_6_clicked()
{
        ui->tableView->setModel(tmpemp.afficher_tri_Nom());
}

void Yacine::on_radioButton_4_clicked()
{
            ui->tableView_2->setModel(tmppre.afficher_tri_DateSort());
}
