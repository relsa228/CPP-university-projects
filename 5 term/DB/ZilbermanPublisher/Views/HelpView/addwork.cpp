#include "addwork.h"
#include "ui_addwork.h"

AddWork::AddWork(QTableWidget *table, DatabaseService *dbService, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AddWork)
{
    ui->setupUi(this);
    this->dbService = dbService;
    this->wrkTable = table;
    this->authors = dbService->getAuthors();
    this->genres = dbService->getGenres();
    this->workTypes = dbService->getWorkTypes();

    newWork = new Work();
    newWork->id = QUuid::createUuid().toString();

    QStringList* authorsList = new QStringList();
    QStringList* typesList = new QStringList();
    QStringList* genresList = new QStringList();

    for(Author* author: *authors)
        authorsList->push_back(author->id + ": " + author->surname + " " + author->name + " " + author->patronymic);

    for(WorkType* workType: *workTypes)
        typesList->push_back(workType->getType());

    for(Genre* genre: *genres)
        genresList->push_back(genre->getGenre());

    ui->genre_box->addItems(*genresList);
    ui->type_box->addItems(*typesList);
    ui->author_box->addItems(*authorsList);

    ui->author_tab->setColumnCount(2);
    ui->author_tab->setHorizontalHeaderLabels(QStringList() << "ID" << "ФИО автора");

    ui->genre_tab->setColumnCount(1);
    ui->genre_tab->setHorizontalHeaderLabels(QStringList() << "Жанр");
}

AddWork::~AddWork()
{
    delete ui;
}

void AddWork::on_add_author_clicked()
{
    QString authorStr = ui->author_box->currentText();
    for(Author* author: *authors) {
        if(author->id + ": " + author->surname + " " + author->name + " " + author->patronymic == authorStr) {
            if (newWork->authors->contains(author))
                return;
            newWork->authors->push_back(author);
        }
    }

    ui->author_tab->setRowCount(ui->author_tab->rowCount() + 1);

    QTableWidgetItem *accName = new QTableWidgetItem(tr("%1").arg(newWork->authors->last()->id));
    ui->author_tab->setItem(ui->author_tab->rowCount() - 1, 0, accName);
    ui->author_tab->item(ui->author_tab->rowCount() - 1, 0)->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsSelectable);

    QTableWidgetItem *bank = new QTableWidgetItem(tr("%1").arg(newWork->authors->last()->surname + " " +
                                                               newWork->authors->last()->name + " " + newWork->authors->last()->patronymic));
    ui->author_tab->setItem(ui->author_tab->rowCount() - 1, 1, bank);
    ui->author_tab->item(ui->author_tab->rowCount() - 1, 1)->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsSelectable);
}


void AddWork::on_add_genre_clicked()
{
    QString generStr = ui->genre_box->currentText();
    for(Genre* genre: *genres) {
        if(genre->getGenre() == generStr) {
            if (newWork->genres->contains(genre))
                return;
            newWork->genres->push_back(genre);
        }
    }

    ui->genre_tab->setRowCount(ui->genre_tab->rowCount() + 1);

    QTableWidgetItem *accName = new QTableWidgetItem(tr("%1").arg(newWork->genres->last()->getGenre()));
    ui->genre_tab->setItem(ui->genre_tab->rowCount() - 1, 0, accName);
    ui->genre_tab->item(ui->genre_tab->rowCount() - 1, 0)->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsSelectable);
}


void AddWork::on_del_author_clicked()
{
    int num = ui->auth_del_num->value();
    if (num - 1 < newWork->authors->count()) {
        newWork->authors->removeAt(num - 1);
        ui->author_tab->removeRow(num - 1);
    }
}


void AddWork::on_del_genre_clicked()
{
    int num = ui->gen_del_num->value();
    if (num - 1 < newWork->genres->count()) {
        newWork->genres->removeAt(num - 1);
        ui->genre_tab->removeRow(num - 1);
    }
}


void AddWork::on_add_work_clicked()
{
    for(WorkType* workType: *workTypes)
        if (workType->getType() == ui->type_box->currentText())
                newWork->type = workType;

    newWork->name = ui->name_edit->text();
    newWork->edition_number = ui->edit_num->value();

    dbService->addWork(newWork);

    //внесение в таблицу
}

