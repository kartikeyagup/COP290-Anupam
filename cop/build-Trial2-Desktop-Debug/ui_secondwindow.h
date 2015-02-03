/********************************************************************************
** Form generated from reading UI file 'secondwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SECONDWINDOW_H
#define UI_SECONDWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Secondwindow
{
public:
    QLineEdit *usernametext;
    QLineEdit *passwordtext;
    QPushButton *login;
    QPushButton *forgot;
    QLabel *usernamelabel;
    QLabel *passwordlabel;

    void setupUi(QDialog *Secondwindow)
    {
        if (Secondwindow->objectName().isEmpty())
            Secondwindow->setObjectName(QStringLiteral("Secondwindow"));
        Secondwindow->resize(400, 300);
        usernametext = new QLineEdit(Secondwindow);
        usernametext->setObjectName(QStringLiteral("usernametext"));
        usernametext->setGeometry(QRect(190, 50, 113, 27));
        passwordtext = new QLineEdit(Secondwindow);
        passwordtext->setObjectName(QStringLiteral("passwordtext"));
        passwordtext->setGeometry(QRect(190, 100, 113, 27));
        login = new QPushButton(Secondwindow);
        login->setObjectName(QStringLiteral("login"));
        login->setGeometry(QRect(110, 170, 99, 27));
        forgot = new QPushButton(Secondwindow);
        forgot->setObjectName(QStringLiteral("forgot"));
        forgot->setGeometry(QRect(240, 170, 99, 27));
        usernamelabel = new QLabel(Secondwindow);
        usernamelabel->setObjectName(QStringLiteral("usernamelabel"));
        usernamelabel->setGeometry(QRect(60, 50, 71, 17));
        passwordlabel = new QLabel(Secondwindow);
        passwordlabel->setObjectName(QStringLiteral("passwordlabel"));
        passwordlabel->setGeometry(QRect(60, 110, 67, 17));

        retranslateUi(Secondwindow);

        QMetaObject::connectSlotsByName(Secondwindow);
    } // setupUi

    void retranslateUi(QDialog *Secondwindow)
    {
        Secondwindow->setWindowTitle(QApplication::translate("Secondwindow", "Dialog", 0));
        login->setText(QApplication::translate("Secondwindow", "login", 0));
        forgot->setText(QApplication::translate("Secondwindow", "forgot", 0));
        usernamelabel->setText(QApplication::translate("Secondwindow", "Username", 0));
        passwordlabel->setText(QApplication::translate("Secondwindow", "Password", 0));
    } // retranslateUi

};

namespace Ui {
    class Secondwindow: public Ui_Secondwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SECONDWINDOW_H
