#include <stdio.h>
#include <tchar.h>
#include <Windows.h>
#include <stdbool.h>

void ErrorMsg() {
    DWORD dw = GetLastError();
    printf_s("Can't create a procces! Cause of Error: %lu", dw);
}

int _tmain(int argc, _TCHAR* argv[])
{
	SECURITY_ATTRIBUTES sa;
	sa.nLength = sizeof(SECURITY_ATTRIBUTES);
	sa.lpSecurityDescriptor = NULL;
	sa.bInheritHandle = TRUE;

    int n = 0;
    scanf_s("%d", &n);
	getchar();

    for (int i = 0; i < n; ++i) {
        PROCESS_INFORMATION ProcessInfo; //This is what we get as an [out] parameter
        ZeroMemory(&ProcessInfo, sizeof(PROCESS_INFORMATION));
        STARTUPINFO StartupInfo; //This is an [in] parameter

        ZeroMemory(&StartupInfo, sizeof(StartupInfo));
        StartupInfo.cb = sizeof(STARTUPINFO); //Only compulsory field

        HANDLE pipe1Read, pipe1Write;

        if (!CreatePipe(&pipe1Read, &pipe1Write, &sa, 0)) {
            ErrorMsg();
        }

        StartupInfo.dwFlags = STARTF_USESTDHANDLES;
        StartupInfo.hStdInput = pipe1Read;

        TCHAR lpszClientPath[] = L"         .txt";
		int tmp = i;
		for (int d = 8; (tmp / 10 || tmp < 10) && d >= 0; --d)
		{
			lpszClientPath[d] = ((tmp % 10) + 48);
			tmp /= 10;
		}

        bool process = CreateProcess(L"child.exe",
            lpszClientPath,
            NULL, NULL, true,
            CREATE_NO_WINDOW,// CREATE_NEW_CONSOLE|CREATE_SUSPENDED
            NULL, NULL,
            &StartupInfo,
            &ProcessInfo);

        if (!process) {
            ErrorMsg();
        }

        char c;

        while ((c = getchar()) != '\n') {
            DWORD writeBytes;
            WriteFile(pipe1Write, &c, sizeof(char), &writeBytes, NULL);
        }

        if (c == '\n') {
            DWORD writeBytes;
            WriteFile(pipe1Write, &c, sizeof(char), &writeBytes, NULL);
        }

        CloseHandle(pipe1Read);
        CloseHandle(pipe1Write);

        CloseHandle(ProcessInfo.hThread);
        CloseHandle(ProcessInfo.hProcess);
    }
    
	return 0;
}

