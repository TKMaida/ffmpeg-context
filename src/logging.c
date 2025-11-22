#include <tchar.h>

#include "logging.h"

void PrintErrorMessage(LONG errorCode)
{
	LPTSTR errorMsg = NULL;
	if (!FormatMessage(
		FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_ALLOCATE_BUFFER,
		NULL,
		errorCode,
		0,
		(LPTSTR) & errorMsg,
		0,
		NULL
	))
	{
		_tprintf(_T("Format message failed with 0x%x\n"), GetLastError());
	}

	_tprintf(_T("ERROR: %s"), errorMsg);

}

void GetSystemMessage(LONG code, TCHAR errMsg[], size_t errMsgSize) {
	
	TCHAR buff[ERROR_BUFFER_SIZE];

	DWORD len;

	len = FormatMessage(
		FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
		NULL,
		code,
		0,
		buff,
		ERROR_BUFFER_SIZE,
		NULL
		);

	_stprintf_s(errMsg, errMsgSize, _T("%s\n"),
		len ? buff : _T("Error message not found."));
}