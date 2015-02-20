#include "question.h"
#include "ui_question.h"
#include "changepassword.h"
#include <bits/stdc++.h>
#include <fstream>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QCoreApplication>
#include <question.h>
#include <qmessagebox.h>
#include "onlyusername.h"
using namespace std;

question::question(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::question)
{
    ui->setupUi(this);
}

question::~question()
{
    delete ui;
}

void question::on_pushButton_clicked()
{
    ifstream usercheckfile;
    usercheckfile.open("/home/ronak8/Desktop/Untitled Folder 2/usernamefinal.txt");
    string check;
    char ch='\n';
    while(getline(usercheckfile,check,ch)){
       ui->label_securityques->setText("gkhgkgh");
    }
    usercheckfile.close();



    QString user;
    user= ui->answerask->text();
    QByteArray ba = user.toLocal8Bit();
    const char *c = ba.data();
    string answer= string(c);
    ofstream fil;
    fil.open("/home/ronak8/Desktop/Untitled Folder 2/usernamefinal.txt");
    fil<<answer;
    fil.close();

    ifstream user1checkfile;
    user1checkfile.open("/home/ronak8/Desktop/Untitled Folder 2/usernamefinal.txt");
    string check1;
    char cho='\n';
    getline(user1checkfile,check,cho);
    user1checkfile.close();
    if(check1=="0"){
      QMessageBox::information(this,"Warning","answer is incorrect");
    }
    else{
        this->hide();
        changepassword secnew;
        secnew.exec();
        secnew.show();
    }






}
