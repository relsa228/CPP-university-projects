#include "thread.h"

Thread::Thread(QVector<TestClass*>* workingVector)
{
    this->workingVector = workingVector;
    this->workingThread = new QThread();

    this->lvlOfWork = "0 lvl";
    this->runtimeStatus = "onStart";
}
