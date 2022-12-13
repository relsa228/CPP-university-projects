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
#include "Entities/author.h"
#include "Entities/work.h"

class DatabaseService
{
public:
    DatabaseService();

    Manager* getManager(QString login, QString password);
    QList<Customer*>* getCustomersViaManager(QString login);
    QList<Order*>* getOrders(QString login);
    QList<Author*>* getAuthors();
    QList<Work*>* getWorks();

    void addAuthor(QString name, QString surname, QString ptr);
    void addCustomer(QString name, QString spec, QString managerID);
    void createOrder(Order* order,  QString managerId);

private:
    QSqlDatabase database;
};

#endif // DATABASESERVICE_H
