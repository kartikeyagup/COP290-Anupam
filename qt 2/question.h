#ifndef QUESTION_H
#define QUESTION_H

#include <QDialog>

namespace Ui {
class question;
}

class question : public QDialog
{
    Q_OBJECT

public:
    explicit question(QWidget *parent = 0);
    ~question();

private slots:
    void on_pushButton_clicked();

private:
    Ui::question *ui;
};

#endif // QUESTION_H
