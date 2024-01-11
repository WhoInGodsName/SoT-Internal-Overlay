#include "Functions.h"
#include <TlHelp32.h>
#include <stdio.h>
#include <string>
#include <windows.h>
#include <iostream>
#include "modulemgr.h"
#include "engine.h"


HANDLE ProcessFunctions::GetHandle()
{
	pHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
	return pHandle;
}

wchar_t* convertCharArrayToLPCWSTR(const char* charArray)
{
    wchar_t* wString = new wchar_t[4096];
    MultiByteToWideChar(CP_ACP, 0, charArray, -1, wString, 4096);
    return wString;
}

char* convertStringToCharArray(std::string string) {
    const int length = string.length();
    char* char_array = new char[length + 1];
    strcpy(char_array, string.c_str());
    return char_array;

}

wchar_t* convertStringToLPCWSTR(std::string string) {
	return convertCharArrayToLPCWSTR(convertStringToCharArray(string));
}

MODULEINFO GetModuleInfo(const char* szModule)
{
	MODULEINFO modinfo = { 0 };
	HMODULE hModule = GetModuleHandle(convertCharArrayToLPCWSTR(szModule));
	if (hModule == 0)
		return modinfo;
	GetModuleInformation(GetCurrentProcess(), hModule, &modinfo, sizeof(MODULEINFO));
	return modinfo;
}

uintptr_t FindPattern(const char* module, const char* pattern, const char* mask)
{
	//Get all module related information
	MODULEINFO mInfo = GetModuleInfo(module);

	//Assign our base and module size
	//Having the values right is ESSENTIAL, this makes sure
	//that we don't scan unwanted memory and leading our game to crash
	uintptr_t base = (uintptr_t)mInfo.lpBaseOfDll;
	DWORD size = (DWORD)mInfo.SizeOfImage;

	//Get length for our mask, this will allow us to loop through our array
	DWORD patternLength = (DWORD)strlen(mask);

	for (DWORD i = 0; i < size - patternLength; i++)
	{
		bool found = true;
		for (DWORD j = 0; j < patternLength; j++)
		{
			//if we have a ? in our mask then we have true by default, 
			//or if the bytes match then we keep searching until finding it or not
			found &= mask[j] == '?' || pattern[j] == *(char*)(base + i + j);
		}

		//found = true, our entire pattern was found
		//return the memory addy so we can write to it
		if (found)
		{
			return base + i;
		}
	}

	return NULL;
}

long long GetWorldAddress() {
	uintptr_t moduleBase = (uintptr_t)GetModuleHandle(L"SoTGame.exe");
	uintptr_t worldBase = FindPattern("SoTGame.exe", "\x48\x8B\x05\x00\x00\x00\x00\x48\x8B\x88\x00\x00\x00\x00\x48\x85\xC9\x74\x06\x48\x8B\x49\x70", "xxx????xxx????xxxxxxxxx");
	uintptr_t worldOffset = *(UINT*)(worldBase + 3);
	uintptr_t uWorld = worldBase + worldOffset + 7;

	return (long long)uWorld;
}

long long GetGNameAddress() {
	uintptr_t moduleBase = (uintptr_t)GetModuleHandle(L"SoTGame.exe");
	uintptr_t gNameBase = FindPattern("SoTGame.exe", "\x48\x8B\x1D\x00\x00\x00\x00\x48\x85\xDB\x75\x00\xB9\x08\x04\x00\x00", "xxx????xxxx?xxxxx");
	uintptr_t gNameOffset = *(UINT*)(gNameBase + 3);
	uintptr_t uGName = gNameBase + gNameOffset + 7;

	return (long long)uGName;

}



/*
void GetWindowSize() {
	RECT rect;
	HWND hwnd = FindWindow(NULL, L"SoTGame.exe");
	if (GetWindowRect(hwnd, &rect))
	{
		SOT_WINDOW_W = rect.right - rect.left;
		SOT_WINDOW_H = rect.bottom - rect.top;
	}
}*/

