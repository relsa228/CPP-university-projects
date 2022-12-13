#include "author.h"

Author::Author(QString id, QString name, QString surname, QString patronymic, int work_count) {
    this->id = id;
    this->name = name;
    this->surname = surname;
    this->patronymic = patronymic;
    this->work_count = work_count;
}

Author::Author()
{

}
