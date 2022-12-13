#ifndef WORK_H
#define WORK_H

#include <QString>
#include <QStringList>
#include <QList>

#include "Entities/author.h"

class Work
{
public:
    Work(QString id, QString name, int edition_number, QString type);

    QString id;
    QString name;
    int edition_number;
    QString type;

    QStringList* genres;
    QList<Author*>* authors;
};

#endif // WORK_H
