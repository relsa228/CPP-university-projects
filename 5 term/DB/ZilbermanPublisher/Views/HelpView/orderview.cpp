#include "orderview.h"
#include "ui_orderview.h"

OrderView::OrderView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::OrderView)
{
    ui->setupUi(this);
}

OrderView::~OrderView()
{
    delete ui;
}
