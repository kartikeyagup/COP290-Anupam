#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "secondwindow.h"
#include "new_user.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap bkgnd("/home/ronak8/Desktop/download.jpg");
   bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
   QPalette palette;
   palette.setBrush(QPalette::Background, bkgnd);
   this->setPalette(palette);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_signin_clicked()
{

   /* this->hide();
    Secondwindow sec(this);
    sec.exec();
    sec.show();*/
}

void MainWindow::on_newuser_clicked()
{
    this->hide();
    New_User newuser(this);
    newuser.exec();

    newuser.show();


}
