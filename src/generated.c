#define WIN32_LEAN_AND_MEAN
#include<reg_utils.h>
#include<logging.h>
#include<stdio.h>
#include<op_result.h>
#include <tchar.h>

int main(int argc, char** argv)
{

	OpResult regUpdated = UpdateRegistry();
	if (!regUpdated.msg) 
	{ 
		_tprintf(_T("Error displaying status.")); 
	}
	else
	{
		_tprintf(regUpdated.msg);
	}

	getchar();
	return 0;
}