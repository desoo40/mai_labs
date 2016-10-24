#include <stdio.h>
#include <tchar.h>
#include <Windows.h>
#include <stdbool.h>

int _tmain(int argc, _TCHAR* argv[])
{
	SECURITY_ATTRIBUTES sa;
	sa.nLength = sizeof(SECURITY_ATTRIBUTES);
	sa.lpSecurityDescriptor = NULL;
	sa.bInheritHandle = TRUE;

	PROCESS_INFORMATION ProcessInfo; //This is what we get as an [out] parameter
	ZeroMemory(&ProcessInfo, sizeof(PROCESS_INFORMATION));
	STARTUPINFO StartupInfo; //This is an [in] parameter

	TCHAR lpszClientPath[] = L"child1.txt";
	ZeroMemory(&StartupInfo, sizeof(StartupInfo));
	StartupInfo.cb = sizeof(STARTUPINFO); //Only compulsory field

	HANDLE pipe1Read, pipe1Write;
	CreatePipe(&pipe1Read, &pipe1Write, &sa, 0);
	StartupInfo.dwFlags = STARTF_USESTDHANDLES;
	StartupInfo.hStdInput = pipe1Read;

	DeleteFile(L"child.txt");

	HANDLE hFile = CreateFile(
		L"child.txt",            // name of the write
		GENERIC_WRITE,          // open for writing
		0,                      // do not share
		NULL,                   // default security
		CREATE_NEW,             // create new file only
		FILE_ATTRIBUTE_NORMAL,  // normal file
		NULL);                  // no attr. template

	if (hFile == INVALID_HANDLE_VALUE)
	{
		_tprintf(TEXT("Terminal failure: Unable to open file \"%s\" for write.\n"), L"child.txt");
		return;
	}

	StartupInfo.hStdOutput = hFile;

	bool process = CreateProcess(L"child.exe",
		lpszClientPath,
		NULL, NULL, true,
		CREATE_NO_WINDOW,// CREATE_NEW_CONSOLE|CREATE_SUSPENDED
		NULL, NULL,
		&StartupInfo,
		&ProcessInfo);
	
	DWORD writeBytes;
	char x = 'y';
	WriteFile(pipe1Write, &x, sizeof(char), &writeBytes, NULL);

	CloseHandle(pipe1Read);
	CloseHandle(pipe1Write);
	CloseHandle(hFile);

	CloseHandle(ProcessInfo.hThread);
	CloseHandle(ProcessInfo.hProcess);

	return 0;
}

