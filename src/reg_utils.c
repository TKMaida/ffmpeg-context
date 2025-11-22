#include <stdio.h>
#include <tchar.h>

#include "op_result.h"
#include "logging.h"
#include "reg_utils.h"

LSTATUS RegKeyExists(HKEY hKeyRoot, LPCTSTR lpSubKey)
{
	HKEY hKey;

	LONG lResult = RegOpenKeyEx(hKeyRoot, lpSubKey, 0, KEY_READ, &hKey);

	if (lResult == ERROR_SUCCESS)
	{
		RegCloseKey(hKey);
	}
	return lResult;
}

LSTATUS CreateRegKey(HKEY hKeyRoot, LPCTSTR lpSubKey)
{
	HKEY hKey;
	DWORD disposition;

	LONG lResult = RegCreateKeyEx(
		hKeyRoot,
		lpSubKey,
		0,
		NULL,
		REG_OPTION_NON_VOLATILE,
		KEY_WRITE,
		NULL,
		&hKey,
		&disposition
		);

	if (lResult == ERROR_SUCCESS)
	{
		RegCloseKey(hKey);
	}

	return lResult;
}

OpResult UpdateRegistry() {

    LSTATUS lResult = RegKeyExists(HKEY_CLASSES_ROOT, PROGRAM_REG_KEY);

    if (lResult == ERROR_FILE_NOT_FOUND) 
    {

        lResult = CreateRegKey(HKEY_CLASSES_ROOT, PROGRAM_REG_KEY);

        if (lResult != ERROR_SUCCESS) 
        {
           
            TCHAR sysMsg[128] = { 0 };
            GetSystemMessage(lResult, sysMsg, 128);

            TCHAR finalMsg[256] = { 0 };
            _stprintf_s(finalMsg, 256, _T("%s: Failed to create base key."), sysMsg);

            return (OpResult) { lResult, finalMsg };
        }
    }
    else if (lResult != ERROR_SUCCESS) 
    {
        TCHAR sysMsg[128] = { 0 };
        GetSystemMessage(lResult, sysMsg, 128);

        TCHAR finalMsg[256] = { 0 };
        _stprintf_s(finalMsg, 256, _T("%s: Unhandled exception checking base key."), sysMsg);

        return (OpResult) { lResult, finalMsg };
    }

    lResult = RegKeyExists(HKEY_CLASSES_ROOT, PROGRAM_REG_KEY_COMMAND);

    if (lResult == ERROR_FILE_NOT_FOUND) 
    {
        lResult = CreateRegKey(HKEY_CLASSES_ROOT, PROGRAM_REG_KEY_COMMAND);

        if (lResult != ERROR_SUCCESS) 
        {
            TCHAR sysMsg[128] = { 0 };
            GetSystemMessage(lResult, sysMsg, 128);

            TCHAR finalMsg[256] = { 0 };
            _stprintf_s(finalMsg, 256, _T("%s: Failed to create command key."), sysMsg);

            return (OpResult) { lResult, finalMsg };
        }
    }
    else if (lResult != ERROR_SUCCESS) 
    {
        TCHAR sysMsg[128] = { 0 };
        GetSystemMessage(lResult, sysMsg, 128);

        TCHAR finalMsg[256] = { 0 };
        _stprintf_s(finalMsg, 256, _T("%s: Unhandled exception checking base key."), sysMsg);

        return (OpResult) { lResult, finalMsg };
    }

    TCHAR* successMsg = _T("Registry updated successfully.");
    return (OpResult) { ERROR_SUCCESS, successMsg };
}