#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.h"
#include "res.h"
#include <QMessageBox>
#include "mailing/SmtpMime"
#include "mailing/smtpclient.h"
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
QT_CHARTS_USE_NAMESPACE


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    on_pushButton_8_clicked(); // affichage des clients
    /* QPixmap pix("C:/Users/amdouni/Desktop/red.png");
         int w = ui->label_7->width();
         int h=ui->label_7->height();
         ui->label_6->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio)) ;*/
}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow :: getIDFromTableView(QTableView * tv){
    int id =-1;
    if(tv->currentIndex().isValid() == true){
    QModelIndexList indexes = tv->selectionModel()->selection().indexes();
    QVariant qv = indexes.at(0).data();
    QString ss = qv.toString();
    std::string cc = ss.toStdString();
    id = std::atoi (cc.c_str());
    }else{
        id = -1;
    }
    return id;
}



void MainWindow::on_pushButton_7_clicked() //mailing
{
    SmtpClient smtp("smtp.gmail.com", 465, SmtpClient::SslConnection);

        smtp.setUser("qt1dev@gmail.com");
        smtp.setPassword("thisisustransporters");


        MimeMessage message;

        message.setSender(new EmailAddress("qt1dev@gmail.com", "hey there"));
        message.addRecipient(new EmailAddress(ui->lineEdit_9->text(), ""));
        message.setSubject(ui->lineEdit_14->text());

        MimeText text;

        text.setText(ui->lineEdit_15->text());

        message.addPart(&text);

        smtp.connectToHost();
        smtp.login();
        smtp.sendMail(message);
        smtp.quit();
}

void MainWindow::on_pushButton_8_clicked()
{
   ui->tableView->setModel( temp.afficher_client());
}

