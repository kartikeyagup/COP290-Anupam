/********************************************************************************
** Form generated from reading UI file 'question.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUESTION_H
#define UI_QUESTION_H

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

class Ui_question
{
public:
    QLabel *label_securityques;
    QLineEdit *answerask;
    QPushButton *pushButton;

    void setupUi(QDialog *question)
    {
        if (question->objectName().isEmpty())
            question->setObjectName(QStringLiteral("question"));
        question->resize(609, 435);
        label_securityques = new QLabel(question);
        label_securityques->setObjectName(QStringLiteral("label_securityques"));
        label_securityques->setGeometry(QRect(80, 150, 431, 31));
        answerask = new QLineEdit(question);
        answerask->setObjectName(QStringLiteral("answerask"));
        answerask->setGeometry(QRect(80, 200, 441, 27));
        answerask->setFocusPolicy(Qt::StrongFocus);
        pushButton = new QPushButton(question);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(298, 320, 151, 27));

        retranslateUi(question);

        QMetaObject::connectSlotsByName(question);
    } // setupUi

    void retranslateUi(QDialog *question)
    {
        question->setWindowTitle(QApplication::translate("question", "Dialog", 0));
        label_securityques->setText(QString());
        answerask->setText(QString());
        answerask->setPlaceholderText(QString());
        pushButton->setText(QApplication::translate("question", "Change Password", 0));
    } // retranslateUi

};

namespace Ui {
    class question: public Ui_question {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUESTION_H
