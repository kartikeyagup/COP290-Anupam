/********************************************************************************
** Form generated from reading UI file 'filewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILEWINDOW_H
#define UI_FILEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListView>
#include <QtWidgets/QTreeView>

QT_BEGIN_NAMESPACE

class Ui_FileWindow
{
public:
    QListView *listView;
    QTreeView *directoryview;
    QTreeView *filelistview;

    void setupUi(QDialog *FileWindow)
    {
        if (FileWindow->objectName().isEmpty())
            FileWindow->setObjectName(QStringLiteral("FileWindow"));
        FileWindow->resize(986, 503);
        listView = new QListView(FileWindow);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setGeometry(QRect(550, 20, 256, 192));
        directoryview = new QTreeView(FileWindow);
        directoryview->setObjectName(QStringLiteral("directoryview"));
        directoryview->setGeometry(QRect(30, 20, 256, 371));
        filelistview = new QTreeView(FileWindow);
        filelistview->setObjectName(QStringLiteral("filelistview"));
        filelistview->setGeometry(QRect(290, 20, 256, 361));

        retranslateUi(FileWindow);

        QMetaObject::connectSlotsByName(FileWindow);
    } // setupUi

    void retranslateUi(QDialog *FileWindow)
    {
        FileWindow->setWindowTitle(QApplication::translate("FileWindow", "FileWindow", 0));
    } // retranslateUi

};

namespace Ui {
    class FileWindow: public Ui_FileWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILEWINDOW_H
