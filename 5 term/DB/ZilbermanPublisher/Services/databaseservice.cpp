#include "databaseservice.h"

DatabaseService::DatabaseService()
{
    database = QSqlDatabase::addDatabase("QPSQL");
    database.setDatabaseName("publisher_controller_base");
    database.setUserName("postgres");
    database.setPassword("root");
    if(!database.open())
        QMessageBox::critical(0, "Соединение не установлено", database.lastError().text());
    logger = new LoggerService(database);
}

Manager *DatabaseService::getManager(QString login, QString password)
{
    QString getUser = "SELECT managers.\"id\", managers.\"name\", managers.\"surname\", managers.\"patronymic\", managers.\"username\", "
                      "positions.\"position\", managers.\"is_active\" FROM managers RIGHT JOIN positions ON positions.\"id\" = managers."
                      "\"position\" WHERE \"password\" = crypt('" + password + "', \"password\") AND \"username\" = '" + login + "'";
    QSqlQuery* query = new QSqlQuery(database);
    query->exec(getUser);
    if(query->next()) {
        return new Manager(query->value(0).toString(), query->value(1).toString(), query->value(2).toString(), query->value(3).toString(),
                           query->value(4).toString(), query->value(5).toString(), query->value(6).toBool());
    }
    else {
        QMessageBox::critical(0, "Ошибка", "Пользователь не найден");
        return NULL;
    }
}

QList<Customer*>* DatabaseService::getCustomersViaManager(QString login)
{
    QList<Customer*> *result = new QList<Customer*>;
    QSqlQuery* query = new QSqlQuery(database);
    query->exec("SELECT * FROM customers WHERE manager='" + login + "'");
    while(query->next())
        result->push_back(new Customer(query->value(0).toString(), query->value(2).toString(), query->value(1).toString(), query->value(3).toInt()));

    return result;
}

QList<Order*> *DatabaseService::getOrders(QString login)
{
    QList<Order*> *result = new QList<Order*>;
    QSqlQuery* query = new QSqlQuery(database);
    query->exec("SELECT * FROM orders RIGHT JOIN order_states ON order_states.id = orders.order_state RIGHT JOIN customers ON customers.id = orders.customer WHERE orders.manager='" + login + "'");
    while (query->next())
        result->push_back(new Order(query->value(0).toString(), query->value(11).toString(), query->value(2).toInt(), query->value(3).toString(),
                                    query->value(4).toString(), query->value(5).toString(), query->value(9).toString()));

    return result;
}

QList<Author *> *DatabaseService::getAuthors()
{
    QList<Author*>* result = new QList<Author*>();
    QSqlQuery* query = new QSqlQuery(database);
    query->exec("SELECT * FROM authors");
    while (query->next())
        result->push_back(new Author(query->value(0).toString(), query->value(1).toString(), query->value(2).toString(), query->value(3).toString(),
                                     query->value(4).toInt()));

    return result;
}

QList<Work *> *DatabaseService::getWorks()
{
    QList<Work*>* result = new QList<Work*>();
    QSqlQuery* query = new QSqlQuery(database);
    query->exec("SELECT * FROM works LEFT JOIN work_types ON work_types.id = works.\"type\"");
    while (query->next())
        result->push_back(new Work(query->value(0).toString(), query->value(1).toString(), query->value(2).toInt(), new WorkType(query->value(3).toInt(), query->value(5).toString())));

    for(Work* work: *result) {
        QSqlQuery* query = new QSqlQuery(database);
        query->exec("SELECT * FROM genre_affiliation LEFT JOIN genres ON genres.id = genre_affiliation.genre WHERE genre_affiliation.\"work\" = '" + work->id + "'");
        while (query->next())
            work->genres->push_back(new Genre(query->value(2).toInt(), query->value(3).toString()));

        query->exec("SELECT * FROM authorship LEFT JOIN authors ON authors.id = authorship.author WHERE authorship.\"work\" = '" + work->id + "'");
        while (query->next())
            work->authors->push_back(new Author(query->value(2).toString(), query->value(3).toString(), query->value(4).toString(), query->value(5).toString(),
                                               query->value(6).toInt()));
    }

    return result;
}

