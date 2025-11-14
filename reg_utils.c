#include <reg_utils.h>
#include <stdio.h>
#include <logging.h>
#include <tchar.h>

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
	LPDWORD disposition;

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

LSTATUS UpdateRegistry()
{
	LPCTSTR lpBaseKey = TEXT(PROGRAM_REG_KEY);
	LPCTSTR lpCommandKey = _T(PROGRAM_REG_KEY_COMMAND);
	LSTATUS result = RegKeyExists(HKEY_CLASSES_ROOT, lpBaseKey);

	if (result == ERROR_FILE_NOT_FOUND)
	{
		result = CreateRegKey(HKEY_CLASSES_ROOT, lpBaseKey);
		if (result != ERROR_SUCCESS)
		{
			return result;
		}
	}
	else if (result != ERROR_SUCCESS)
	{
		return result; 
	}

	result = RegKeyExists(HKEY_CLASSES_ROOT, lpCommandKey);

	if (result == ERROR_FILE_NOT_FOUND)
	{
		result = CreateRegKey(HKEY_CLASSES_ROOT, lpCommandKey);

		if (result != ERROR_SUCCESS)
		{
			return result;
		}
	}
	else if (result != ERROR_SUCCESS)
	{
		return result;
	}

	return ERROR_SUCCESS;
}



