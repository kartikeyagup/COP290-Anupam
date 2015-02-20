#ifndef ONLYUSERNAME_H
#define ONLYUSERNAME_H

#include <QDialog>

namespace Ui {
class Onlyusername;
}

class Onlyusername : public QDialog
{
    Q_OBJECT

public:
    explicit Onlyusername(QWidget *parent = 0);
    ~Onlyusername();

private slots:
    void on_Next_push_clicked();

    void on_Cancel_push_clicked();

private:
    Ui::Onlyusername *ui;
};

#endif // ONLYUSERNAME_H