QList<PrintCenter *> *DatabaseService::getPrintCenters()
{
    QList<PrintCenter*> *result = new QList<PrintCenter*>();
    QSqlQuery* query = new QSqlQuery(database);
    query->exec("SELECT * FROM print_centers");
    while(query->next())
        result->push_back(new PrintCenter(query->value(0).toString(), query->value(1).toString(), query->value(3).toInt(), query->value(4).toInt()));

    return result;
}

PrintCenter *DatabaseService::getPrintCenterViaManager(Manager *manager)
{
    QSqlQuery* query = new QSqlQuery(database);
    query->exec("SELECT * FROM print_centers WHERE manager = '" + manager->getId() + "'");
    query->next();
    PrintCenter *pc = new PrintCenter(query->value(0).toString(), query->value(1).toString(), query->value(3).toInt(), query->value(4).toInt());
    return pc;
}

QList<WorkType *> *DatabaseService::getWorkTypes()
{
    QList<WorkType *> *result = new QList<WorkType *>();
    QSqlQuery* query = new QSqlQuery(database);
    query->exec("SELECT * FROM work_types");
    while(query->next())
        result->push_back(new WorkType(query->value(0).toInt(), query->value(1).toString()));

    return result;
}

QList<Genre *> *DatabaseService::getGenres()
{
    QList<Genre *> *result = new QList<Genre *>();
    QSqlQuery* query = new QSqlQuery(database);
    query->exec("SELECT * FROM genres");
    while(query->next())
        result->push_back(new Genre(query->value(0).toInt(), query->value(1).toString()));

    return result;
}

QList<Batch *> *DatabaseService::getReadyBatches(QString printCenterId)
{
    QList<Batch *> * result = new QList<Batch *>();
    QSqlQuery* query = new QSqlQuery(database);
    query->exec("SELECT * FROM batches WHERE print_center = '" + printCenterId + "' AND print_state = 4");
    while(query->next())
        result->push_back(new Batch(query->value(0).toString(), query->value(1).toString(), query->value(2).toString(),
                                    query->value(3).toString(), "ready", query->value(5).toInt()));

    return result;
}

QList<Batch *> *DatabaseService::getOnWorkBatches(QString printCenterId)
{
    QList<Batch *> * result = new QList<Batch *>();
    QSqlQuery* query = new QSqlQuery(database);
    query->exec("SELECT * FROM batches WHERE print_center = '" + printCenterId + "' AND print_state = 3");
    while(query->next())
        result->push_back(new Batch(query->value(0).toString(), query->value(1).toString(), query->value(2).toString(),
                                    query->value(3).toString(), "on_work", query->value(5).toInt()));

    return result;
}

QList<Manager *> *DatabaseService::getManagers()
{
    QList<Manager*>* result = new QList<Manager*>();
    QSqlQuery* query = new QSqlQuery(database);
    query->exec("SELECT * FROM managers WHERE position <> 3");
    while(query->next())
        result->push_back(new Manager(query->value(0).toString(), query->value(1).toString(), query->value(2).toString(), query->value(3).toString(),
                                      query->value(4).toString(), query->value(5).toString(), query->value(7).toString(), query->value(8).toBool()));
    return result;
}

QList<Position *> *DatabaseService::getPositions()
{
    QList<Position*>* result = new QList<Position*>();
    QSqlQuery* query = new QSqlQuery(database);
    query->exec("SELECT * FROM positions");
    while(query->next())
        result->push_back(new Position (query->value(0).toInt(), query->value(1).toString()));
    return result;
}

QList<Log *> *DatabaseService::getLogs()
{
    return logger->getLogs();
}

void DatabaseService::addAuthor(QString name, QString surname, QString ptr, QString managerId)
{
    QString uuid = QUuid::createUuid().toString();
    uuid.remove('}');
    uuid.remove('{');

    QSqlQuery* query = new QSqlQuery(database);
    query->exec("INSERT INTO authors VALUES ('" + uuid + "', '" + name + "', '" + surname + "', '" + ptr + "', 0)");

    logger->writeLog(new Log(managerId, "add", uuid, "author"));
}

