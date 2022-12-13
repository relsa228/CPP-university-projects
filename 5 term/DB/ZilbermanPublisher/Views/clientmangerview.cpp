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
    updateCustomerTab();
    updateOrderTab();
    updateAuthorTab();
    updateWorkTab();
}

ClientMangerView::~ClientMangerView()
{
    delete ui;
}

void ClientMangerView::on_add_author_clicked()
{
    AddAuthor* addAuthorView = new AddAuthor(ui->author_table, dbService, wrkManager);
    addAuthorView->show();
}

void ClientMangerView::on_add_customer_clicked()
{
    AddCustomerView* addCustomerView = new AddCustomerView(ui->customer_table, dbService, wrkManager);
    addCustomerView->show();
}

void ClientMangerView::on_add_order_clicked()
{
    OrderView* orderView = new OrderView(ui->order_table, dbService, wrkManager);
    orderView->show();
}

void ClientMangerView::updateAuthorTab()
{
    QList<Author*>* authors = dbService->getAuthors();
    ui->author_table->setColumnCount(5);
    ui->author_table->setRowCount(authors->count());
    ui->author_table->setHorizontalHeaderLabels(QStringList() << "ID" << "Имя" << "Фамилия" << "Отчество" << "Кол-во работ");

    for(int row = 0; row < authors->count(); row++)
    {
        QTableWidgetItem *accName = new QTableWidgetItem(tr("%1").arg(authors->at(row)->id));
        ui->author_table->setItem(row, 0, accName);
        ui->author_table->item(row, 0)->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsSelectable);

        QTableWidgetItem *bank = new QTableWidgetItem(tr("%1").arg(authors->at(row)->name));
        ui->author_table->setItem(row, 1, bank);
        ui->author_table->item(row, 1)->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsSelectable);

        QTableWidgetItem *num = new QTableWidgetItem(tr("%1").arg(authors->at(row)->surname));
        ui->author_table->setItem(row, 2, num);
        ui->author_table->item(row, 2)->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsSelectable);

        QTableWidgetItem *money = new QTableWidgetItem(tr("%1").arg(authors->at(row)->patronymic));
        ui->author_table->setItem(row, 3, money);
        ui->author_table->item(row, 3)->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsSelectable);

        QTableWidgetItem *dedline = new QTableWidgetItem(tr("%1").arg(authors->at(row)->work_count));
        ui->author_table->setItem(row, 4, dedline);
        ui->author_table->item(row, 4)->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsSelectable);
    }
}

void ClientMangerView::updateOrderTab()
{
    QList<Order*>* orders = dbService->getOrders(wrkManager->getId());
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

void ClientMangerView::updateWorkTab()
{
    QList<Work*>* works = dbService->getWorks();
    ui->work_table->setColumnCount(5);
    ui->work_table->setRowCount(works->count());
    ui->work_table->setHorizontalHeaderLabels(QStringList() << "ID" << "Название" << "Издание" << "Тип" << "Жанры");

    for(int row = 0; row < works->count(); row++)
    {
        QString genres = "";
        for(Genre *genre: *works->at(row)->genres)
            genres += genre->getGenre() + ", ";

        genres.chop(2);

        QTableWidgetItem *accName = new QTableWidgetItem(tr("%1").arg(works->at(row)->id));
        ui->work_table->setItem(row, 0, accName);
        ui->work_table->item(row, 0)->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsSelectable);

        QTableWidgetItem *bank = new QTableWidgetItem(tr("%1").arg(works->at(row)->name));
        ui->work_table->setItem(row, 1, bank);
        ui->work_table->item(row, 1)->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsSelectable);

        QTableWidgetItem *num = new QTableWidgetItem(tr("%1").arg(works->at(row)->edition_number));
        ui->work_table->setItem(row, 2, num);
        ui->work_table->item(row, 2)->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsSelectable);

        QTableWidgetItem *money = new QTableWidgetItem(tr("%1").arg(works->at(row)->type->getType()));
        ui->work_table->setItem(row, 3, money);
        ui->work_table->item(row, 3)->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsSelectable);

        QTableWidgetItem *dedline = new QTableWidgetItem(tr("%1").arg(genres));
        ui->work_table->setItem(row, 4, dedline);
        ui->work_table->item(row, 4)->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsSelectable);
    }
}

void ClientMangerView::updateCustomerTab()
{
    QList<Customer*>* customers = dbService->getCustomersViaManager(wrkManager->getId());
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
}


void ClientMangerView::on_add_work_clicked()
{
    AddWork *addWork = new AddWork(ui->work_table, dbService);
    addWork->show();
}

