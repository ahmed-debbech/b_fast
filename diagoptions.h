#ifndef DIAGOPTIONS_H
#define DIAGOPTIONS_H

#include <QDialog>

namespace Ui {
class Diagoptions;
}

class Diagoptions : public QDialog
{
    Q_OBJECT

public:
    explicit Diagoptions(QWidget *parent = nullptr);
    ~Diagoptions();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Diagoptions *ui1;
};

#endif // DIAGOPTIONS_H
