#ifndef ADDCUSTOMERVIEW_H
#define ADDCUSTOMERVIEW_H

#include <QMainWindow>

namespace Ui {
class AddCustomerView;
}

class AddCustomerView : public QMainWindow
{
    Q_OBJECT

public:
    explicit AddCustomerView(QWidget *parent = nullptr);
    ~AddCustomerView();

private:
    Ui::AddCustomerView *ui;
};

#endif // ADDCUSTOMERVIEW_H
