#include <logging.h>
#include <tchar.h>
#include <utils.h>

void PrintErrorMessage(LONG errorCode)
{
	LPTSTR errorMsg = NULL;
	if (!FormatMessage(
		FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_ALLOCATE_BUFFER,
		NULL,
		errorCode,
		0,
		&errorMsg,
		0,
		NULL
	))
	{
		printf("Format message failed with 0x%x\n", GetLastError());
	}

	_tprintf(L"ERROR: %s", errorMsg);

}


TCHAR* ErrorMessage(LONG errorCode) 
{
    LPTSTR sysMsg = NULL;
    DWORD len = FormatMessage(
        FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
        NULL,
        errorCode,
        0,
        (LPTSTR)&sysMsg,
        0,
        NULL
    );

    TCHAR* msg = NULL;

    if (!sysMsg || len == 0) {
        msg = (TCHAR*)malloc(64 * sizeof(TCHAR));
        if (msg) _stprintf_s(msg, 64, _T("Error code 0x%08X"), errorCode);
    }
    else {
        msg = (TCHAR*)malloc((len + 1) * sizeof(TCHAR));
        if (msg) {
            _tcsncpy_s(msg, len + 1, sysMsg, len);
            msg[len] = 0; 
        }
        LocalFree(sysMsg);
    }

    return msg;
}