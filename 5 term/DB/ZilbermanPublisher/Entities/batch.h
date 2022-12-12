#ifndef BATCH_H
#define BATCH_H

#include <QString>

class Batch
{
public:
    Batch(QString id, QString work, int count_of_work, QString print_state);

    QString id;
    QString order;
    QString work;
    QString print_center;
    QString print_state;
    int count_of_work;
};

#endif // BATCH_H
