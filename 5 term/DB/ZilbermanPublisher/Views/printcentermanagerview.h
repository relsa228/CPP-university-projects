#ifndef PRINTCENTERMANAGERVIEW_H
#define PRINTCENTERMANAGERVIEW_H

#include <QMainWindow>

namespace Ui {
class PrintCenterManagerView;
}

class PrintCenterManagerView : public QMainWindow
{
    Q_OBJECT

public:
    explicit PrintCenterManagerView(QWidget *parent = nullptr);
    ~PrintCenterManagerView();

private:
    Ui::PrintCenterManagerView *ui;
};

#endif // PRINTCENTERMANAGERVIEW_H
