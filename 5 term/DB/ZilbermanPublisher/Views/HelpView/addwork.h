#ifndef ADDWORK_H
#define ADDWORK_H

#include "Services/databaseservice.h"
#include "qtablewidget.h"
#include <QMainWindow>

#include "Entities/genre.h"
#include "Entities/worktype.h"

namespace Ui {
class AddWork;
}

class AddWork : public QMainWindow
{
    Q_OBJECT

public:
    explicit AddWork(QTableWidget *table, DatabaseService *dbService, QWidget *parent = nullptr);
    ~AddWork();

private slots:
    void on_add_author_clicked();

    void on_add_genre_clicked();

    void on_del_author_clicked();

    void on_del_genre_clicked();

    void on_add_work_clicked();

private:
    Ui::AddWork *ui;

    DatabaseService *dbService;
    QTableWidget *wrkTable;

    QList<Author*> *authors;
    QList<Genre*> *genres;
    QList<WorkType*> *workTypes;

    Work* newWork;
};

#endif // ADDWORK_H
