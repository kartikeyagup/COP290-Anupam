/********************************************************************************
** Form generated from reading UI file 'finalinterface.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINALINTERFACE_H
#define UI_FINALINTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Finalinterface
{
public:
    QProgressBar *progressBar;
    QListView *filelistview;
    QListView *listView_2;
    QLabel *label;
    QLabel *label_2;
    QTreeView *directoryview;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *addfile;
    QPushButton *Deletefile;
    QPushButton *Sync;
    QPushButton *DeleteAccount;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *Finalinterface)
    {
        if (Finalinterface->objectName().isEmpty())
            Finalinterface->setObjectName(QStringLiteral("Finalinterface"));
        Finalinterface->resize(819, 523);
        progressBar = new QProgressBar(Finalinterface);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(430, 420, 171, 23));
        progressBar->setValue(24);
        filelistview = new QListView(Finalinterface);
        filelistview->setObjectName(QStringLiteral("filelistview"));
        filelistview->setGeometry(QRect(280, 80, 256, 301));
        listView_2 = new QListView(Finalinterface);
        listView_2->setObjectName(QStringLiteral("listView_2"));
        listView_2->setGeometry(QRect(550, 80, 256, 301));
        label = new QLabel(Finalinterface);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(180, 40, 101, 17));
        label->setFrameShape(QFrame::NoFrame);
        label->setWordWrap(false);
        label_2 = new QLabel(Finalinterface);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(590, 40, 91, 17));
        label_2->setScaledContents(false);
        label_2->setWordWrap(false);
        directoryview = new QTreeView(Finalinterface);
        directoryview->setObjectName(QStringLiteral("directoryview"));
        directoryview->setGeometry(QRect(10, 80, 256, 301));
        layoutWidget = new QWidget(Finalinterface);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(300, 470, 471, 29));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        addfile = new QPushButton(layoutWidget);
        addfile->setObjectName(QStringLiteral("addfile"));

        horizontalLayout->addWidget(addfile);

        Deletefile = new QPushButton(layoutWidget);
        Deletefile->setObjectName(QStringLiteral("Deletefile"));

        horizontalLayout->addWidget(Deletefile);

        Sync = new QPushButton(layoutWidget);
        Sync->setObjectName(QStringLiteral("Sync"));

        horizontalLayout->addWidget(Sync);

        DeleteAccount = new QPushButton(Finalinterface);
        DeleteAccount->setObjectName(QStringLiteral("DeleteAccount"));
        DeleteAccount->setGeometry(QRect(60, 420, 121, 27));
        layoutWidget1 = new QWidget(Finalinterface);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 470, 264, 29));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(layoutWidget1);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_2->addWidget(pushButton);

        pushButton_2 = new QPushButton(layoutWidget1);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout_2->addWidget(pushButton_2);


        retranslateUi(Finalinterface);

        QMetaObject::connectSlotsByName(Finalinterface);
    } // setupUi

    void retranslateUi(QDialog *Finalinterface)
    {
        Finalinterface->setWindowTitle(QApplication::translate("Finalinterface", "Dialog", 0));
        label->setText(QApplication::translate("Finalinterface", "System Files", 0));
        label_2->setText(QApplication::translate("Finalinterface", "Server Files", 0));
        addfile->setText(QApplication::translate("Finalinterface", "Add file", 0));
        Deletefile->setText(QApplication::translate("Finalinterface", "Delete file", 0));
        Sync->setText(QApplication::translate("Finalinterface", "Sync", 0));
        DeleteAccount->setText(QApplication::translate("Finalinterface", "Delete Account", 0));
        pushButton->setText(QApplication::translate("Finalinterface", "Add Directory", 0));
        pushButton_2->setText(QApplication::translate("Finalinterface", "Remove Directory", 0));
    } // retranslateUi

};

namespace Ui {
    class Finalinterface: public Ui_Finalinterface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINALINTERFACE_H
