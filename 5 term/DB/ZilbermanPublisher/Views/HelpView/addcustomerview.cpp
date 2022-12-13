#include "addcustomerview.h"
#include "ui_addcustomerview.h"

AddCustomerView::AddCustomerView(QTableWidget *table, DatabaseService *dbService, Manager *manager, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AddCustomerView)
{
    ui->setupUi(this);

    this->dbService = dbService;
    this->wrkManager = manager;
    this->wrkTable = table;
}

AddCustomerView::~AddCustomerView()
{
    delete ui;
}

void AddCustomerView::on_pushButton_clicked()
{
    QString name = ui->name_edit->text();
    QString spec = ui->spec_edit->text();

    dbService->addCustomer(name, spec, wrkManager->getId());

    QList<Customer*>* customers = dbService->getCustomersViaManager(wrkManager->getId());
    wrkTable->setColumnCount(4);
    wrkTable->setRowCount(customers->count());
    wrkTable->setHorizontalHeaderLabels(QStringList() << "ID" << "Название" << "Специализация" << "Кол-во заказов");

    for(int row = 0; row < customers->count(); row++)
    {
        QTableWidgetItem *accName = new QTableWidgetItem(tr("%1").arg(customers->at(row)->getId()));
        wrkTable->setItem(row, 0, accName);
        wrkTable->item(row, 0)->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsSelectable);

        QTableWidgetItem *bank = new QTableWidgetItem(tr("%1").arg(customers->at(row)->getName()));
        wrkTable->setItem(row, 1, bank);
        wrkTable->item(row, 1)->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsSelectable);

        QTableWidgetItem *num = new QTableWidgetItem(tr("%1").arg(customers->at(row)->getSpec()));
        wrkTable->setItem(row, 2, num);
        wrkTable->item(row, 2)->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsSelectable);

        QTableWidgetItem *money = new QTableWidgetItem(tr("%1").arg(customers->at(row)->getOrder_count()));
        wrkTable->setItem(row, 3, money);
        wrkTable->item(row, 3)->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsSelectable);
    }

    this->close();
}

