/********************************************************************************
** Form generated from reading UI file 'settingswindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGSWINDOW_H
#define UI_SETTINGSWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SettingsWindow
{
public:
    QVBoxLayout *verticalLayout;
    QRadioButton *ClassesRootRad;
    QRadioButton *CurrentUserRad;
    QRadioButton *LocalMachineRad;
    QRadioButton *UsersRad;
    QRadioButton *CurrentConfigRad;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *SettingsWindow)
    {
        if (SettingsWindow->objectName().isEmpty())
            SettingsWindow->setObjectName("SettingsWindow");
        SettingsWindow->resize(269, 282);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/main_icons/Icons/monitor.png"), QSize(), QIcon::Normal, QIcon::Off);
        SettingsWindow->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(SettingsWindow);
        verticalLayout->setObjectName("verticalLayout");
        ClassesRootRad = new QRadioButton(SettingsWindow);
        ClassesRootRad->setObjectName("ClassesRootRad");

        verticalLayout->addWidget(ClassesRootRad);

        CurrentUserRad = new QRadioButton(SettingsWindow);
        CurrentUserRad->setObjectName("CurrentUserRad");

        verticalLayout->addWidget(CurrentUserRad);

        LocalMachineRad = new QRadioButton(SettingsWindow);
        LocalMachineRad->setObjectName("LocalMachineRad");

        verticalLayout->addWidget(LocalMachineRad);

        UsersRad = new QRadioButton(SettingsWindow);
        UsersRad->setObjectName("UsersRad");

        verticalLayout->addWidget(UsersRad);

        CurrentConfigRad = new QRadioButton(SettingsWindow);
        CurrentConfigRad->setObjectName("CurrentConfigRad");

        verticalLayout->addWidget(CurrentConfigRad);

        buttonBox = new QDialogButtonBox(SettingsWindow);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(SettingsWindow);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, SettingsWindow, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, SettingsWindow, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(SettingsWindow);
    } // setupUi

    void retranslateUi(QDialog *SettingsWindow)
    {
        SettingsWindow->setWindowTitle(QCoreApplication::translate("SettingsWindow", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \321\200\320\260\320\267\320\264\320\265\320\273", nullptr));
        ClassesRootRad->setText(QCoreApplication::translate("SettingsWindow", "HKEY_CLASSES_ROOT", nullptr));
        CurrentUserRad->setText(QCoreApplication::translate("SettingsWindow", "HKEY_CURRENT_USER", nullptr));
        LocalMachineRad->setText(QCoreApplication::translate("SettingsWindow", "HKEY_LOCAL_MACHINE", nullptr));
        UsersRad->setText(QCoreApplication::translate("SettingsWindow", "HKEY_USERS", nullptr));
        CurrentConfigRad->setText(QCoreApplication::translate("SettingsWindow", "HKEY_CURRENT_CONFIG", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SettingsWindow: public Ui_SettingsWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSWINDOW_H
