#ifndef ADMINVIEW_H
#define ADMINVIEW_H

#include <QMainWindow>

namespace Ui {
class AdminView;
}

class AdminView : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminView(QWidget *parent = nullptr);
    ~AdminView();

private:
    Ui::AdminView *ui;
};

#endif // ADMINVIEW_H
