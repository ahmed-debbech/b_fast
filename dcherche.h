#ifndef DCHERCHE_H
#define DCHERCHE_H

#include <QDialog>

namespace Ui {
class dcherche;
}

class dcherche : public QDialog
{
    Q_OBJECT

public:
    explicit dcherche(QWidget *parent = nullptr);
    ~dcherche();

private:
    Ui::dcherche *ui;
};

#endif // DCHERCHE_H
