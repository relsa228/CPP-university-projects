#ifndef CLIENTMANGERVIEW_H
#define CLIENTMANGERVIEW_H

#include <QMainWindow>
#include <Services/databaseservice.h>

#include <Entities/manager.h>
#include <Entities/author.h>
#include <Entities/work.h>

#include <Views/HelpView/addauthor.h>
#include <Views/HelpView/addcustomerview.h>
#include <Views/HelpView/orderview.h>

namespace Ui {
class ClientMangerView;
}

class ClientMangerView : public QMainWindow
{
    Q_OBJECT

public:
    explicit ClientMangerView(DatabaseService *dbService, Manager *manager, QWidget *parent = nullptr);
    ~ClientMangerView();

private slots:
    void on_add_author_clicked();

    void on_add_customer_clicked();

    void on_add_order_clicked();

private:
    Ui::ClientMangerView *ui;
    void updateAuthorTab();
    void updateOrderTab();
    void updateWorkTab();
    void updateCustomerTab();

    DatabaseService *dbService;
    Manager *wrkManager;
};

#endif // CLIENTMANGERVIEW_H
