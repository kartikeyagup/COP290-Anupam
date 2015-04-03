/********************************************************************************
** Form generated from reading UI file 'changepassword.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGEPASSWORD_H
#define UI_CHANGEPASSWORD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_changepassword
{
public:
    QPushButton *proceed_push;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *newpass_line;
    QLabel *label_2;
    QLineEdit *renewpass_line;

    void setupUi(QDialog *changepassword)
    {
        if (changepassword->objectName().isEmpty())
            changepassword->setObjectName(QStringLiteral("changepassword"));
        changepassword->resize(400, 300);
        proceed_push = new QPushButton(changepassword);
        proceed_push->setObjectName(QStringLiteral("proceed_push"));
        proceed_push->setGeometry(QRect(250, 220, 99, 27));
        widget = new QWidget(changepassword);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(20, 40, 361, 141));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        newpass_line = new QLineEdit(widget);
        newpass_line->setObjectName(QStringLiteral("newpass_line"));

        verticalLayout->addWidget(newpass_line);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        renewpass_line = new QLineEdit(widget);
        renewpass_line->setObjectName(QStringLiteral("renewpass_line"));

        verticalLayout->addWidget(renewpass_line);


        retranslateUi(changepassword);

        QMetaObject::connectSlotsByName(changepassword);
    } // setupUi

    void retranslateUi(QDialog *changepassword)
    {
        changepassword->setWindowTitle(QApplication::translate("changepassword", "Dialog", 0));
        proceed_push->setText(QApplication::translate("changepassword", "Proceed", 0));
        label->setText(QApplication::translate("changepassword", "Enter new password", 0));
        label_2->setText(QApplication::translate("changepassword", "Re-enter password", 0));
    } // retranslateUi

};

namespace Ui {
    class changepassword: public Ui_changepassword {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGEPASSWORD_H
