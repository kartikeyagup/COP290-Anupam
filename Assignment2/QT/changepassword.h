#ifndef CHANGEPASSWORD_H
#define CHANGEPASSWORD_H

#include <QDialog>

namespace Ui {
class changepassword;
}

class changepassword : public QDialog
{
    Q_OBJECT

public:
    explicit changepassword(QWidget *parent = 0);
    ~changepassword();

private slots:
    void on_proceed_push_clicked();

private:
    Ui::changepassword *ui;
};

#endif // CHANGEPASSWORD_H
