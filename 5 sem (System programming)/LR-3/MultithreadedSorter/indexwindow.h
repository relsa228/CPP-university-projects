#ifndef INDEXWINDOW_H
#define INDEXWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class IndexWindow; }
QT_END_NAMESPACE

class IndexWindow : public QMainWindow
{
    Q_OBJECT

public:
    IndexWindow(QWidget *parent = nullptr);
    ~IndexWindow();

private:
    Ui::IndexWindow *ui;
};
#endif // INDEXWINDOW_H
