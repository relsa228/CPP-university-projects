#include "manager.h"

Manager::Manager()
{

}

Manager::Manager(QString id, QString name, QString surname, QString patronymic, QString username, QString position, bool is_active)
{
    this->id = id;
    this->username = username;
    this->name = name;
    this->surname = surname;
    this->patronymic = patronymic;
    this->position = position;
    this->is_active = is_active;
}

const QString &Manager::getId() const
{
    return id;
}

const QString &Manager::getUsername() const
{
    return username;
}

const QString &Manager::getName() const
{
    return name;
}

const QString &Manager::getSurname() const
{
    return surname;
}

const QString &Manager::getPatronymic() const
{
    return patronymic;
}

const QString &Manager::getPosition() const
{
    return position;
}

bool Manager::getIs_active() const
{
    return is_active;
}
