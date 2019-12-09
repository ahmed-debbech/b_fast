#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <string>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QString>
#include <QDebug>
#include <QSqlRecord>
#include <QSqlQueryModel>
#include <QItemSelectionModel>
#include <QSqlTableModel>
#include <QVariant>
#include <QList>
#include <QChar>
#include <string>
#include "subscriber.h"
#include "subscription.h"
#include <QTableView>
#include "subscription.h"
#include <QPalette>
#include <QMessageBox>
#include <QSqlDatabase>
#include "mailing/smtpclient.h"
#include "mailing/SmtpMime"
//#include <openssl/aes.h>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    on_pushButton_7_clicked(); //show subscribers

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

void MainWindow::on_pushButton_3_clicked()
{
    ui->label_12->setVisible(false);
   ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_7_clicked(){
    Subscriber * s = new Subscriber();
    QSqlQueryModel *model = s->showSubscriber();
    ui->list->setModel(model);
    delete s;
}

void MainWindow::on_pushButton_5_clicked()
{
    int id = getIDFromTableView(ui->list);
    if(id != -1){
        Subscriber * s = new Subscriber(id);
        s->delSubscriber();
     }else{
        QMessageBox::critical(nullptr, QObject::tr("Selection"),
                              QObject::tr("Il faut selecter un element d'abord"), QMessageBox::Cancel);

    }
    on_pushButton_7_clicked(); // this function call is to refresh the table afte
    //clicking go back button
}

void MainWindow::on_pushButton_4_clicked()
{
    QSqlQuery query;
    int id = getIDFromTableView(ui->list);
    if(id != -1){
        query.prepare("Select * from abonne where ID_ABONNEE= :id");
        query.bindValue(":id" ,id);
        query.exec();
        QSqlQueryModel model;
        model.setQuery(query);
       //fill the blanks ...
        ui->label_19->setVisible(false);
        ui->stackedWidget->setCurrentIndex(2);
       QString res = "Subscriber's ID: " + QString::number(id);
       ui->label_18->setText(res);
       ui->lineEdit_5->setText(model.record(0).value("NOM").toString());
       ui->lineEdit_7->setText(model.record(0).value("PRENOM").toString());
       QString sexe = model.record(0).value("SEXE").toString();
       ui->lineEdit_6->setText(QString::number(model.record(0).value("PIN").toInt()));
       QSqlRecord rec = model.record(0);
       ui->lineEdit_18->setText(rec.value("EMAIL").toString());

       if(sexe == "m"){
           ui->radioButton_3->setChecked(true);
           ui->radioButton_4->setChecked(false);
        }else{
           ui->radioButton_3->setChecked(false);
           ui->radioButton_4->setChecked(true);
        }
    }else{
        QMessageBox::critical(nullptr, QObject::tr("Selection"),
                              QObject::tr("Il faut selecter un element d'abord."), QMessageBox::Cancel);
    }
}

void MainWindow::on_list_clicked(){
    int id = getIDFromTableView(ui->list);
    Subscription * s = new Subscription();
    QSqlQueryModel * model = s->showSubs(id);
    ui->tableView->setModel(model);
    delete s;
}

void MainWindow::on_pushButton_9_clicked()
{
    int id = getIDFromTableView(ui->list);
    if(id != -1){
        ui->label_21->setText("Subscriber's ID: " + QString::number(id));
        ui->stackedWidget_2->setCurrentIndex(1);
    }else{
        QMessageBox::critical(nullptr, QObject::tr("Selection"),
                              QObject::tr("Il faut selecter un element d'abord."), QMessageBox::Cancel);
    }
}

void MainWindow::on_pushButton_11_clicked()
{
    on_list_clicked();
    //i called this function here because it does the same thing
    //as refreshing subsciptions
}

void MainWindow::on_pushButton_8_clicked()
{
    int id = getIDFromTableView(ui->tableView);
    if(id != -1){
    QSqlQuery query;
    query.prepare("Select * from abonnement where id_abonn= :id ");
    query.bindValue(":id", id);
    query.exec();
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery(query);
    ui->label_33->setText("Subscriber's ID: " + model->record(0).value(6).toString());
    ui->label_32->setText("Subscription's ID: " + model->record(0).value(0).toString());
    ui->lineEdit_15->setText(model->record(0).value(1).toString());
    ui->lineEdit_14->setText(model->record(0).value(2).toString());
    ui->lineEdit_13->setText(model->record(0).value(3).toString());
    ui->lineEdit_16->setText(model->record(0).value(4).toString());
    ui->stackedWidget_2->setCurrentIndex(2);
    }else{
        QMessageBox::critical(nullptr, QObject::tr("Selection"),
                              QObject::tr("Il faut selecter un element d'abord."), QMessageBox::Cancel);
    }
}

void MainWindow::on_pushButton_10_clicked()
{
    int id = getIDFromTableView(ui->tableView);
    Subscription * s = new Subscription(id);
    s->delSubs();
    delete s;
}

void MainWindow::on_pushButton_13_clicked()
{
    on_pushButton_7_clicked(); // this function call is to refresh the table afte
    //clicking go back button
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_12_clicked()
{
    QString sex = "u"; //to initialize as unknown
    if(ui->radioButton->isChecked() == true){
        sex = "m";
    }else{
        if(ui->radioButton_2->isChecked() == true){
            sex = "f";
        }
    }
    ui->lineEdit->text();
    Subscriber * s= new Subscriber(ui->lineEdit->text().toInt(),
                                   ui->lineEdit_2->text(),
                                   ui->lineEdit_3->text(),
                                   sex,
                                   ui->lineEdit_4->text().toInt(),
                                   0, ui->lineEdit_17->text());
    ui->label_12->setVisible(true);
    if(s->addSubscriber() == true){
        ui->label_12->setText("Status: Ajoute avec succes!");
        QPalette palette = ui->label_12->palette();
         palette.setColor(ui->label_12->foregroundRole(), Qt::green);
         ui->label_12->setPalette(palette);
    }else {
        ui->label_12->setText("Status: Ne peut pas ajouter!");
        QPalette palette = ui->label_12->palette();
         palette.setColor(ui->label_12->foregroundRole(), Qt::red);
         ui->label_12->setPalette(palette);
    }
    delete s;

}

void MainWindow::on_pushButton_15_clicked()
{
    on_pushButton_7_clicked(); // this function call is to refresh the table afte
    //clicking go back button
   ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_14_clicked()
{
    QString sex = "u"; //to initialize as unknown
    if(ui->radioButton_3->isChecked() == true){
        sex = "m";
    }else{
        if(ui->radioButton_4->isChecked() == true){
            sex = "f";
        }
    }
    QRegularExpression rx("[0-9]+");
    QRegularExpressionMatch match = rx.match(ui->label_18->text());
    QString id_ab = match.captured(0);
    Subscriber * s= new Subscriber(id_ab.toInt(),
                                   ui->lineEdit_5->text(),
                                   ui->lineEdit_7->text(),
                                   sex,
                                   ui->lineEdit_6->text().toInt(),
                                   0, ui->lineEdit_18->text());
    ui->label_19->setVisible(true);
    if(s->modSubscriber() == true){
        ui->label_19->setText("Status: Modifie avec succes!");
        QPalette palette = ui->label_19->palette();
         palette.setColor(ui->label_19->foregroundRole(), Qt::green);
         ui->label_19->setPalette(palette);
    }else {
        ui->label_19->setText("Status: Ne peut pas modifier!");
        QPalette palette = ui->label_19->palette();
         palette.setColor(ui->label_19->foregroundRole(), Qt::red);
         ui->label_19->setPalette(palette);
    }
    delete s;

}

void MainWindow::on_pushButton_16_clicked()
{
    ui->lineEdit->setText("");
    ui->lineEdit_2->setText("");
    ui->lineEdit_3->setText("");
    ui->lineEdit_4->setText("");
    ui->radioButton->setChecked(false);
    ui->radioButton_2->setChecked(false);
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    Subscriber *s =new Subscriber();
    QSqlQueryModel * model = s->sort(index);
     ui->list->setModel(model);
    delete s;
}

void MainWindow::on_pushButton_17_clicked()
{
    QRegularExpression rx("[0-9]+");
    QRegularExpressionMatch match = rx.match(ui->label_21->text());
    QString qs = match.captured(0);
    Subscription *s = new Subscription(ui->lineEdit_8->text().toInt(),
                                       ui->lineEdit_10->text(),
                                       ui->lineEdit_9->text(),
                                       ui->lineEdit_12->text(),
                                       ui->lineEdit_11->text(), 0,
                                       qs.toInt());
    s->addSubs();
    delete s;

}

void MainWindow::on_pushButton_18_clicked(){

    Subscription *s = new Subscription();
    ui->tableView->setModel(s->showSubs(ui->label_21->text().toInt()));
    ui->stackedWidget_2->setCurrentIndex(0);
}

void MainWindow::on_pushButton_19_clicked()
{
    ui->lineEdit_8->setText("");
    ui->lineEdit_10->setText("");
    ui->lineEdit_9->setText("");
    ui->lineEdit_12->setText("");
    ui->lineEdit_11->setText("");

}

void MainWindow::on_pushButton_21_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);
}

void MainWindow::on_pushButton_20_clicked()
{
    QRegularExpression rx("[0-9]+");
    QRegularExpressionMatch match = rx.match(ui->label_33->text());
    QString id_ab = match.captured(0);
    QRegularExpressionMatch match1 = rx.match(ui->label_32->text());
    QString id= match1.captured(0);
    Subscription * s = new Subscription(id.toInt(),
                                        ui->lineEdit_15->text(),
                                        ui->lineEdit_14->text(),
                                         ui->lineEdit_13->text(),
                                         ui->lineEdit_16->text(),
                                         0, id_ab.toInt());
    s->modSubs();
}

void MainWindow::on_pushButton_6_clicked()
{
    QString key = ui->plainTextEdit->toPlainText();
    int index = ui->comboBox_2->itemData(ui->comboBox_2->currentIndex()).toInt();
    Subscriber * s = new Subscriber();
    QSqlQueryModel * q = s->search(index, key);
    if(q != nullptr){
        ui->list->setModel(q);
    }else{
        QMessageBox::critical(nullptr, QObject::tr("Warning"),
          QObject::tr("Cet abonnee n'est pas trouve."), QMessageBox::Cancel);
    }

}

void MainWindow::on_sendEmail_clicked()
{
    SmtpClient smtp("smtp.gmail.com", 465, SmtpClient::SslConnection);

        // We need to set the username (your email address) and the password
        // for smtp authentification.

        smtp.setUser(ui->username->text());
        smtp.setPassword(ui->password->text());
    // Now we create a MimeMessage object. This will be the email.

    MimeMessage message;

    message.setSender(new EmailAddress(ui->username->text(), ui->sender->text()));
    message.addRecipient(new EmailAddress(ui->recipients->text(), ""));
    message.setSubject(ui->subject->text());

    // Now add some text to the email.
    // First we create a MimeText object.

    MimeText text;

    text.setText(ui->texteditor->toPlainText());

    // Now add it to the mail

    message.addPart(&text);

    // Now we can send the mail

    smtp.connectToHost();
    smtp.login();
    smtp.sendMail(message);
    smtp.quit();
}

void MainWindow::on_pushButton_22_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}



void MainWindow::on_list_doubleClicked()
{
    int id = getIDFromTableView(ui->list);
    QSqlQuery query;
     query.prepare("Select * from abonne where ID_ABONNEE= :id");
     query.bindValue(":id", id);
    query.exec();
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery(query);
    ui->recipients->setText(model->record(0).value(6).toString());
    ui->stackedWidget->setCurrentIndex(3);
}
