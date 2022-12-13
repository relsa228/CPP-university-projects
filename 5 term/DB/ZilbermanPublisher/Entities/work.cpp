#include "work.h"

Work::Work(QString id, QString name, int edition_number, WorkType* type)
{
    this->id = id;
    this->name = name;
    this->edition_number = edition_number;
    this->type = type;

    this->genres = new QList<Genre*>();
    this->authors = new QList<Author*>();
}

Work::Work()
{
    this->genres = new QList<Genre*>();
    this->authors = new QList<Author*>();
}
