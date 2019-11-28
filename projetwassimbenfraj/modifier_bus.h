#ifndef MODIFIER_BUS_H
#define MODIFIER_BUS_H

#include <QDialog>

namespace Ui {
class modifier_bus;
}

class modifier_bus : public QDialog
{
    Q_OBJECT

public:
    explicit modifier_bus(QWidget *parent = nullptr);
    ~modifier_bus();

private slots:
    void on_pushButton_5_clicked();

private:
    Ui::modifier_bus *ui;
};

#endif // MODIFIER_BUS_H
