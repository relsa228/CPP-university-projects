#include "regworkerservice.h"

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

RegUnit RegWorkerService::extractUnit(LPCTSTR subkey, LPCTSTR name, DWORD type, uint option)
{
    HKEY key;
    TCHAR value[255];
    DWORD valueL = 255;

    switch (option) {
    case 0:
        RegOpenKey(HKEY_CLASSES_ROOT, subkey, &key);
        break;
    case 1:
        RegOpenKey(HKEY_CURRENT_USER, subkey, &key);
        break;
    case 2:
        RegOpenKey(HKEY_LOCAL_MACHINE, subkey, &key);
        break;
    case 3:
        RegOpenKey(HKEY_USERS, subkey, &key);
        break;
    case 4:
        RegOpenKey(HKEY_CURRENT_CONFIG, subkey, &key);
        break;
    }

    RegQueryValueEx(key, name, NULL, &type, (LPBYTE)&value, &valueL);
    RegCloseKey(key);

    std::wstring test(&value[0]);
    std::string result(test.begin(), test.end());

    return RegUnit(QString::fromWCharArray(name), QString::fromStdString(result));
}

QVector<RegUnit> *RegWorkerService::extractUnits(LPCTSTR subkey, DWORD type, uint option)
{
    HKEY key;

    switch (option) {
    case 0:
        RegOpenKey(HKEY_CLASSES_ROOT, subkey, &key);
        break;
    case 1:
        RegOpenKey(HKEY_CURRENT_USER, subkey, &key);
        break;
    case 2:
        RegOpenKey(HKEY_LOCAL_MACHINE, subkey, &key);
        break;
    case 3:
        RegOpenKey(HKEY_USERS, subkey, &key);
        break;
    case 4:
        RegOpenKey(HKEY_CURRENT_CONFIG, subkey, &key);
        break;
    }

    QVector<RegUnit> *result = getNamesOfUnits(key);

    for(int i = 0; i < result->count(); i++) {
        std::wstring inptName = result->at(i).getUnitName().toStdWString();
        (*result)[i] = extractUnit(subkey,inptName.c_str(), type, option);
    }

    return result;
}
