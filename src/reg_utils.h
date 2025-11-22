#pragma once

#include <windows.h>
#include <stdbool.h>
#include <op_result.h>

#define PROGRAM_REG_KEY _T("*\\shell\\Re-Encode with FFMPEG")
#define PROGRAM_REG_KEY_COMMAND _T("*\\shell\\Re-Encode with FFMPEG\\command")

LSTATUS RegKeyExists(HKEY hKeyRoot, LPCTSTR lpSubKey);

LSTATUS CreateRegKey(HKEY hKeyRoot, LPCTSTR lpSubKey);

OpResult UpdateRegistry();


