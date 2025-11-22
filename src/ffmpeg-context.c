#define WIN32_LEAN_AND_MEAN
#include<stdio.h>
#include <tchar.h>

#include "reg_utils.h"
#include "logging.h"
#include "op_result.h"


int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hInstPrev, PSTR cmdline, int cmdshow)
{

	OpResult regUpdated = UpdateRegistry();
	if (!regUpdated.msg) 
	{ 
		int messageBox = MessageBox(
			NULL,
			_T("Error displaying status!"),
			_T("Error!"),
			MB_OK | MB_ICONERROR
		);
		return -1;
	}

	switch (regUpdated.code)
	{
		case ERROR_ACCESS_DENIED: 
		{
			int messageBox = MessageBox(
				NULL,
				regUpdated.msg,
				_T("Access denied!"),
				MB_OK | MB_ICONERROR
			);
		} break;

#ifdef _DEBUG
		case ERROR_SUCCESS:
		{
			int messageBox = MessageBox(
				NULL,
				regUpdated.msg,
				_T("Success!"),
				MB_OK | MB_ICONINFORMATION
			);
		} break;
#endif

		default:
		{
			int messageBox = MessageBox(
				NULL,
				regUpdated.msg,
				_T("Error!"),
				MB_OK | MB_ICONERROR
			);
		} break;
	}
	return 0;
}