void DatabaseService::addCustomer(QString name, QString spec, QString managerID)
{
    QString uuid = QUuid::createUuid().toString();
    uuid.remove('}');
    uuid.remove('{');

    QSqlQuery* query = new QSqlQuery(database);
    query->exec("INSERT INTO customers VALUES (gen_random_uuid(), '" + name + "', '" + spec + "', 0, '" + managerID + "')");

    logger->writeLog(new Log(managerID, "add", uuid, "customer"));
}

void DatabaseService::createOrder(Order *order, QString managerId)
{
    QSqlQuery* query = new QSqlQuery(database);
    QString currentDate = QDateTime::currentDateTime().toString("yyyy.MM.dd").replace(".", "-");
    query->exec("INSERT INTO orders VALUES ('"+ order->getId() +"', '" + order->getCustomer() + "', " +
                QString::number(order->getCost()) + ", '" + currentDate + "', '" + order->getDedline() + "', NULL, 3, '" + managerId + "')");

    for(Batch* batch: *order->batches)
        query->exec("INSERT INTO batches VALUES (gen_random_uuid(), '" + batch->order + "', '" + batch->work + "', '" + batch->print_center + "', 3, " +
                    QString::number(batch->count_of_work) + ")");

    logger->writeLog(new Log(managerId, "add", order->getId(), "order"));
}

void DatabaseService::addWork(Work *newWork, QString managerId)
{
    QSqlQuery* query = new QSqlQuery(database);
    query->exec("INSERT INTO works VALUES ('" + newWork->id + "', '" + newWork->name + "', " +
                QString::number(newWork->edition_number) + ", " + QString::number(newWork->type->getId()) + ")");

    for(Author* author: *newWork->authors)
        query->exec("INSERT INTO authorship VALUES ('" + author->id + "', '" + newWork->id + "')");

    for(Genre* genre: *newWork->genres)
        query->exec("INSERT INTO genre_affiliation VALUES (" + QString::number(genre->getId()) + ", '" + newWork->id + "')");

    logger->writeLog(new Log(managerId, "add", newWork->id, "work"));
}

void DatabaseService::addManager(Manager *newManager, QString password)
{
    QSqlQuery* query = new QSqlQuery(database);
    QString currentDate = QDateTime::currentDateTime().toString("yyyy.MM.dd HH:mm:ss").replace(".", "-");
    query->exec("INSERT INTO managers VALUES (gen_random_uuid(), '" + newManager->getName() + "', '" + newManager->getSurname() +
                "', '" + newManager->getPatronymic() + "', '" + newManager->getUsername() + "', " + newManager->getPosition() +
                ", crypt('" + password + "', gen_salt('bf', 8)), '" + currentDate + "', true)");
}

void DatabaseService::changeOrderStatus(QString orderId, QString managerId)
{
    QSqlQuery* query = new QSqlQuery(database);
    QString currentDate = QDateTime::currentDateTime().toString("yyyy.MM.dd").replace(".", "-");
    query->exec("UPDATE orders SET order_state = 5, close_date = '" + currentDate + "' WHERE id = '" + orderId + "'");

    logger->writeLog(new Log(managerId, "change", orderId, "order"));
}

void DatabaseService::changeBatchPrintStatus(QString batchId, QString status, QString managerId)
{
    QSqlQuery* query = new QSqlQuery(database);
    query->exec("UPDATE batches SET print_state = " + status + " WHERE id = '" + batchId + "'");

    logger->writeLog(new Log(managerId, "change", batchId, "batch"));
}

void DatabaseService::changeManagerStatus(QString managerId, QString status)
{
    QSqlQuery* query = new QSqlQuery(database);
    query->exec("UPDATE managers SET is_active = " + status + " WHERE id = '" + managerId + "'");
}

void DatabaseService::changeManagerPassword(QString managerId, QString newPassword)
{
    QSqlQuery* query = new QSqlQuery(database);
    query->exec("UPDATE managers SET password = crypt('" + newPassword + "', gen_salt('bf', 8)) WHERE id = '" + managerId + "'");
}
