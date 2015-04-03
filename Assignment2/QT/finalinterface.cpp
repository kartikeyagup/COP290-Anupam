#include "finalinterface.h"
#include "ui_finalinterface.h"
#include <QtCore>
#include <QtGui>
#include <qdir.h>
Finalinterface::Finalinterface(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Finalinterface)
{
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

Finalinterface::~Finalinterface()
{
    delete ui;
}

void Finalinterface::on_directoryview_clicked(const QModelIndex &index)
{
    QString Path= dirmodel->fileInfo(index).absoluteFilePath();
    ui->filelistview->setRootIndex(filemodel->setRootPath(Path));
}
