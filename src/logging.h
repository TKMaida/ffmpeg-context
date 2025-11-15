#pragma once

#include <windows.h>
#include <stdio.h>

void PrintErrorMessage(LONG errorCode);
const TCHAR* GetErrorMessage(LONG errorCode);