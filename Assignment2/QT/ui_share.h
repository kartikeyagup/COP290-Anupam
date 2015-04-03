/********************************************************************************
** Form generated from reading UI file 'share.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHARE_H
#define UI_SHARE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_Share
{
public:
    QPushButton *pushButton;
    QLabel *label;
    QLineEdit *otheruser;
    QRadioButton *viewradio;
    QRadioButton *editradio;
    QListWidget *serverlist;

    void setupUi(QDialog *Share)
    {
        if (Share->objectName().isEmpty())
            Share->setObjectName(QStringLiteral("Share"));
        Share->resize(682, 370);
        pushButton = new QPushButton(Share);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(470, 310, 99, 27));
        label = new QLabel(Share);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(110, 60, 131, 17));
        otheruser = new QLineEdit(Share);
        otheruser->setObjectName(QStringLiteral("otheruser"));
        otheruser->setGeometry(QRect(110, 90, 241, 27));
        viewradio = new QRadioButton(Share);
        viewradio->setObjectName(QStringLiteral("viewradio"));
        viewradio->setGeometry(QRect(120, 140, 117, 21));
        editradio = new QRadioButton(Share);
        editradio->setObjectName(QStringLiteral("editradio"));
        editradio->setGeometry(QRect(120, 180, 117, 22));
        serverlist = new QListWidget(Share);
        serverlist->setObjectName(QStringLiteral("serverlist"));
        serverlist->setGeometry(QRect(390, 30, 256, 241));
        serverlist->setSelectionMode(QAbstractItemView::MultiSelection);

        retranslateUi(Share);

        QMetaObject::connectSlotsByName(Share);
    } // setupUi

    void retranslateUi(QDialog *Share)
    {
        Share->setWindowTitle(QApplication::translate("Share", "Dialog", 0));
        pushButton->setText(QApplication::translate("Share", "Share", 0));
        label->setText(QApplication::translate("Share", "Enter Username", 0));
        viewradio->setText(QApplication::translate("Share", "View Only", 0));
        editradio->setText(QApplication::translate("Share", "Edit only", 0));
    } // retranslateUi

};

namespace Ui {
    class Share: public Ui_Share {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHARE_H
