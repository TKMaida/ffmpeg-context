#define WIN32_LEAN_AND_MEAN
#include<reg_utils.h>
#include<logging.h>
#include<stdio.h>
#include<op_result.h>
#include <tchar.h>


int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
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
	else
	{
		int messageBox = MessageBox(
			NULL,
			_T("Successfully updated registry!"),
			_T("Success!"),
			MB_OK | MB_ICONINFORMATION
		);
	}

	getchar();
	return 0;
}