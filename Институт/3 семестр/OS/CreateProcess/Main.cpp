#include "stdafx.h"
#include <Windows.h>

int _tmain(int argc, _TCHAR* argv[])
{
	PROCESS_INFORMATION ProcessInfo; //This is what we get as an [out] parameter
	ZeroMemory(&ProcessInfo, sizeof(PROCESS_INFORMATION));
	STARTUPINFO StartupInfo; //This is an [in] parameter
	TCHAR lpszClientPath[] = L"calc";
	ZeroMemory(&StartupInfo, sizeof(StartupInfo));
	StartupInfo.cb = sizeof (STARTUPINFO); //Only compulsory field
	bool process = CreateProcess(L"C:\\Windows\\System32\\calc.exe", //NULL
									NULL, //lpszClientPath,
									NULL, NULL, true, 
									CREATE_NEW_CONSOLE,// CREATE_NEW_CONSOLE|CREATE_SUSPENDED
									NULL, NULL, 
									&StartupInfo, 
									&ProcessInfo);
	CloseHandle(ProcessInfo.hThread);
	CloseHandle(ProcessInfo.hProcess);
	return 0;
}

