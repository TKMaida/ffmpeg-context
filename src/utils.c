#include <windows.h>
#include <tchar.h>
#include <stdarg.h>
#include <stdlib.h>

#define BUFFSIZE 512

TCHAR* formatString(const TCHAR* format, ...) {
    if (!format) return NULL;

    va_list args;
    va_start(args, format);
    int len = _vsctprintf(format, args);
    va_end(args);

    if (len <= 0) len = 1;

    TCHAR* buffer = (TCHAR*)malloc((len + 1) * sizeof(TCHAR));
    if (!buffer) return NULL;

    va_start(args, format);
    _vsntprintf_s(buffer, len + 1, _TRUNCATE, format, args);
    va_end(args);

    return buffer;
}