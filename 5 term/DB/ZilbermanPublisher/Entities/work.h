#ifndef WORK_H
#define WORK_H

#include <QString>
#include <QStringList>
#include <QList>

#include "Entities/author.h"
#include "Entities/genre.h"
#include "Entities/worktype.h"

class Work
{
public:
    Work(QString id, QString name, int edition_number, WorkType* type);
    Work();

    QString id;
    QString name;
    int edition_number;
    WorkType* type;

    QList<Genre*>* genres;
    QList<Author*>* authors;
};

#endif // WORK_H
