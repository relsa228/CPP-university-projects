#include "batchesview.h"
#include "ui_batchesview.h"

BatchesView::BatchesView(QTableWidget *table, DatabaseService *dbService, QList<Batch*>* batches, QString uuid, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BatchesView)
{
    ui->setupUi(this);
    this->dbService = dbService;
    this->uuid = uuid;
    this->batches = batches;
    this->wrkTable = table;

    works = new QList<Work*>();
    works = dbService->getWorks();

    printcenters = new QList<PrintCenter*>();
    printcenters = dbService->getPrintCenters();

    QStringList* custList = new QStringList();
    for(Work* work: *works)
        custList->push_back(work->id + ": " + work->name);

    ui->work_box->addItems(*custList);

    QStringList* printList = new QStringList();
    for(PrintCenter* printcenter: *printcenters)
        printList->push_back(printcenter->getAdress());

    ui->print_box->addItems(*printList);
}

BatchesView::~BatchesView()
{
    delete ui;
}

void BatchesView::on_add_batch_clicked()
{
    QString work = ui->work_box->currentText();
    Work* currentWork = new Work();
    for(Work* wrk: *works)
        if (wrk->id + ": " + wrk->name == work)
            currentWork = wrk;

    QString print = ui->print_box->currentText();
    PrintCenter* currentPrint = new PrintCenter();
    for(PrintCenter* printCent: *printcenters)
        if (printCent->getAdress() == print)
            currentPrint = printCent;

    batches->push_back(new Batch(uuid, currentWork->id, ui->count_spin->text().toInt(), "in_plane", currentPrint->getId()));

    wrkTable->setColumnCount(3);
    wrkTable->setRowCount(batches->count());
    wrkTable->setHorizontalHeaderLabels(QStringList() << "Работа" << "Кол-во копий" << "Печатный центр");

    for(int row = 0; row < batches->count(); row++)
    {
        QString work = batches->at(row)->work;
        QString currentWork = "";
        for(Work* wrk: *works)
            if (wrk->id == work)
                currentWork = wrk->name;

        QString print = batches->at(row)->print_center;
        QString currentPrint = "";
        for(PrintCenter* printCent: *printcenters)
            if (printCent->getId() == print)
                currentPrint = printCent->getAdress();

        QTableWidgetItem *accName = new QTableWidgetItem(tr("%1").arg(currentWork));
        wrkTable->setItem(row, 0, accName);
        wrkTable->item(row, 0)->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsSelectable);

        QTableWidgetItem *bank = new QTableWidgetItem(tr("%1").arg(batches->at(row)->count_of_work));
        wrkTable->setItem(row, 1, bank);
        wrkTable->item(row, 1)->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsSelectable);

        QTableWidgetItem *num = new QTableWidgetItem(tr("%1").arg(currentPrint));
        wrkTable->setItem(row, 2, num);
        wrkTable->item(row, 2)->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsSelectable);
    }

    this->close();
}

