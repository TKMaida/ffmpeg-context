#define WIN32_LEAN_AND_MEAN
//#include<reg_utils.h>
#include "logging.h"
#include<stdio.h>
#include "op_result.h"
#include <tchar.h>


int APIENTRY WinMain(HINSTANCE hInst, HINSTANCE hInstPrev, PSTR cmdline, int cmdshow)
{
	TCHAR buff[512] = { 0 };

	/*TCHAR sysMsg[256];
	DWORD n = FormatMessage(
		FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
		NULL,
		ERROR_FILE_NOT_FOUND,
		0,
		sysMsg,
		256,
		NULL
	);*/

	GetSystemMessage(ERROR_FILE_NOT_FOUND, buff, 512);
	int messageBox = MessageBox(
		NULL,
		buff,
		_T("sfkasdf"),
		MB_OK | MB_ICONINFORMATION
	);

	/*OpResult regUpdated = UpdateRegistry();
	if (!regUpdated.msg) 
	{ 

		GetSystemMessage(ERROR_FILE_NOT_FOUND, buff);
		int messageBox = MessageBox(
			NULL,
			_T("Error displaying status!"),
			_T("Error!"),
			MB_OK | MB_ICONERROR
		);

	}
	else
	{
		int messageBox = MessageBox(
			NULL,
			_T("Successfully updated registry!"),
			_T("Success!"),
			MB_OK | MB_ICONINFORMATION
		);
	}*/


	return 0;
}