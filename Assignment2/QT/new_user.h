#ifndef NEW_USER_H
#define NEW_USER_H

#include <QDialog>

namespace Ui {
class New_User;
}

class New_User : public QDialog
{
    Q_OBJECT

public:
    explicit New_User(QWidget *parent = 0);
    ~New_User();

private slots:
    void on_createaccount_clicked();

private:
       Ui::New_User *ui;
};

#endif // NEW_USER_H
