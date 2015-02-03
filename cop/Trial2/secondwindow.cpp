#include "secondwindow.h"
#include "ui_secondwindow.h"
#include <bits/stdc++.h>
#include <fstream>
#include <QFile>
#include <QTextStream>
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
    QByteArray ba = user.toLocal8Bit();
    const char *c = ba.data();
    string username= string(c);
    cout<<username<<endl;
  /*  ofstream userpass;
    userpass.open("Username.txt");
    userpass<< username<<"\n";
    userpass.close();*/
    QFile fMyFile("apname.txt");
    fMyFile.open(QIODevice::WriteOnly);
    QTextStream stream( &fMyFile);
    stream <<"agjkflj"<< endl;
    fMyFile.close();
}
