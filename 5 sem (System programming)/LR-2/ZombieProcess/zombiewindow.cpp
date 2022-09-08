#include "zombiewindow.h"
#include "ui_zombiewindow.h"

ZombieWindow::ZombieWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ZombieWindow)
{
    ui->setupUi(this);
}

ZombieWindow::~ZombieWindow()
{
    delete ui;
}

