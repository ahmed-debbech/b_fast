#ifndef OPTIONS_H
#define OPTIONS_H

#include <QMainWindow>

namespace Ui {
class Options;
}

class Options : public QMainWindow
{
    Q_OBJECT

public:
    explicit Options(QWidget *parent = nullptr);
    ~Options();

private:
    Ui::Options *ui;
};

#endif // OPTIONS_H
