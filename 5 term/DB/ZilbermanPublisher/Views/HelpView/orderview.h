#ifndef ORDERVIEW_H
#define ORDERVIEW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QUuid>

#include <Services/databaseservice.h>

#include <Entities/manager.h>
#include <Entities/author.h>
#include <Entities/work.h>
#include <Entities/order.h>

#include <Views/HelpView/batchesview.h>

namespace Ui {
class OrderView;
}

class OrderView : public QMainWindow
{
    Q_OBJECT

public:
    explicit OrderView(QTableWidget *table, DatabaseService *dbService, Manager *manager, QWidget *parent = nullptr);
    ~OrderView();

private slots:
    void on_pushButton_3_clicked();

    void on_add_batch_clicked();

private:
    Ui::OrderView *ui;

    QString uuid;

    DatabaseService *dbService;
    Manager *wrkManager;
    QTableWidget *wrkTable;

    Order *orderModel;
    QList<Batch*> *batches;
};

#endif // ORDERVIEW_H
