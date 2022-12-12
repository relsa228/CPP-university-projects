#include "batchesview.h"
#include "ui_batchesview.h"

BatchesView::BatchesView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BatchesView)
{
    ui->setupUi(this);
}

BatchesView::~BatchesView()
{
    delete ui;
}
