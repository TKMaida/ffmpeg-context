#pragma once

#include <windows.h>
#include <stdio.h>

#define ERROR_BUFFER_SIZE 256
void PrintErrorMessage(LONG errorCode);
void GetSystemMessage(LONG code, TCHAR errMsg[], size_t errMsgSize);