#include "regunit.h"

const QString &RegUnit::getUnitValue() const
{
    return UnitValue;
}

void RegUnit::setUnitValue(const QString &newUnitValue)
{
    UnitValue = newUnitValue;
}

const QString &RegUnit::getUnitName() const
{
    return UnitName;
}

void RegUnit::setUnitName(const QString &newUnitName)
{
    UnitName = newUnitName;
}

RegUnit::RegUnit()
{

}

RegUnit::RegUnit(QString name, QString value)
{
    this->UnitName = name;
    this->UnitValue = value;
}
