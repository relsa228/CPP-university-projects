#ifndef THREAD_H
#define THREAD_H

#include <QThread>
#include <QVector>

#include "Entities/testclass.h"
#include "Service/mergesortservice.h"

class Thread
{
public:
    QVector<TestClass*>* workingVector;
private:
    QThread* workingThread;

    QString runtimeStatus;
    QString lvlOfWork;

public:
    Thread(QVector<TestClass*>* workingVector);
};

#endif // THREAD_H
