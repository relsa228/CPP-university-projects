#include "order.h"

Order::Order(QString id, QString customer, int cost, QString open_date, QString dedline, QString close_date, QString order_state)
{
    this->id = id;
    this->customer = customer;
    this->cost = cost;
    this->open_date = open_date;
    this->dedline = dedline;
    this->close_date = close_date;
    this->order_state = order_state;

    this->batches = new QList<Batch*>;
}

const QString &Order::getId() const
{
    return id;
}

const QString &Order::getCustomer() const
{
    return customer;
}

int Order::getCost() const
{
    return cost;
}

const QString &Order::getOpen_date() const
{
    return open_date;
}

const QString &Order::getDedline() const
{
    return dedline;
}

const QString &Order::getOrder_state() const
{
    return order_state;
}

const QString &Order::getClose_date() const
{
    return close_date;
}
