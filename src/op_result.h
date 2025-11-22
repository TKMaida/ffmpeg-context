#pragma once

#include <windows.h>

#define OP_RESULT_MSG_SIZE 256
typedef struct {
	LONG code;
	TCHAR msg[OP_RESULT_MSG_SIZE];
} OpResult;

