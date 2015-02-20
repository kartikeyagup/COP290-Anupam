#include "new_user.h"
#include "ui_new_user.h"
#include "secondwindow.h"
#include <qlineedit.h>
#include <fstream>
#include <vector>
#include <iostream>
#include <qmessagebox.h>
using namespace std;

New_User::New_User(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::New_User)
{
    ui->setupUi(this);
    ui->name_lineedit->setPlaceholderText("Enter Name");
    ui->surname_lineedit->setPlaceholderText("Enter Surname");
    ui->securityquestion->setPlaceholderText("Enter Security Question");
    ui->answer->setPlaceholderText("Enter Answer");
}

New_User::~New_User()
{
    delete ui;
}

void New_User::on_createaccount_clicked()
{
    vector<pair<string,QString> > newuserinfo;
    vector<string> newuserinfostring;
//    if(ui->name_lineedit->text()==""){
//
//        }
//    }
    newuserinfo.push_back(make_pair("First name",ui->name_lineedit->text()));
    newuserinfo.push_back(make_pair("Surname",ui->surname_lineedit->text()));
    newuserinfo.push_back(make_pair("Username",ui->username1_lineedit->text()));
    newuserinfo.push_back(make_pair("password",ui->password1_lineedit->text()));
    newuserinfo.push_back(make_pair("security",ui->securityquestion->text()));
    newuserinfo.push_back(make_pair("answer",ui->answer->text()));
    for(int i=0;i<newuserinfo.size();i++){
        QByteArray ba = newuserinfo[i].second.toLocal8Bit();
        const char *c = ba.data();
        newuserinfostring.push_back(string(c));
    }
    int count=0;
    string a="";
    for(int i=0;i<newuserinfostring.size();i++){
        if(newuserinfostring[i]==""){
            a+=newuserinfo[i].first;
            a= a+ ","+ " ";
        }
    }
    if(a!=""){
        a=a.substr(0,a.size()-2);
        a=a+":"+"not provided";
        QMessageBox::information(this,"Unable to create account","please provide all information");
    }
    else if(ui->password1_lineedit->text()!=ui->repassword_lineedit->text()){
        QMessageBox::information(this,"Unable to create account","Passwords do not match");
    }
    else{
        ofstream newuserfile;
        newuserfile.open("/home/ronak8/Desktop/Untitled Folder 2/newuserfile.txt");
        for(int i=0;i<newuserinfostring.size();i++){
            if(i==0){
                newuserfile<<newuserinfostring[i]<<" ";
            }
            else{
                newuserfile<<newuserinfostring[i]<<"\n";
            }
        }
        QMessageBox::information(this,"Account Created","Account successfully Created");
        this->hide();
        Secondwindow secnew;
        secnew.exec();
        secnew.show();
        newuserfile.close();
    }

}


