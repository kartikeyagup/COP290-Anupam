/********************************************************************************
** Form generated from reading UI file 'onlyusername.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ONLYUSERNAME_H
#define UI_ONLYUSERNAME_H

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

class Ui_Onlyusername
{
public:
    QPushButton *Next_push;
    QPushButton *Cancel_push;
    QLabel *username_label;
    QLineEdit *username2_line;

    void setupUi(QDialog *Onlyusername)
    {
        if (Onlyusername->objectName().isEmpty())
            Onlyusername->setObjectName(QStringLiteral("Onlyusername"));
        Onlyusername->resize(400, 300);
        Next_push = new QPushButton(Onlyusername);
        Next_push->setObjectName(QStringLiteral("Next_push"));
        Next_push->setGeometry(QRect(40, 220, 99, 27));
        Cancel_push = new QPushButton(Onlyusername);
        Cancel_push->setObjectName(QStringLiteral("Cancel_push"));
        Cancel_push->setGeometry(QRect(230, 220, 99, 27));
        username_label = new QLabel(Onlyusername);
        username_label->setObjectName(QStringLiteral("username_label"));
        username_label->setGeometry(QRect(50, 70, 81, 17));
        username2_line = new QLineEdit(Onlyusername);
        username2_line->setObjectName(QStringLiteral("username2_line"));
        username2_line->setGeometry(QRect(40, 110, 281, 27));

        retranslateUi(Onlyusername);

        QMetaObject::connectSlotsByName(Onlyusername);
    } // setupUi

    void retranslateUi(QDialog *Onlyusername)
    {
        Onlyusername->setWindowTitle(QApplication::translate("Onlyusername", "Dialog", 0));
        Next_push->setText(QApplication::translate("Onlyusername", "Next", 0));
        Cancel_push->setText(QApplication::translate("Onlyusername", "Cancel", 0));
        username_label->setText(QApplication::translate("Onlyusername", "Username", 0));
    } // retranslateUi

};

namespace Ui {
    class Onlyusername: public Ui_Onlyusername {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ONLYUSERNAME_H
