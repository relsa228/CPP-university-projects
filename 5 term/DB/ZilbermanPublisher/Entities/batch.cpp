#include "batch.h"

Batch::Batch(QString id, QString work, int count_of_work, QString print_state)
{
    this->id = id;
    this->work = work;
    this->count_of_work = count_of_work;
    this->print_state = print_state;
}
