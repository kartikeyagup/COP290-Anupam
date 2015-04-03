#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QDialog>

namespace Ui {
class Secondwindow;
}

class Secondwindow : public QDialog
{
    Q_OBJECT

public:
    explicit Secondwindow(QWidget *parent = 0);
    ~Secondwindow();

private slots:
    void on_login_clicked();

    void on_forgot_clicked();

private:
    Ui::Secondwindow *ui;
};

#endif // SECONDWINDOW_H
