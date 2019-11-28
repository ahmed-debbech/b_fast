#ifndef AJOUTBUS_H
#define AJOUTBUS_H

#include <QDialog>

namespace Ui {
class ajoutbus;
}
class QSystemTrayIcon;

class ajoutbus : public QDialog
{
    Q_OBJECT

public:
    explicit ajoutbus(QWidget *parent = nullptr);
    ~ajoutbus();

private slots:
    void on_pushButton_5_clicked();

private:
    Ui::ajoutbus *ui;
    QSystemTrayIcon *mysystem;
};

#endif // AJOUTBUS_H
