#ifndef DATABASESERVICE_H
#define DATABASESERVICE_H

#include <QString>
#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlQuery>
#include <QList>

#include "Entities/manager.h"
#include "Entities/customer.h"
#include "Entities/order.h"
#include "Entities/batch.h"

class DatabaseService
{
public:
    DatabaseService();

    Manager* getManager(QString login, QString password);
    QList<Customer*>* getCustomersViaManager(QString login);
    QList<Order*>* getOrders(QString login);

private:
    QSqlDatabase database;
};

#endif // DATABASESERVICE_H
