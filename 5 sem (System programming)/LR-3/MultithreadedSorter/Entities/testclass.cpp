#include "testclass.h"

const QString &TestClass::getObjectName() const
{
    return objectName;
}

void TestClass::setObjectName(const QString &newObjectName)
{
    objectName = newObjectName;
}

long TestClass::getObjectIndex() const
{
    return objectIndex;
}

void TestClass::setObjectIndex(long newObjectIndex)
{
    objectIndex = newObjectIndex;
}

TestClass::TestClass(QString objectName, long objectIndex) {
    this->objectIndex = objectIndex;
    this->objectName = objectName;
}
