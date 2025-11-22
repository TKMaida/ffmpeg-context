#include <stdio.h>
#include <tchar.h>

#include "op_result.h"
#include "logging.h"
#include "reg_utils.h"

LSTATUS RegKeyExists(HKEY hKeyRoot, LPCTSTR lpSubKey)
{
    HKEY hKey;

    LONG lStatus = RegOpenKeyEx(hKeyRoot, lpSubKey, 0, KEY_READ, &hKey);

    if (lStatus == ERROR_SUCCESS)
    {
        RegCloseKey(hKey);
    }
    _tprintf(_T("RegKeyExists result: %ld\n"), lStatus);

    return lStatus;
}

LSTATUS CreateRegKey(HKEY hKeyRoot, LPCTSTR lpSubKey)
{
    HKEY hKey;
    DWORD disposition;

    LSTATUS lStatus = RegCreateKeyEx(
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

    if (lStatus == ERROR_SUCCESS)
    {
        RegCloseKey(hKey);
    }
    return lStatus;
}

OpResult UpdateRegistry() {

    LSTATUS lStatus = RegKeyExists(HKEY_CLASSES_ROOT, PROGRAM_REG_KEY);

    if (lStatus == ERROR_FILE_NOT_FOUND)
    {

        lStatus = CreateRegKey(HKEY_CLASSES_ROOT, PROGRAM_REG_KEY);

        if (lStatus != ERROR_SUCCESS)
        {

            TCHAR sysMsg[128] = { 0 };
            GetSystemMessage(lStatus, sysMsg, 128);

            TCHAR finalMsg[OP_RESULT_MSG_SIZE] = { 0 };

            OpResult result;

            result.code = lStatus;
            _stprintf_s(result.msg, OP_RESULT_MSG_SIZE, _T("%sFailed to create base key."), sysMsg);

            return result;
        }
    }
    else if (lStatus != ERROR_SUCCESS)
    {
        TCHAR sysMsg[128] = { 0 };
        GetSystemMessage(lStatus, sysMsg, 128);

        TCHAR finalMsg[OP_RESULT_MSG_SIZE] = { 0 };

        OpResult result;

        result.code = lStatus;
        _stprintf_s(result.msg, OP_RESULT_MSG_SIZE, _T("%sUnhandled exception checking base key."), sysMsg);

        return result;
    }

    lStatus = RegKeyExists(HKEY_CLASSES_ROOT, PROGRAM_REG_KEY_COMMAND);

    if (lStatus == ERROR_FILE_NOT_FOUND)
    {
        lStatus = CreateRegKey(HKEY_CLASSES_ROOT, PROGRAM_REG_KEY_COMMAND);

        if (lStatus != ERROR_SUCCESS)
        {
            TCHAR sysMsg[128] = { 0 };
            GetSystemMessage(lStatus, sysMsg, 128);

            OpResult result;

            result.code = lStatus;
            _stprintf_s(result.msg, OP_RESULT_MSG_SIZE, _T("%sFailed to create command key."), sysMsg);

            return result;
        }
    }
    else if (lStatus != ERROR_SUCCESS)
    {
        TCHAR sysMsg[128] = { 0 };
        GetSystemMessage(lStatus, sysMsg, 128);

        TCHAR finalMsg[OP_RESULT_MSG_SIZE] = { 0 };
        _stprintf_s(finalMsg, OP_RESULT_MSG_SIZE, _T("%sUnhandled exception checking command key."), sysMsg);

        return (OpResult) { lStatus, finalMsg };
    }

    OpResult result;
    result.code = ERROR_SUCCESS;
    _stprintf_s(result.msg, OP_RESULT_MSG_SIZE, _T("Successfully updated registry!"));
    return result;
}