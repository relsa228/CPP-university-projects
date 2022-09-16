#include "threadservice.h"

ThreadService::ThreadService(long collectionCount, long groupCount)
{
    mergeSortService = new MergeSortService();
    generateThreadCollection(generateCollection(collectionCount), groupCount);
}

QVector<TestClass *>* ThreadService::generateCollection(long collectionCount)
{
    QVector<TestClass *> *resultVector = new QVector<TestClass *>();
    for(long i = 0; i < collectionCount; i++)
        resultVector->push_back(new TestClass("ObjectName_" + QString::number(i), i));

    return resultVector;
}

void ThreadService::generateThreadCollection(QVector<TestClass *> *testClassCollection, long groupCount)
{
    this->sortData = new QVector<Thread*>();
    long currentCount = testClassCollection->count()/groupCount;

    sortData->push_back(new Thread(new QVector<TestClass*>()));
    while(!testClassCollection->isEmpty())
    {
        if(sortData->last()->workingVector->length() != currentCount) {
            sortData->last()->workingVector->push_back(testClassCollection->first());
            testClassCollection->pop_front();
        }
        else
            sortData->push_back(new Thread(new QVector<TestClass*>()));
    }
}
