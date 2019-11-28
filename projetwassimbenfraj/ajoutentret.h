#ifndef AJOUTENTRET_H
#define AJOUTENTRET_H

#include <QDialog>

namespace Ui {
class ajoutentret;

}
class QSystemTrayIcon;
class ajoutentret : public QDialog
{
    Q_OBJECT

public:
    explicit ajoutentret(QWidget *parent = nullptr);
    ~ajoutentret();

private:
    Ui::ajoutentret *ui;
    QSystemTrayIcon * mysystem;
};

#endif // AJOUTENTRET_H
