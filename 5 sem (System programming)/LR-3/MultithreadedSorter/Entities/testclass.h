#ifndef TESTCLASS_H
#define TESTCLASS_H

#include <QString>

class TestClass
{
private:
    QString objectName;
    long objectIndex;

public:
    TestClass(QString objectName, long objectIndex);

    const QString &getObjectName() const;
    void setObjectName(const QString &newObjectName);

    long getObjectIndex() const;
    void setObjectIndex(long newObjectIndex);
};

#endif // TESTCLASS_H
