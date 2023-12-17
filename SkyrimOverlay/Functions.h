#ifndef FUNCTIONS
#define FUNCTIONS

#define _CRT_SECURE_NO_WARNINGS

#include <Windows.h>
#include "Overlay.h"
#include <time.h>

namespace ProcessFunctions
{
	HANDLE GetHandle();
	
}

wchar_t* convertCharArrayToLPCWSTR(const char* charArray);
char* convertStringToCharArray(std::string string);
long long GetWorldAddress();
long long GetGNameAddress();

#endif


