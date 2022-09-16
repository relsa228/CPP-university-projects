#include "indexwindow.h"
#include "ui_indexwindow.h"

IndexWindow::IndexWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::IndexWindow)
{
    ui->setupUi(this);
}

IndexWindow::~IndexWindow()
{
    delete ui;
}

