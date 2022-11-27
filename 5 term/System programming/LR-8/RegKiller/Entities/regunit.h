#ifndef REGUNIT_H
#define REGUNIT_H

#include "QString"


class RegUnit
{
private:
    QString UnitName;
    QString UnitValue;
public:
    RegUnit();
    RegUnit(QString name, QString value);
    const QString &getUnitValue() const;
    void setUnitValue(const QString &newUnitValue);
    const QString &getUnitName() const;
    void setUnitName(const QString &newUnitName);
};

#endif // REGUNIT_H
