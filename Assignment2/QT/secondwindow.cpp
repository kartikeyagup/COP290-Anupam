#include "secondwindow.h"
#include "ui_secondwindow.h"
#include <bits/stdc++.h>
#include <fstream>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QCoreApplication>
#include <question.h>
#include <qmessagebox.h>
#include "finalinterface.h"
#include "onlyusername.h"
using namespace std;

Secondwindow::Secondwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Secondwindow)
{
    ui->setupUi(this);
}

Secondwindow::~Secondwindow()
{
    delete ui;
}

void Secondwindow::on_login_clicked()
{

    QString user;
    user= ui->usernametext->text();
    QString password;
    password= ui->passwordtext->text();
    QByteArray ba = user.toLocal8Bit();
    const char *c = ba.data();
    string username= string(c);
    QByteArray pass = password.toLocal8Bit();
    const char *cpass = pass.data();
    string passwordstr = string(cpass);
    ofstream fil;
    fil.open("/home/ronak8/Desktop/Untitled Folder 2/usernamefinal.txt");
    fil<<username<<"\n";
    fil<<passwordstr;
    fil.close();
    ifstream usercheckfile;
    usercheckfile.open("/home/ronak8/Desktop/Untitled Folder 2/usernamefinal.txt");
    char a=getchar();
    if(a=='0'){
        QMessageBox::information(this,"Warning","username or password is incorrect");
    }
    else{
        this->hide();
        Finalinterface object(this);
        object.exec();
        object.show();
    }
}

void Secondwindow::on_forgot_clicked()
{

    this->hide();
    Onlyusername useronly(this);
    useronly.exec();
    useronly.show();




}


