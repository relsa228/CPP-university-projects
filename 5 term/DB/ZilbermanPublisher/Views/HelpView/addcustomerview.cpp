#include "addcustomerview.h"
#include "ui_addcustomerview.h"

AddCustomerView::AddCustomerView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AddCustomerView)
{
    ui->setupUi(this);
}

AddCustomerView::~AddCustomerView()
{
    delete ui;
}
