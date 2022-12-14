#include "batch.h"

Batch::Batch(QString orderID, QString work, QString print_center, QString print_state, int count_of_work)
{
    this->order = orderID;
    this->work = work;
    this->count_of_work = count_of_work;
    this->print_state = print_state;
    this->print_center = print_center;
}

Batch::Batch(QString id, QString orderID, QString work, QString print_center, QString print_state, int count_of_work)
{
    this->id = id;
    this->order = orderID;
    this->work = work;
    this->count_of_work = count_of_work;
    this->print_state = print_state;
    this->print_center = print_center;
}
