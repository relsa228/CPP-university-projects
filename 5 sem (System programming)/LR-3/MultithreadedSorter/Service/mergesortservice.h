#ifndef MERGESORTSERVICE_H
#define MERGESORTSERVICE_H

#include <QVector>

#include "Entities/testclass.h"

class MergeSortService
{
public:
    MergeSortService();

    void sortGroup(QVector<TestClass*>* wrkGroup);
    QVector<TestClass*>* mergeGroups(QVector<TestClass*>* firstWrkGroup, QVector<TestClass*>* secondWrkGroup);
};

#endif // MERGESORTSERVICE_H
