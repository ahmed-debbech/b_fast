#ifndef AJOUTRAPPEL_H
#define AJOUTRAPPEL_H

#include <QDialog>

namespace Ui {
class ajoutrappel;
}

class ajoutrappel : public QDialog
{
    Q_OBJECT

public:
    explicit ajoutrappel(QWidget *parent = nullptr);
    ~ajoutrappel();

private:
    Ui::ajoutrappel *ui;
};

#endif // AJOUTRAPPEL_H
