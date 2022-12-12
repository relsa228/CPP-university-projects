#ifndef MANAGER_H
#define MANAGER_H

#include <QString>

class Manager
{
public:
    Manager();
    Manager(QString id, QString name, QString surname,
            QString patronymic, QString username, QString position, bool is_active);

    const QString &getId() const;
    const QString &getUsername() const;
    const QString &getName() const;
    const QString &getSurname() const;
    const QString &getPatronymic() const;
    const QString &getPosition() const;
    bool getIs_active() const;

private:
    QString id;

    QString username;
    QString name;
    QString surname;
    QString patronymic;

    QString position;
    bool is_active;
};

#endif // MANAGER_H
