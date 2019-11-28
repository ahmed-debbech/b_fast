#ifndef POUBELLE_H
#define POUBELLE_H

#include <QDialog>

namespace Ui {
class Poubelle;
}

class Poubelle : public QDialog
{
    Q_OBJECT

public:
    explicit Poubelle(QWidget *parent = nullptr);
    ~Poubelle();

private:
    Ui::Poubelle *ui;
};

#endif // POUBELLE_H
