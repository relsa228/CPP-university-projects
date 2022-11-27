#include "regworkerservice.h"
#include <sstream>

#define MAX_KEY_LENGTH 255
#define MAX_VALUE_NAME 16383

RegWorkerService::RegWorkerService()
{

}

QVector<RegUnit>* RegWorkerService::getNamesOfUnits(HKEY hKey)
{
    QVector<RegUnit>* result = new QVector<RegUnit>();

    TCHAR    achClass[MAX_PATH] = TEXT("");
    DWORD    cchClassName = MAX_PATH;
    DWORD    cSubKeys=0;
    DWORD    cbMaxSubKey;
    DWORD    cchMaxClass;
    DWORD    cValues;
    DWORD    cchMaxValue;
    DWORD    cbMaxValueData;
    DWORD    cbSecurityDescriptor;
    FILETIME ftLastWriteTime;

    DWORD i, retCode;

    TCHAR  achValue[MAX_VALUE_NAME];
    DWORD cchValue = MAX_VALUE_NAME;

    retCode = RegQueryInfoKey(
            hKey,
            achClass,
            &cchClassName,
            NULL,
            &cSubKeys,
            &cbMaxSubKey,
            &cchMaxClass,
            &cValues,
            &cchMaxValue,
            &cbMaxValueData,
            &cbSecurityDescriptor,
            &ftLastWriteTime);

    if (cValues) {
        for (i = 0, retCode = ERROR_SUCCESS; i < cValues; i++) {
            cchValue = MAX_VALUE_NAME;
            achValue[0] = '\0';
            retCode = RegEnumValue(hKey, i,
                                   achValue,
                                   &cchValue, NULL, NULL, NULL, NULL);

            if (retCode == ERROR_SUCCESS) {
                std::wstring test(&achValue[0]);
                std::string name(test.begin(), test.end());
                result->push_back(RegUnit(QString::fromStdString(name), ""));
            }
        }
    }

    return result;
}

RegUnit RegWorkerService::extractUnit(LPCTSTR subkey, LPCTSTR name, DWORD type, HKEY option)
{
    HKEY key;
    TCHAR value[255];
    DWORD valueL = 255;
    RegOpenKey(option, subkey, &key);
    RegQueryValueEx(key, name, NULL, &type, (LPBYTE)&value, &valueL);
    std::wstring test(&value[0]);
    std::string result(test.begin(), test.end());

    if (type == REG_DWORD)
    {
        DWORD dword;
        if (0 == RegQueryValueEx(key, name, NULL, &type, reinterpret_cast<BYTE*>(&dword), &valueL)){
            std::stringstream ss;
            ss << dword;
            result = ss.str();
        }
    }
    if (type == REG_BINARY)
    {
        BYTE bytes[1024];
        if (0 == RegQueryValueEx(key, name, NULL, &type, reinterpret_cast<LPBYTE>(&bytes), &valueL)){
            for(BYTE byte: bytes){
                std::stringstream ss;
                ss << (int)byte;
                result = ss.str();
            }
        }
    }

    RegCloseKey(key);

    return RegUnit(QString::fromWCharArray(name), QString::fromStdString(result));
}

QVector<RegUnit> *RegWorkerService::extractUnits(LPCTSTR subkey, DWORD type, HKEY option)
{
    HKEY key;
    RegOpenKey(option, subkey, &key);
    QVector<RegUnit> *result = getNamesOfUnits(key);

    for(int i = 0; i < result->count(); i++) {
        std::wstring inptName = result->at(i).getUnitName().toStdWString();
        (*result)[i] = extractUnit(subkey,inptName.c_str(), type, option);
    }

    return result;
}
