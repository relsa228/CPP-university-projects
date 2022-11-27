#ifndef REGWORKERSERVICE_H
#define REGWORKERSERVICE_H

#include "Entities/regunit.h"
#include "windows.h"
#include "QVector"

class RegWorkerService
{
private:
    QVector<RegUnit>* getNamesOfUnits(HKEY hKey);
public:
    RegWorkerService();

    RegUnit extractUnit(LPCTSTR subkey, LPCTSTR name, DWORD type, uint option);
    QVector<RegUnit>* extractUnits(LPCTSTR subkey, DWORD type, uint option);

};

#endif // REGWORKERSERVICE_H
