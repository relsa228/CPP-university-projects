#ifndef ZOMBIEWINDOW_H
#define ZOMBIEWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class ZombieWindow; }
QT_END_NAMESPACE

class ZombieWindow : public QMainWindow
{
    Q_OBJECT

public:
    ZombieWindow(QWidget *parent = nullptr);
    ~ZombieWindow();

private:
    Ui::ZombieWindow *ui;
};
#endif // ZOMBIEWINDOW_H
