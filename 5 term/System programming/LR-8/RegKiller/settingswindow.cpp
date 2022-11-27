#include "settingswindow.h"
#include "ui_settingswindow.h"

SettingsWindow::SettingsWindow(uint *option, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsWindow)
{
    ui->setupUi(this);

    wrkOption = option;

    switch (*wrkOption) {
    case 0:
        ui->ClassesRootRad->setChecked(true);
        break;
    case 1:
        ui->CurrentUserRad->setChecked(true);
        break;
    case 2:
        ui->LocalMachineRad->setChecked(true);
        break;
    case 3:
        ui->UsersRad->setChecked(true);
        break;
    case 4:
        ui->CurrentConfigRad->setChecked(true);
        break;
    default:
        break;
    }
}

SettingsWindow::~SettingsWindow()
{
    delete ui;
}

void SettingsWindow::on_buttonBox_accepted()
{
    if(ui->ClassesRootRad->isChecked())
        *wrkOption = 0;
    if(ui->CurrentUserRad->isChecked())
        *wrkOption = 1;
    if(ui->LocalMachineRad->isChecked())
        *wrkOption = 2;
    if(ui->UsersRad->isChecked())
        *wrkOption = 3;
    if(ui->CurrentConfigRad->isChecked())
        *wrkOption = 4;

    this->close();
}


void SettingsWindow::on_buttonBox_rejected()
{
    this->close();
}

