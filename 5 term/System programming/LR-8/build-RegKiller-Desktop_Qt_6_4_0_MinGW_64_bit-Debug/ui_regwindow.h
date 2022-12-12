/********************************************************************************
** Form generated from reading UI file 'regwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGWINDOW_H
#define UI_REGWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RegWindow
{
public:
    QWidget *fullGroup;
    QVBoxLayout *verticalLayout_3;
    QTableWidget *outTable;
    QHBoxLayout *controlGroup;
    QHBoxLayout *horizontalLayout;
    QLineEdit *addrEdit;
    QLineEdit *nameEdit;
    QHBoxLayout *buttonsGroup;
    QPushButton *searchButton;
    QPushButton *exportButton;
    QPushButton *settingsButton;

    void setupUi(QMainWindow *RegWindow)
    {
        if (RegWindow->objectName().isEmpty())
            RegWindow->setObjectName("RegWindow");
        RegWindow->resize(800, 600);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/main_icons/Icons/monitor.png"), QSize(), QIcon::Normal, QIcon::Off);
        RegWindow->setWindowIcon(icon);
        fullGroup = new QWidget(RegWindow);
        fullGroup->setObjectName("fullGroup");
        verticalLayout_3 = new QVBoxLayout(fullGroup);
        verticalLayout_3->setObjectName("verticalLayout_3");
        outTable = new QTableWidget(fullGroup);
        outTable->setObjectName("outTable");

        verticalLayout_3->addWidget(outTable);

        controlGroup = new QHBoxLayout();
        controlGroup->setObjectName("controlGroup");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        addrEdit = new QLineEdit(fullGroup);
        addrEdit->setObjectName("addrEdit");

        horizontalLayout->addWidget(addrEdit);

        nameEdit = new QLineEdit(fullGroup);
        nameEdit->setObjectName("nameEdit");

        horizontalLayout->addWidget(nameEdit);


        controlGroup->addLayout(horizontalLayout);

        buttonsGroup = new QHBoxLayout();
        buttonsGroup->setObjectName("buttonsGroup");
        searchButton = new QPushButton(fullGroup);
        searchButton->setObjectName("searchButton");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/functIcons/Icons/SystemIcons/search.svg"), QSize(), QIcon::Normal, QIcon::Off);
        searchButton->setIcon(icon1);

        buttonsGroup->addWidget(searchButton);

        exportButton = new QPushButton(fullGroup);
        exportButton->setObjectName("exportButton");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/functIcons/Icons/SystemIcons/upload.svg"), QSize(), QIcon::Normal, QIcon::Off);
        exportButton->setIcon(icon2);

        buttonsGroup->addWidget(exportButton);

        settingsButton = new QPushButton(fullGroup);
        settingsButton->setObjectName("settingsButton");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/functIcons/Icons/SystemIcons/gear-fill.svg"), QSize(), QIcon::Normal, QIcon::Off);
        settingsButton->setIcon(icon3);

        buttonsGroup->addWidget(settingsButton);


        controlGroup->addLayout(buttonsGroup);


        verticalLayout_3->addLayout(controlGroup);

        RegWindow->setCentralWidget(fullGroup);

        retranslateUi(RegWindow);

        QMetaObject::connectSlotsByName(RegWindow);
    } // setupUi

    void retranslateUi(QMainWindow *RegWindow)
    {
        RegWindow->setWindowTitle(QCoreApplication::translate("RegWindow", "RegKiller", nullptr));
        addrEdit->setPlaceholderText(QCoreApplication::translate("RegWindow", "\320\220\320\264\321\200\320\265\321\201 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\321\217...", nullptr));
        nameEdit->setPlaceholderText(QCoreApplication::translate("RegWindow", "\320\230\320\274\321\217 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\321\217...", nullptr));
        searchButton->setText(QString());
        exportButton->setText(QString());
        settingsButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class RegWindow: public Ui_RegWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGWINDOW_H
