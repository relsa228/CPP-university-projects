#include "orderview.h"
#include "ui_orderview.h"

OrderView::OrderView(QTableWidget *table, DatabaseService *dbService, Manager *manager, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::OrderView)
{
    ui->setupUi(this);

    this->dbService = dbService;
    this->wrkManager = manager;
    this->wrkTable = table;

    QList<Customer*>* customers = dbService->getCustomersViaManager(manager->getId());

    QStringList* custList = new QStringList();
    for(Customer* customer: *customers)
        custList->push_back(customer->getName());

    ui->customer_box->addItems(*custList);

    uuid = QUuid::createUuid().toString();
    uuid.remove("}");
    uuid.remove("{");
}

OrderView::~OrderView()
{
    delete ui;
}

void OrderView::on_pushButton_3_clicked()
{
    QString customerName = ui->customer_box->currentText();
    QString customerID = "";
    QList<Customer*>* customers = dbService->getCustomersViaManager(wrkManager->getId());
    for(Customer* customer: *customers)
        if(customer->getName() == customerName)
            customerID = customer->getId();

    orderModel = new Order(uuid, customerID, ui->price_edit->value(), "", ui->dedline_edit->text().replace(".", "-"), "", "");
    orderModel->batches = batches;
    dbService->createOrder(orderModel, wrkManager->getId());

    QList<Order*>* orders = dbService->getOrders(wrkManager->getId());
    wrkTable->setColumnCount(7);
    wrkTable->setRowCount(orders->count());
    wrkTable->setHorizontalHeaderLabels(QStringList() << "ID" << "Заказчик" << "Стоимость" << "Дата открытия" << "Краний срок" << "Дата закрытия" << "Статус");

    for(int row = 0; row < orders->count(); row++)
    {
        QTableWidgetItem *accName = new QTableWidgetItem(tr("%1").arg(orders->at(row)->getId()));
        wrkTable->setItem(row, 0, accName);
        wrkTable->item(row, 0)->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsSelectable);

        QTableWidgetItem *bank = new QTableWidgetItem(tr("%1").arg(orders->at(row)->getCustomer()));
        wrkTable->setItem(row, 1, bank);
        wrkTable->item(row, 1)->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsSelectable);

        QTableWidgetItem *num = new QTableWidgetItem(tr("%1").arg(orders->at(row)->getCost()));
        wrkTable->setItem(row, 2, num);
        wrkTable->item(row, 2)->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsSelectable);

        QTableWidgetItem *money = new QTableWidgetItem(tr("%1").arg(orders->at(row)->getOpen_date()));
        wrkTable->setItem(row, 3, money);
        wrkTable->item(row, 3)->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsSelectable);

        QTableWidgetItem *dedline = new QTableWidgetItem(tr("%1").arg(orders->at(row)->getDedline()));
        wrkTable->setItem(row, 4, dedline);
        wrkTable->item(row, 4)->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsSelectable);

        QTableWidgetItem *closeDate = new QTableWidgetItem(tr("%1").arg(orders->at(row)->getClose_date()));
        wrkTable->setItem(row, 5, closeDate);
        wrkTable->item(row, 5)->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsSelectable);

        QTableWidgetItem *state = new QTableWidgetItem(tr("%1").arg(orders->at(row)->getOrder_state()));
        wrkTable->setItem(row, 6, state);
        wrkTable->item(row, 6)->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsSelectable);
    }

    this->close();
}


void OrderView::on_add_batch_clicked()
{
    BatchesView* batchesView = new BatchesView(ui->batches_table, dbServices, batches, uuid);
    batchesView->show();
}

