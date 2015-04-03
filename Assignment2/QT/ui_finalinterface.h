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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Finalinterface
{
public:
    QWidget *centralWidget;
    QPushButton *mkdir;
    QPushButton *removedir;
    QTreeView *directoryview;
    QPushButton *addfile;
    QPushButton *deletefile;
    QPushButton *openfile;
    QPushButton *Share;
    QPushButton *Rename;
    QPushButton *RenameDir;
    QPushButton *syncall;
    QPushButton *syncselected;
    QPushButton *Logout;
    QProgressBar *progressBar;
    QTreeView *filesystemview;
    QListWidget *serverlist;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QDialog *Finalinterface)
    {
        if (Finalinterface->objectName().isEmpty())
            Finalinterface->setObjectName(QStringLiteral("Finalinterface"));
        Finalinterface->resize(1049, 536);
        centralWidget = new QWidget(Finalinterface);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setGeometry(QRect(-10, -10, 906, 461));
        mkdir = new QPushButton(centralWidget);
        mkdir->setObjectName(QStringLiteral("mkdir"));
        mkdir->setGeometry(QRect(40, 70, 99, 27));
        removedir = new QPushButton(centralWidget);
        removedir->setObjectName(QStringLiteral("removedir"));
        removedir->setGeometry(QRect(40, 110, 99, 27));
        directoryview = new QTreeView(centralWidget);
        directoryview->setObjectName(QStringLiteral("directoryview"));
        directoryview->setGeometry(QRect(50, 190, 271, 241));
        addfile = new QPushButton(centralWidget);
        addfile->setObjectName(QStringLiteral("addfile"));
        addfile->setGeometry(QRect(170, 30, 99, 27));
        deletefile = new QPushButton(centralWidget);
        deletefile->setObjectName(QStringLiteral("deletefile"));
        deletefile->setGeometry(QRect(170, 70, 99, 27));
        openfile = new QPushButton(centralWidget);
        openfile->setObjectName(QStringLiteral("openfile"));
        openfile->setGeometry(QRect(40, 30, 99, 27));
        Share = new QPushButton(centralWidget);
        Share->setObjectName(QStringLiteral("Share"));
        Share->setGeometry(QRect(170, 110, 99, 27));
        Rename = new QPushButton(centralWidget);
        Rename->setObjectName(QStringLiteral("Rename"));
        Rename->setGeometry(QRect(330, 30, 99, 27));
        RenameDir = new QPushButton(centralWidget);
        RenameDir->setObjectName(QStringLiteral("RenameDir"));
        RenameDir->setGeometry(QRect(330, 70, 99, 27));
        syncall = new QPushButton(centralWidget);
        syncall->setObjectName(QStringLiteral("syncall"));
        syncall->setGeometry(QRect(510, 30, 99, 27));
        syncselected = new QPushButton(centralWidget);
        syncselected->setObjectName(QStringLiteral("syncselected"));
        syncselected->setGeometry(QRect(510, 70, 99, 27));
        Logout = new QPushButton(centralWidget);
        Logout->setObjectName(QStringLiteral("Logout"));
        Logout->setGeometry(QRect(340, 110, 99, 27));
        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(500, 120, 118, 23));
        progressBar->setValue(24);
        filesystemview = new QTreeView(centralWidget);
        filesystemview->setObjectName(QStringLiteral("filesystemview"));
        filesystemview->setGeometry(QRect(330, 190, 256, 241));
        serverlist = new QListWidget(centralWidget);
        serverlist->setObjectName(QStringLiteral("serverlist"));
        serverlist->setGeometry(QRect(610, 190, 256, 192));
        menuBar = new QMenuBar(Finalinterface);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1049, 25));
        mainToolBar = new QToolBar(Finalinterface);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setGeometry(QRect(0, 0, 4, 13));
        statusBar = new QStatusBar(Finalinterface);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        statusBar->setGeometry(QRect(0, 0, 3, 22));

        retranslateUi(Finalinterface);

        QMetaObject::connectSlotsByName(Finalinterface);
    } // setupUi

    void retranslateUi(QDialog *Finalinterface)
    {
        Finalinterface->setWindowTitle(QApplication::translate("Finalinterface", "MainWindow", 0));
        mkdir->setText(QApplication::translate("Finalinterface", "mkdir", 0));
        removedir->setText(QApplication::translate("Finalinterface", "rmvdir", 0));
        addfile->setText(QApplication::translate("Finalinterface", "Add file", 0));
        deletefile->setText(QApplication::translate("Finalinterface", "Delete file", 0));
        openfile->setText(QApplication::translate("Finalinterface", "Open file", 0));
        Share->setText(QApplication::translate("Finalinterface", "Share", 0));
        Rename->setText(QApplication::translate("Finalinterface", "Rename file", 0));
        RenameDir->setText(QApplication::translate("Finalinterface", "Rename Dir", 0));
        syncall->setText(QApplication::translate("Finalinterface", "Sync All", 0));
        syncselected->setText(QApplication::translate("Finalinterface", "Sync selected", 0));
        Logout->setText(QApplication::translate("Finalinterface", "Logout", 0));
    } // retranslateUi

};

namespace Ui {
    class Finalinterface: public Ui_Finalinterface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINALINTERFACE_H
