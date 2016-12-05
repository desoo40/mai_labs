#include <stdio.h>
#include <tchar.h>
#include <Windows.h>

int _tmain(int argc, _TCHAR* argv[])
{
	HANDLE File = CreateFile(
		argv[0],            // name of the write
		GENERIC_WRITE,          // open for writing
		0,                      // do not share
		NULL,                   // default security
        CREATE_ALWAYS,             // create new file ALLWAYS
		FILE_ATTRIBUTE_NORMAL,  // normal file
		NULL);                  // no attr. template

    if (File == INVALID_HANDLE_VALUE)
    {
        _tprintf(TEXT("Terminal failure: Unable to open file \"%s\" for write.\n"), L"log.txt");
        return -1;
    }

	DWORD writeBytes;

	char x;
    while ((x = getchar()) != '\n') {
        WriteFile(File, &x, sizeof(char), &writeBytes, NULL);
    }
    
    CloseHandle(File);
	return 0;
}