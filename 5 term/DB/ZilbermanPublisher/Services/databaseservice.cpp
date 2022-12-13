#include "databaseservice.h"

DatabaseService::DatabaseService()
{
    database = QSqlDatabase::addDatabase("QPSQL");
    database.setDatabaseName("publisher_controller_base");
    database.setUserName("postgres");
    database.setPassword("root");
    if(!database.open())
        QMessageBox::critical(0, "Соединение не установлено", database.lastError().text());
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

    for(Order* order: *result) {
        QSqlQuery* query = new QSqlQuery(database);
        query->exec("SELECT * FROM batches RIGHT JOIN print_states ON print_states.id = batches.print_state WHERE \"order\"='" + order->getId() + "'");
        while(query->next()) {
            Batch *batch = new Batch(query->value(0).toString(), query->value(2).toString(), query->value(5).toInt(), query->value(7).toString(), query->value(3).toString());
            order->batches->push_back(batch);
        }
    }

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

void DatabaseService::addAuthor(QString name, QString surname, QString ptr)
{
    QSqlQuery* query = new QSqlQuery(database);
    query->exec("INSERT INTO authors VALUES (gen_random_uuid(), '" + name + "', '" + surname + "', '" + ptr + "', 0)");
}

void DatabaseService::addCustomer(QString name, QString spec, QString managerID)
{
    QSqlQuery* query = new QSqlQuery(database);
    query->exec("INSERT INTO customers VALUES (gen_random_uuid(), '" + name + "', '" + spec + "', 0, '" + managerID + "')");
}

void DatabaseService::createOrder(Order *order, QString managerId)
{
    QSqlQuery* query = new QSqlQuery(database);
    QString currentDate = QDateTime::currentDateTime().toString("yyyy.MM.dd").replace(".", "-");
    query->exec("INSERT INTO orders VALUES ('"+ order->getId() +"', '" + order->getCustomer() + "', " +
                QString::number(order->getCost()) + ", '" + currentDate + "', '" + order->getDedline() + "', NULL, 3, '" + managerId + "')");
    for(Batch* batch: *order->batches){
        QString zapros = "INSERT INTO batches VALUES (gen_random_uuid(), '" + batch->order + "', '" + batch->work + "', '" + batch->print_center + "', 3, " +
                QString::number(batch->count_of_work) + ")";
        query->exec("INSERT INTO batches VALUES (gen_random_uuid(), '" + batch->order + "', '" + batch->work + "', '" + batch->print_center + "', 3, " +
                    QString::number(batch->count_of_work) + ")");
        qDebug() << zapros;
    }
}

void DatabaseService::addWork(Work *newWork)
{

}
