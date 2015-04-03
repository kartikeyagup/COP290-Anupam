#include "filewindow.h"
#include "ui_filewindow.h"
#include <QtCore>
#include <QtGui>
#include <qdir.h>

FileWindow::FileWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FileWindow)
{
    ui->setupUi(this);
    ui->setupUi(this);
    QString Path = "/homjkhkjhjhkjhjlkhhjgcersersdyfguihjopijiuye";
    dirmodel = new QFileSystemModel(this);
    dirmodel->setRootPath(Path);
    //dirmodel->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs);
    ui->directoryview->setModel(dirmodel);

    filemodel = new QFileSystemModel(this);
    filemodel->setRootPath(Path);
    filemodel->setFilter(QDir::NoDotAndDotDot | QDir::Files);
    ui->filelistview->setModel(filemodel);
}

FileWindow::~FileWindow()
{
    delete ui;
}

void FileWindow::on_treeView_clicked(const QModelIndex &index)
{
    QString Path= dirmodel->fileInfo(index).absoluteFilePath();
    ui->filelistview->setRootIndex(filemodel->setRootPath(Path));

}
