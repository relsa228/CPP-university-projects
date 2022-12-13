#ifndef DATABASESERVICE_H
#define DATABASESERVICE_H

#include <QString>
#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlQuery>
#include <QList>

#include "Entities/genre.h"
#include "Entities/manager.h"
#include "Entities/customer.h"
#include "Entities/order.h"
#include "Entities/batch.h"
#include "Entities/author.h"
#include "Entities/work.h"
#include "Entities/printcenter.h"
#include "Entities/worktype.h"

class DatabaseService
{
public:
    DatabaseService();

    Manager* getManager(QString login, QString password);
    QList<Customer*>* getCustomersViaManager(QString login);
    QList<Order*>* getOrders(QString login);
    QList<Author*>* getAuthors();
    QList<Work*>* getWorks();
    QList<PrintCenter*>* getPrintCenters();
    QList<WorkType*>* getWorkTypes();
    QList<Genre*>* getGenres();

    void addAuthor(QString name, QString surname, QString ptr);
    void addCustomer(QString name, QString spec, QString managerID);
    void createOrder(Order* order,  QString managerId);
    void addWork(Work* newWork);

private:
    QSqlDatabase database;
};

#endif // DATABASESERVICE_H
