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
            Batch *batch = new Batch(query->value(0).toString(), query->value(2).toString(), query->value(5).toInt(), query->value(7).toString());
            order->batches->push_back(batch);
        }
    }

    return result;
}
