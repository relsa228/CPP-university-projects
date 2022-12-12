#ifndef AUTHOR_H
#define AUTHOR_H

#include <QString>

class Author
{
public:
    QString id;
    QString name;
    QString surname;
    QString patronymic;
    int work_count;

    Author();
};

#endif // AUTHOR_H
