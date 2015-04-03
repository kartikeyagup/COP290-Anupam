/********************************************************************************
** Form generated from reading UI file 'new_user.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEW_USER_H
#define UI_NEW_USER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_New_User
{
public:
    QLabel *Name;
    QLabel *label_2;
    QPushButton *createaccount;
    QLineEdit *username1_lineedit;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *password1_lineedit;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLineEdit *name_lineedit;
    QLineEdit *surname_lineedit;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLineEdit *repassword_lineedit;
    QLineEdit *securityquestion;
    QLineEdit *answer;

    void setupUi(QDialog *New_User)
    {
        if (New_User->objectName().isEmpty())
            New_User->setObjectName(QStringLiteral("New_User"));
        New_User->resize(609, 435);
        New_User->setAutoFillBackground(true);
        Name = new QLabel(New_User);
        Name->setObjectName(QStringLiteral("Name"));
        Name->setGeometry(QRect(70, 20, 67, 17));
        label_2 = new QLabel(New_User);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(70, 90, 81, 21));
        createaccount = new QPushButton(New_User);
        createaccount->setObjectName(QStringLiteral("createaccount"));
        createaccount->setGeometry(QRect(70, 390, 131, 27));
        createaccount->setAutoDefault(false);
        username1_lineedit = new QLineEdit(New_User);
        username1_lineedit->setObjectName(QStringLiteral("username1_lineedit"));
        username1_lineedit->setGeometry(QRect(70, 120, 491, 27));
        username1_lineedit->setFocusPolicy(Qt::ClickFocus);
        label_3 = new QLabel(New_User);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(70, 160, 121, 17));
        label_4 = new QLabel(New_User);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(70, 230, 141, 17));
        password1_lineedit = new QLineEdit(New_User);
        password1_lineedit->setObjectName(QStringLiteral("password1_lineedit"));
        password1_lineedit->setGeometry(QRect(70, 190, 491, 27));
        password1_lineedit->setFocusPolicy(Qt::ClickFocus);
        password1_lineedit->setEchoMode(QLineEdit::Password);
        layoutWidget = new QWidget(New_User);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(70, 50, 491, 29));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        name_lineedit = new QLineEdit(layoutWidget);
        name_lineedit->setObjectName(QStringLiteral("name_lineedit"));
        name_lineedit->setEnabled(true);
        name_lineedit->setFocusPolicy(Qt::ClickFocus);
        name_lineedit->setContextMenuPolicy(Qt::DefaultContextMenu);
        name_lineedit->setAcceptDrops(true);
        name_lineedit->setFrame(true);
        name_lineedit->setCursorPosition(0);

        horizontalLayout->addWidget(name_lineedit);

        surname_lineedit = new QLineEdit(layoutWidget);
        surname_lineedit->setObjectName(QStringLiteral("surname_lineedit"));
        surname_lineedit->setFocusPolicy(Qt::ClickFocus);

        horizontalLayout->addWidget(surname_lineedit);

        widget = new QWidget(New_User);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(70, 260, 481, 121));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        repassword_lineedit = new QLineEdit(widget);
        repassword_lineedit->setObjectName(QStringLiteral("repassword_lineedit"));
        repassword_lineedit->setFocusPolicy(Qt::ClickFocus);
        repassword_lineedit->setEchoMode(QLineEdit::Password);

        verticalLayout->addWidget(repassword_lineedit);

        securityquestion = new QLineEdit(widget);
        securityquestion->setObjectName(QStringLiteral("securityquestion"));
        securityquestion->setFocusPolicy(Qt::ClickFocus);

        verticalLayout->addWidget(securityquestion);

        answer = new QLineEdit(widget);
        answer->setObjectName(QStringLiteral("answer"));
        answer->setCursor(QCursor(Qt::IBeamCursor));
        answer->setFocusPolicy(Qt::ClickFocus);
        answer->setFrame(true);
        answer->setDragEnabled(false);
        answer->setClearButtonEnabled(false);

        verticalLayout->addWidget(answer);

        layoutWidget->raise();
        Name->raise();
        label_2->raise();
        createaccount->raise();
        username1_lineedit->raise();
        label_3->raise();
        label_4->raise();
        password1_lineedit->raise();
        repassword_lineedit->raise();
        securityquestion->raise();
        answer->raise();

        retranslateUi(New_User);

        QMetaObject::connectSlotsByName(New_User);
    } // setupUi

    void retranslateUi(QDialog *New_User)
    {
        New_User->setWindowTitle(QApplication::translate("New_User", "New User", 0));
        Name->setText(QApplication::translate("New_User", "Name", 0));
        label_2->setText(QApplication::translate("New_User", "Username", 0));
        createaccount->setText(QApplication::translate("New_User", "Create account", 0));
        label_3->setText(QApplication::translate("New_User", "Create Password", 0));
        label_4->setText(QApplication::translate("New_User", "Re-enter Password", 0));
        name_lineedit->setText(QString());
        name_lineedit->setPlaceholderText(QString());
        surname_lineedit->setText(QString());
        securityquestion->setText(QString());
        answer->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class New_User: public Ui_New_User {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEW_USER_H
