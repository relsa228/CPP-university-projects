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

    works = new QList<Work*>;
    works = dbService->getWorks();

    QStringList* custList = new QStringList();
    for(Work* work: *works)
        custList->push_back(work->id + ": " + work->name);

    ui->work_box->addItems(*custList);
}

BatchesView::~BatchesView()
{
    delete ui;
}

void BatchesView::on_pushButton_clicked()
{
    QString work = ui->work_box->currentText();
    Work* currentWork = new Work("", "", 0, "");
    for(Work* wrk: *works)
        if (wrk->id + ": " + wrk->name == work)
            currentWork = wrk;

    Batch* batch = new Batch(uuid, currentWork->id, ui->count_spin->text().toInt(), "in_plane");
}

