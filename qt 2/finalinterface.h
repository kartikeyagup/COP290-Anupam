#ifndef FINALINTERFACE_H
#define FINALINTERFACE_H

#include <QDialog>
#include <QtCore>
#include <QtGui>
#include <QFileSystemModel>

namespace Ui {
class Finalinterface;
}

class Finalinterface : public QDialog
{
    Q_OBJECT

public:
    explicit Finalinterface(QWidget *parent = 0);
    ~Finalinterface();

private slots:
    void on_directoryview_clicked(const QModelIndex &index);

private:
    Ui::Finalinterface *ui;
    QFileSystemModel *dirmodel;
    QFileSystemModel *filemodel;


};

#endif // FINALINTERFACE_H
