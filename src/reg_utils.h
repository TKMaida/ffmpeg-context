#ifndef REG_UTILS_H
#define REG_UTILS_H

#include <windows.h>
#include <stdbool.h>

#define PROGRAM_REG_KEY "*\\shell\\Re-Encode with FFMPEG"
#define PROGRAM_REG_KEY_COMMAND "*\\shell\\Re-Encode with FFMPEG\\command"

LSTATUS RegKeyExists(HKEY hKeyRoot, LPCTSTR lpSubKey);

LSTATUS CreateRegKey(HKEY hKeyRoot, LPCTSTR lpSubKey);

LSTATUS UpdateRegistry();

#endif

