#ifndef BATCHESVIEW_H
#define BATCHESVIEW_H

#include <QMainWindow>

namespace Ui {
class BatchesView;
}

class BatchesView : public QMainWindow
{
    Q_OBJECT

public:
    explicit BatchesView(QWidget *parent = nullptr);
    ~BatchesView();

private:
    Ui::BatchesView *ui;
};

#endif // BATCHESVIEW_H
