#include "regwindow.h"
#include "ui_regwindow.h"

RegWindow::RegWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::RegWindow)
{
    ui->setupUi(this);

    regWorkerService = new RegWorkerService();
    option = HKEY_CLASSES_ROOT;
}

RegWindow::~RegWindow()
{
    delete ui;
}

void RegWindow::on_searchButton_clicked()
{
    ui->outputArea->clear();

    QString address = ui->addrEdit->text();
    QString name = ui->nameEdit->text();

    QString bufAddress = QString("%1").arg(address);
    std::wstring inptAddress = bufAddress.toStdWString();

    QString bufName = QString("%1").arg(name);
    std::wstring inptName = bufName.toStdWString();

    if (!name.isEmpty()) {
        RegUnit regUnit = regWorkerService->extractUnit(inptAddress.c_str(), inptName.c_str(), REG_SZ, option);
        ui->outputArea->setText(regUnit.getUnitName() + " - " + regUnit.getUnitValue());
        return;
    }

    QVector<RegUnit> *regUnits = regWorkerService->extractUnits(inptAddress.c_str(), REG_SZ, option);
    for(auto unit: *regUnits)
        ui->outputArea->setText(ui->outputArea->toPlainText() + unit.getUnitName() + " - " + unit.getUnitValue() + "\n");

}


void RegWindow::on_pushButton_clicked()
{
    SettingsWindow *settingsWindow = new SettingsWindow(&option);
    settingsWindow->show();
}

