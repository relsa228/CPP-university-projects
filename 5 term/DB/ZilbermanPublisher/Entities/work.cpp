#include "work.h"

Work::Work(QString id, QString name, int edition_number, QString type)
{
    this->id = id;
    this->name = name;
    this->edition_number = edition_number;
    this->type = type;

    this->genres = new QStringList();
    this->authors = new QList<Author*>();
}
