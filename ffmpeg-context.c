#define WIN32_LEAN_AND_MEAN
#include<reg_utils.h>
#include<logging.h>
#include<stdio.h>


int main(int argc, char** argv)
{
	LSTATUS regUpdated = UpdateRegistry();

	getchar();
	return 0;
}