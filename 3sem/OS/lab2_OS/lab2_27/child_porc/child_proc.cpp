
#include <stdio.h>
#include <tchar.h>
#include <Windows.h>
#include <stdbool.h>

int _tmain(int argc, _TCHAR* argv[])
{
	/*DWORD mode;
	bool re = GetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), &mode);
	bool res = SetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), 0);
	GetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), &mode);*/
	DeleteFile(L"log.txt");

	HANDLE logFile = CreateFile(
		L"log.txt",            // name of the write
		GENERIC_WRITE,          // open for writing
		0,                      // do not share
		NULL,                   // default security
		CREATE_NEW,             // create new file only
		FILE_ATTRIBUTE_NORMAL,  // normal file
		NULL);                  // no attr. template

	HANDLE File = CreateFile(
		argv[1],            // name of the write
		GENERIC_WRITE,          // open for writing
		0,                      // do not share
		NULL,                   // default security
		CREATE_NEW,             // create new file only
		FILE_ATTRIBUTE_NORMAL,  // normal file
		NULL);                  // no attr. template

	HANDLE inH = GetStdHandle(STD_INPUT_HANDLE);
	HANDLE outH = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD write, readBytes, writeBytes;

	WriteFile(logFile, L"hello", sizeof(L"hello"), &write, NULL);

	char x;

	if (!ReadFile(inH, &x, sizeof(char), &readBytes, NULL))
	{
		WriteFile(logFile, L"read\n", sizeof(L"read\n"), &write, NULL);
		CloseHandle(logFile);
		return -1;
	}

	if (!WriteFile(outH, &x, sizeof(char), &writeBytes, NULL))
	{
		WriteFile(logFile, L"write\n", sizeof(L"write\n"), &write, NULL);
		WriteFile(logFile, &x, sizeof(char), &writeBytes, NULL);
		CloseHandle(logFile);
		return -2;
	}

	WriteFile(logFile, L"correct\n", sizeof(L"correct\n"), &write, NULL);
	CloseHandle(logFile);
	return 0;
}