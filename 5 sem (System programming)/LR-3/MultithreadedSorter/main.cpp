#include "indexwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    IndexWindow w;
    w.show();
    return a.exec();
}
