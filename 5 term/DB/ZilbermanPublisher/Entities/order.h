#ifndef ORDER_H
#define ORDER_H

#include <QString>
#include <QList>

#include "Entities/batch.h"

class Order
{
public:
    QList<Batch*> *batches;

    Order(QString id, QString customer, int cost, QString open_date, QString dedline, QString close_date, QString order_state);

    const QString &getId() const;

    const QString &getCustomer() const;

    int getCost() const;

    const QString &getOpen_date() const;

    const QString &getDedline() const;

    const QString &getOrder_state() const;

    const QString &getClose_date() const;

private:
    QString id;
    QString customer;
    int cost;
    QString open_date;
    QString dedline;
    QString close_date;
    QString order_state;
};

#endif // ORDER_H
