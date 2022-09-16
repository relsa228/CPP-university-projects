#ifndef THREADSERVICE_H
#define THREADSERVICE_H

#include <QVector>

#include "Entities/testclass.h"
#include "Entities/thread.h"

#include "Service/mergesortservice.h"

class ThreadService
{
private:
    MergeSortService* mergeSortService;
    QVector<Thread*>* sortData;

public:
    ThreadService(long collectionCount, long groupCount);

private:
    QVector<TestClass*>* generateCollection(long collectionCount);
    void generateThreadCollection(QVector<TestClass*>* testClassCollection, long groupCount);

    void initSort(QVector<TestClass*>* wrkVector);
    void initMerge(QVector<TestClass*>* firstWrkVector, QVector<TestClass*>* secondWrkVector);
    void initSortProcess();
    void startTread(Thread* wrkThreads);
};

#endif // THREADSERVICE_H
