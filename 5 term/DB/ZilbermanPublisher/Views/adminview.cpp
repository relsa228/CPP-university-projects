#include "adminview.h"
#include "ui_adminview.h"

AdminView::AdminView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdminView)
{
    ui->setupUi(this);
}

AdminView::~AdminView()
{
    delete ui;
}
