#ifndef REGWINDOW_H
#define REGWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class RegWindow; }
QT_END_NAMESPACE

class RegWindow : public QMainWindow
{
    Q_OBJECT

public:
    RegWindow(QWidget *parent = nullptr);
    ~RegWindow();

private:
    Ui::RegWindow *ui;
};
#endif // REGWINDOW_H
