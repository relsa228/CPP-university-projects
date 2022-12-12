#ifndef ORDERVIEW_H
#define ORDERVIEW_H

#include <QMainWindow>

namespace Ui {
class OrderView;
}

class OrderView : public QMainWindow
{
    Q_OBJECT

public:
    explicit OrderView(QWidget *parent = nullptr);
    ~OrderView();

private:
    Ui::OrderView *ui;
};

#endif // ORDERVIEW_H
