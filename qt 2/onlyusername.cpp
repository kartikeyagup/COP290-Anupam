#include "onlyusername.h"
#include "ui_onlyusername.h"
#include "changepassword.h"
#include "secondwindow.h"
#include <string>
#include <iostream>
#include <fstream>
#include <qmessagebox.h>
using namespace std;

Onlyusername::Onlyusername(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Onlyusername)
{
    ui->setupUi(this);
}

Onlyusername::~Onlyusername()
{
    delete ui;
}

void Onlyusername::on_Next_push_clicked()
{
    QString user;
    user= ui->username2_line->text();
    QByteArray ba = user.toLocal8Bit();
    const char *c = ba.data();
    string username= string(c);
    ofstream userfile;
    userfile.open("/home/ronak8/Desktop/Untitled Folder 2/usernameagain.txt");
    userfile<<username;
    userfile.close();
    ifstream checkuserfile;
    checkuserfile.open("/home/ronak8/Desktop/Untitled Folder 2/checkusernameagain.txt");
    char a= getchar();
    if(a=='0'){
        QMessageBox::information(this,"Warning","username incorrect");
    }
    else{
        this->hide();
        Onlyusername secnew;
        secnew.exec();
        secnew.show();
    }


}

void Onlyusername::on_Cancel_push_clicked()
{
    this->hide();
    Secondwindow secnew;
    secnew.exec();
    secnew.show();
}
