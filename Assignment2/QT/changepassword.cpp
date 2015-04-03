#include "changepassword.h"
#include "ui_changepassword.h"
#include <string>
#include <iostream>
#include <fstream>
#include <qmessagebox.h>
using namespace std;

changepassword::changepassword(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::changepassword)
{
    ui->setupUi(this);
}

changepassword::~changepassword()
{
    delete ui;
}

void changepassword::on_proceed_push_clicked()
{
    /*QString user;
    user= ui->newpass_line->text();
    QString password;
    password= ui->renewpass_line->text();
    QByteArray ba = user.toLocal8Bit();
    const char *c = ba.data();
    string username= string(c);
    QByteArray pass = password.toLocal8Bit();
    const char *cpass = pass.data();
    string passwordstr = string(cpass);
    if(username==passwordstr){
        ofstream fil;
        fil.open("/home/ronak8/Desktop/Untitled Folder 2/changedpassfinal.txt");
        fil<<username;
        fil.close();
    }
    else{
        QMessageBox::information(this,"Warning","passwords don't match");
    }*/
}
