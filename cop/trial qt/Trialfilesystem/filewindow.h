#ifndef FILEWINDOW_H
#define FILEWINDOW_H

#include <QDialog>
#include <QtCore>
#include <QtGui>
#include <QFileSystemModel>

namespace Ui {
class FileWindow;
}

class FileWindow : public QDialog
{
    Q_OBJECT

public:
    explicit FileWindow(QWidget *parent = 0);
    ~FileWindow();

private slots:
    void on_treeView_clicked(const QModelIndex &index);

private:
    Ui::FileWindow *ui;
       QFileSystemModel *dirmodel;
    QFileSystemModel *filemodel;
};

#endif // FILEWINDOW_H
