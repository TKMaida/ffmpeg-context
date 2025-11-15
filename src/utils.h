#pragma once

#include<windows.h>
#include<tchar.h>
#include<stdarg.h>

#define BUFFSIZE (512)

TCHAR* formatString(const TCHAR* format, ...);
