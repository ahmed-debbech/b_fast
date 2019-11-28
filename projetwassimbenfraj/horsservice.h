#ifndef HORSSERVICE_H
#define HORSSERVICE_H

#include <QDialog>
#include "bus.h"

namespace Ui {
class horsservice;
}

class horsservice : public QDialog
{
    Q_OBJECT

public:
    explicit horsservice(QWidget *parent = nullptr);
    ~horsservice();

private slots:
    void on_pushButton_5_clicked();

private:
    Ui::horsservice *ui;
    bus tmpbus;
};

#endif // HORSSERVICE_H