void MainWindow::on_pushButton_19_clicked() //ajout client
{
    int ID=ui->lineEdit_a_12->text().toInt();

    QString nom = ui->lineEdit_a_13->text();

    Client c(ID,nom);
    bool test=c.ajouter_client();
    if(test)
  {ui->tableView->setModel(temp.afficher_client());

  QMessageBox::information(nullptr, QObject::tr("Ajouter un client"),
                    QObject::tr("client ajouté.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

  }
    else
        QMessageBox::critical(nullptr, QObject::tr("Ajouter un client"),
                    QObject::tr("Erreur , échec d'ajout !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_20_clicked() //modifier un client
{
    int id = ui->lineEdit_a_14->text().toInt();
   QString nom= ui->lineEdit_a_15->text();

         bool test = temp.modifier_client(id,nom);

             if (test)

             {

                  ui->tableView->setModel( temp.afficher_client());



                 QMessageBox::information(nullptr, QObject::tr("Successfully modified!"),

                             QObject::tr( "Click Cancel to exit."), QMessageBox::Cancel);

             }

             else

                 QMessageBox::critical(nullptr, QObject::tr("Modification Failed !"),

                             QObject::tr( "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_10_clicked()  //ajout reservation
{
    int Id = ui->lineEdit_5->text().toInt();
    QString Type = ui->lineEdit_4->text();
    QString date = ui->lineEdit_6->text();
    QString horaire = ui->lineEdit_8->text();
    int id_ligne = ui->lineEdit_7->text().toInt();


  res rs(Id,Type,date,horaire,id_ligne);

  bool test=rs.ajouter_res();
  if(test)
{ui->tableView_2->setModel(tempr.afficher_res());
QMessageBox::information(nullptr, QObject::tr("Ajouter une reservation"),
                  QObject::tr("reservation ajoutée.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}
  else{
      QMessageBox::critical(nullptr, QObject::tr("Ajouter une reservation"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

  }
}

void MainWindow::on_pushButton_9_clicked() // modifier reservation
{
    int id = ui->lineEdit_9->text().toInt();
    QString Type= ui->lineEdit_10->text();
    QString date= ui->lineEdit_11->text();
   QString horaire= ui->lineEdit_12->text();
   int id_ligne= ui->lineEdit_13->text().toInt();

         bool test = tempr.modifier_res(id,Type,date,horaire,id_ligne);
             if (test)

             {

                  ui->tableView_2->setModel( tempr.afficher_res());



                 QMessageBox::information(nullptr, QObject::tr("Successfully modified !"),

                             QObject::tr( "Click Cancel to exit."), QMessageBox::Cancel);

             }

             else

                 QMessageBox::critical(nullptr, QObject::tr("modification Failed !"),

                             QObject::tr( "Click Cancel to exit."), QMessageBox::Cancel);
}




void MainWindow::on_pushButton_6_clicked() //suppression reservation
{
    int Id = ui->lineEdit_14->text().toInt();
    bool test=tempr.supprimer_res(Id);
    if(test)
    {ui->tableView_2->setModel(tempr.afficher_res());
        QMessageBox::information(nullptr, QObject::tr("Supprimer une reservation"),
                    QObject::tr("Reservation supprimée.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer une reservation"),
                    QObject::tr("Erreur , Echec de suppression !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}




void MainWindow::on_pushButton_clicked()  //chercher client
{
    int ID = ui->lineEdit_19->text().toInt();
    QSqlQueryModel * test=temp.chercher_client(ID);
    if(test != nullptr)
    {
        QMessageBox::information(nullptr, QObject::tr("chercher un client"),
                    QObject::tr("client trouvé.\n"
                                "Click Cancel to get informations."), QMessageBox::Cancel);
            ui->tableView->setModel(test);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("chercher un client"),
                    QObject::tr("Erreur , client introuvable !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}
}

void MainWindow::on_pushButton_21_clicked()
{
ui->tableView->setModel( temp.trier_client());
}

void MainWindow::on_pushButton_22_clicked()
{
 ui->tableView->setModel( temp.trier_client2());
}


void MainWindow::on_pushButton_24_clicked() //aller a ajout
{
    ui->label_43->setVisible(false);
   ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_pushButton_25_clicked() // aller a modif
{
    QSqlQuery query;
    int id = getIDFromTableView(ui->tableView);
    if(id != -1){
        query.prepare("Select * from clients where ID= :id");
        query.bindValue(":id" ,id);
        query.exec();
        QSqlQueryModel model;
        model.setQuery(query);
       //fill the blanks ...
        ui->label_50->setVisible(false);
        ui->stackedWidget->setCurrentIndex(2);
        ui->lineEdit_a_14->setText(QString ::number(id));
      }
    else
        QMessageBox::critical(nullptr, QObject::tr("Selection"),
                              QObject::tr("Veuillez selectionner un ID du table."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_26_clicked() // supp du client
{
    int id = getIDFromTableView(ui->tableView);
    if(id != -1){
       Client * c = new Client(id);
        c->supprimer_client(id);
     }else{
        QMessageBox::critical(nullptr, QObject::tr("Selection"),
                              QObject::tr("Veuillez selectionner un ID du table."), QMessageBox::Cancel);

    }
    on_pushButton_8_clicked(); // this function call is to refresh the table afte
    //clicking go back button
}

void MainWindow::on_pushButton_3_clicked() // aller ajout res
{

   ui->label_52->setVisible(false);
   ui->stackedWidget_2->setCurrentIndex(3);

}

void MainWindow::on_pushButton_4_clicked() // aller a modif res
{
    int id = getIDFromTableView(ui->tableView_2);
    if(id != -1){
    QSqlQuery query;
    query.prepare("Select * from RESERVATIONS where ID= :id ");
    query.bindValue(":id", id);
    query.exec();
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery(query);

    ui->label_40->setVisible(false);
    ui->stackedWidget_2->setCurrentIndex(1);
    }else{
        QMessageBox::critical(nullptr, QObject::tr("Selection"),
                              QObject::tr("Veuillez selectionner un ID du table."), QMessageBox::Cancel);
    }
}

void MainWindow::on_pushButton_5_clicked() //aller au supp res
{
    ui->label_53->setVisible(false);
    ui->stackedWidget_2->setCurrentIndex(2);
 }



void MainWindow::on_pushButton_11_clicked() //affichage res
{
    ui->tableView_2->setModel( tempr.afficher_res());
}


void MainWindow::on_pushButton_2_clicked() //aller au recherche res
{
    ui->label_54->setVisible(false);
    ui->stackedWidget_2->setCurrentIndex(4);
}



void MainWindow::on_pushButton_28_clicked()
{
    ui->tableView_2->setModel( tempr.trier_res());
}

void MainWindow::on_pushButton_29_clicked()
{
   ui->tableView_2->setModel( tempr.trier_res_2());
}

void MainWindow::on_pushButton_23_clicked()
{
    int ID = ui->lineEdit_18->text().toInt();
    QSqlQueryModel * test=tempr.chercher_res(ID);
    if(test != nullptr)
    {
        QMessageBox::information(nullptr, QObject::tr("chercher une resrvation"),
                    QObject::tr("Res trouvé.\n"
                                "Click Cancel to get informations."), QMessageBox::Cancel);
            ui->tableView_5->setModel(test);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("chercher une reservation"),
                    QObject::tr("Erreur , Res introuvable !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}
}

void MainWindow::on_pushButton_12_clicked()
{
    ui->label->setVisible(false);
    ui->stackedWidget_2->setCurrentIndex(0);
}

void MainWindow::on_pushButton_13_clicked()
{
    ui->label->setVisible(false);
    ui->stackedWidget_2->setCurrentIndex(0);
}

void MainWindow::on_pushButton_14_clicked()
{
    ui->label->setVisible(false);
    ui->stackedWidget_2->setCurrentIndex(0);
}

void MainWindow::on_pushButton_15_clicked()
{
    ui->label->setVisible(false);
    ui->stackedWidget_2->setCurrentIndex(0);
}

void MainWindow::on_pushButton_16_clicked()
{
    ui->label->setVisible(false);
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_17_clicked()
{
    ui->label->setVisible(false);
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_18_clicked()
{
    ui->label->setVisible(false);
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_27_clicked()
{
    ui->label_55->setVisible(false);
    ui->stackedWidget->setCurrentIndex(3);
}





