#ifndef BATCH_H
#define BATCH_H

#include <QString>

class Batch
{
public:
    Batch(QString orderID, QString work, QString print_center, QString print_state, int count_of_work);
    Batch(QString id, QString orderID, QString work, QString print_center, QString print_state, int count_of_work);

    QString id;
    QString order;
    QString work;
    QString print_center;
    QString print_state;
    int count_of_work;
};

#endif // BATCH_H
