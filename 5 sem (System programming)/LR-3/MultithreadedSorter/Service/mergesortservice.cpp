#include "mergesortservice.h"

MergeSortService::MergeSortService()
{

}

void MergeSortService::sortGroup(QVector<TestClass *> *wrkGroup)
{
    for (int i = 0; i < wrkGroup->length() - 1; i++)
        for (int j = 0; j < wrkGroup->length() - i - 1; j++)
            if (wrkGroup->at(j)->getObjectIndex() > wrkGroup->at(j + 1)->getObjectIndex())
                wrkGroup->swapItemsAt(j, j + 1);
}

QVector<TestClass *> *MergeSortService::mergeGroups(QVector<TestClass *> *firstWrkGroup, QVector<TestClass *> *secondWrkGroup)
{
    QVector<TestClass *>* resultVector = new QVector<TestClass *>();

    while(!firstWrkGroup->isEmpty() && !secondWrkGroup->isEmpty()) {
        if (firstWrkGroup->isEmpty()) {
            resultVector->push_front(secondWrkGroup->first());
            secondWrkGroup->pop_front();
        }
        else if(secondWrkGroup->isEmpty()) {
            resultVector->push_front(firstWrkGroup->first());
            firstWrkGroup->pop_front();
        }
        else if(firstWrkGroup->first()->getObjectIndex() > secondWrkGroup->first()->getObjectIndex()) {
            resultVector->push_front(secondWrkGroup->first());
            secondWrkGroup->pop_front();
        }
        else if(firstWrkGroup->first()->getObjectIndex() < secondWrkGroup->first()->getObjectIndex()) {
            resultVector->push_front(firstWrkGroup->first());
            firstWrkGroup->pop_front();
        }
        else {
            resultVector->push_front(firstWrkGroup->first());
            firstWrkGroup->pop_front();

            resultVector->push_front(secondWrkGroup->first());
            secondWrkGroup->pop_front();
        }
    }

    return resultVector;
}
