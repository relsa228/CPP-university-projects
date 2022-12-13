#include "addauthor.h"
#include "ui_addauthor.h"

AddAuthor::AddAuthor(QTableWidget *table, DatabaseService *dbService, Manager *manager, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AddAuthor)
{
    ui->setupUi(this);

    this->dbService = dbService;
    this->wrkManager = manager;
    this->wrkTable = table;
}

AddAuthor::~AddAuthor()
{
    delete ui;
}

void AddAuthor::on_add_author_clicked()
{
    QString name = ui->name_edit->text();
    QString surname = ui->surname_edit->text();
    QString ptr = ui->ptr_edit->text();

    dbService->addAuthor(name, surname, ptr);

    QList<Author*>* authors = dbService->getAuthors();
    wrkTable->setColumnCount(5);
    wrkTable->setRowCount(authors->count());
    wrkTable->setHorizontalHeaderLabels(QStringList() << "ID" << "Имя" << "Фамилия" << "Отчество" << "Кол-во работ");

    for(int row = 0; row < authors->count(); row++)
    {
        QTableWidgetItem *accName = new QTableWidgetItem(tr("%1").arg(authors->at(row)->id));
        wrkTable->setItem(row, 0, accName);
        wrkTable->item(row, 0)->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsSelectable);

        QTableWidgetItem *bank = new QTableWidgetItem(tr("%1").arg(authors->at(row)->name));
        wrkTable->setItem(row, 1, bank);
        wrkTable->item(row, 1)->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsSelectable);

        QTableWidgetItem *num = new QTableWidgetItem(tr("%1").arg(authors->at(row)->surname));
        wrkTable->setItem(row, 2, num);
        wrkTable->item(row, 2)->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsSelectable);

        QTableWidgetItem *money = new QTableWidgetItem(tr("%1").arg(authors->at(row)->patronymic));
        wrkTable->setItem(row, 3, money);
        wrkTable->item(row, 3)->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsSelectable);

        QTableWidgetItem *dedline = new QTableWidgetItem(tr("%1").arg(authors->at(row)->work_count));
        wrkTable->setItem(row, 4, dedline);
        wrkTable->item(row, 4)->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsSelectable);
    }

    this->close();
}

