#define WIN32_LEAN_AND_MEAN

#include<stdio.h>
#include <tchar.h>

#include "op_result.h"
#include "logging.h"
#include "reg_utils.h"


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
	}

#ifdef _DEBUG

	else
	{
		int messageBox = MessageBox(
			NULL,
			_T("Successfully updated registry!"),
			_T("Success!"),
			MB_OK | MB_ICONINFORMATION
		);
	}

#endif
	return 0;
}