#ifndef CLIENTMANGERVIEW_H
#define CLIENTMANGERVIEW_H

#include <QMainWindow>
#include <Services/databaseservice.h>
#include <Entities/manager.h>

namespace Ui {
class ClientMangerView;
}

class ClientMangerView : public QMainWindow
{
    Q_OBJECT

public:
    explicit ClientMangerView(DatabaseService *dbService, Manager *manager, QWidget *parent = nullptr);
    ~ClientMangerView();

private:
    Ui::ClientMangerView *ui;

    DatabaseService *dbService;
    Manager *wrkManager;
};

#endif // CLIENTMANGERVIEW_H
