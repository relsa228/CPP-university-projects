#include "clientmangerview.h"
#include "ui_clientmangerview.h"

ClientMangerView::ClientMangerView(DatabaseService *dbService, Manager *manager, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ClientMangerView)
{
    ui->setupUi(this);

    this->dbService = dbService;
    this->wrkManager = manager;

    ui->name_lable->setText(wrkManager->getSurname() + " " + wrkManager->getName() + " " + wrkManager->getPatronymic());
    ui->id_lable->setText("ID: " + wrkManager->getId());
///////////////////////////////////////////////////////////////////
    QList<Customer*>* customers = dbService->getCustomersViaManager(manager->getId());
    ui->customer_table->setColumnCount(4);
    ui->customer_table->setRowCount(customers->count());
    ui->customer_table->setHorizontalHeaderLabels(QStringList() << "ID" << "Название" << "Специализация" << "Кол-во заказов");

    for(int row = 0; row < customers->count(); row++)
    {
        QTableWidgetItem *accName = new QTableWidgetItem(tr("%1").arg(customers->at(row)->getId()));
        ui->customer_table->setItem(row, 0, accName);
        ui->customer_table->item(row, 0)->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsSelectable);

        QTableWidgetItem *bank = new QTableWidgetItem(tr("%1").arg(customers->at(row)->getName()));
        ui->customer_table->setItem(row, 1, bank);
        ui->customer_table->item(row, 1)->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsSelectable);

        QTableWidgetItem *num = new QTableWidgetItem(tr("%1").arg(customers->at(row)->getSpec()));
        ui->customer_table->setItem(row, 2, num);
        ui->customer_table->item(row, 2)->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsSelectable);

        QTableWidgetItem *money = new QTableWidgetItem(tr("%1").arg(customers->at(row)->getOrder_count()));
        ui->customer_table->setItem(row, 3, money);
        ui->customer_table->item(row, 3)->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsSelectable);
    }
///////////////////////////////////////////////////////////////////////
    QList<Order*>* orders = dbService->getOrders(manager->getId());
    ui->order_table->setColumnCount(7);
    ui->order_table->setRowCount(orders->count());
    ui->order_table->setHorizontalHeaderLabels(QStringList() << "ID" << "Заказчик" << "Стоимость" << "Дата открытия" << "Краний срок" << "Дата закрытия" << "Статус");

    for(int row = 0; row < orders->count(); row++)
    {
        QTableWidgetItem *accName = new QTableWidgetItem(tr("%1").arg(orders->at(row)->getId()));
        ui->order_table->setItem(row, 0, accName);
        ui->order_table->item(row, 0)->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsSelectable);

        QTableWidgetItem *bank = new QTableWidgetItem(tr("%1").arg(orders->at(row)->getCustomer()));
        ui->order_table->setItem(row, 1, bank);
        ui->order_table->item(row, 1)->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsSelectable);

        QTableWidgetItem *num = new QTableWidgetItem(tr("%1").arg(orders->at(row)->getCost()));
        ui->order_table->setItem(row, 2, num);
        ui->order_table->item(row, 2)->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsSelectable);

        QTableWidgetItem *money = new QTableWidgetItem(tr("%1").arg(orders->at(row)->getOpen_date()));
        ui->order_table->setItem(row, 3, money);
        ui->order_table->item(row, 3)->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsSelectable);

        QTableWidgetItem *dedline = new QTableWidgetItem(tr("%1").arg(orders->at(row)->getDedline()));
        ui->order_table->setItem(row, 4, dedline);
        ui->order_table->item(row, 4)->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsSelectable);

        QTableWidgetItem *closeDate = new QTableWidgetItem(tr("%1").arg(orders->at(row)->getClose_date()));
        ui->order_table->setItem(row, 5, closeDate);
        ui->order_table->item(row, 5)->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsSelectable);

        QTableWidgetItem *state = new QTableWidgetItem(tr("%1").arg(orders->at(row)->getOrder_state()));
        ui->order_table->setItem(row, 6, state);
        ui->order_table->item(row, 6)->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsSelectable);
    }
}

ClientMangerView::~ClientMangerView()
{
    delete ui;
}
