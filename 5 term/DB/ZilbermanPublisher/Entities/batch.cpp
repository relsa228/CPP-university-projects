#include "batch.h"

Batch::Batch(QString orderID, QString work, int count_of_work, QString print_state, QString print_center)
{
    this->order = orderID;
    this->work = work;
    this->count_of_work = count_of_work;
    this->print_state = print_state;
    this->print_center = print_center;
}
