#include <logging.h>
#include <tchar.h>

void PrintErrorMessage(LONG errorCode)
{
	LPTSTR errorMsg = NULL;
	if (!FormatMessage(
		FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_ALLOCATE_BUFFER,
		NULL,
		errorCode,
		0,
		(LPTSTR)&errorMsg,
		0,
		NULL
	))
	{
		printf("Format message failed with 0x%x\n", GetLastError());
	}

	_tprintf(L"ERROR: %s", errorMsg);

}
