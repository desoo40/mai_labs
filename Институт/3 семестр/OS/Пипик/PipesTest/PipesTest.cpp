// PipesTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>

int _tmain(int argc, _TCHAR* argv[])
{
	SECURITY_ATTRIBUTES sa;
	sa.nLength = sizeof(SECURITY_ATTRIBUTES);
	sa.lpSecurityDescriptor = NULL;
	sa.bInheritHandle = TRUE;

	PROCESS_INFORMATION ProcessInfo; //This is what we get as an [out] parameter
	ZeroMemory(&ProcessInfo, sizeof(PROCESS_INFORMATION));
	STARTUPINFO StartupInfo; //This is an [in] parameter
	TCHAR lpszClientPath[] = L"Server";
	ZeroMemory(&StartupInfo, sizeof(StartupInfo));
	StartupInfo.cb = sizeof (STARTUPINFO); //Only compulsory field
	HANDLE pipe1Read, pipe1Write, pipe2Read, pipe2Write;
	CreatePipe(&pipe1Read, &pipe1Write, &sa, 0);
	CreatePipe(&pipe2Read, &pipe2Write, &sa, 0);
	StartupInfo.dwFlags = STARTF_USESTDHANDLES;
	StartupInfo.hStdInput = pipe1Read;
	StartupInfo.hStdOutput = pipe2Write;

	bool process = CreateProcess(NULL,
		lpszClientPath,
		NULL, NULL, true,
		CREATE_NO_WINDOW,// CREATE_NEW_CONSOLE|CREATE_SUSPENDED
		NULL, NULL,
		&StartupInfo,
		&ProcessInfo);
	CloseHandle(pipe1Read);
	CloseHandle(pipe2Write);

	DWORD writeBytes, readBytes;
	double x = 2;
	WriteFile(pipe1Write, &x, sizeof(double), &writeBytes, NULL);
	ReadFile(pipe2Read, &x, sizeof(double), &readBytes, NULL);

	CloseHandle(pipe2Read);
	CloseHandle(pipe1Write);
	CloseHandle(ProcessInfo.hThread);
	CloseHandle(ProcessInfo.hProcess);
	printf("%Lf", x);
	system("pause");
	return 0;
}

