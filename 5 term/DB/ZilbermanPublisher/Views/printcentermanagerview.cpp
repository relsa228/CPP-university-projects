#include "printcentermanagerview.h"
#include "ui_printcentermanagerview.h"

PrintCenterManagerView::PrintCenterManagerView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PrintCenterManagerView)
{
    ui->setupUi(this);
}

PrintCenterManagerView::~PrintCenterManagerView()
{
    delete ui;
}
