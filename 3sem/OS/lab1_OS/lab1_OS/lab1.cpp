#include <stdlib.h>

#include <math.h>

#include <tchar.h>

#include <Windows.h>

#include <stdbool.h>
#include <cstdio>

#define MAX_THREADS 10

#define MAX_BUFFER 100

#define BUFSIZE 32

DWORD WINAPI ThreadFunction3(LPVOID lpParam);

double data1[MAX_BUFFER];

void Example3()

{

	HANDLE hThreadArray[MAX_THREADS];

	DWORD dwThreadIdArray[MAX_THREADS];

	for (int i = 0; i < MAX_BUFFER; i++)

	{

		data1[i] = i;

	}

	for (int i = 0; i < MAX_THREADS; i++)

	{

		hThreadArray[i] = CreateThread(NULL,

			0,

			ThreadFunction3,

			i,

			NULL,

			&dwThreadIdArray[i]);

	}

	WaitForMultipleObjects(MAX_THREADS, hThreadArray, TRUE, INFINITE);

	for (int i = 0; i < MAX_THREADS; i++) CloseHandle(hThreadArray[i]);

	for (int i = (MAX_BUFFER) / (MAX_THREADS); i < MAX_BUFFER; i += (MAX_BUFFER) / (MAX_THREADS))

	{

		data1[0] += data1[i];

	}

	printf("%f\n", data1[0]);

}

DWORD WINAPI ThreadFunction3(LPVOID lpParam)

{

	int length = (MAX_BUFFER) / (MAX_THREADS);

	int myNumber = (int)lpParam;

	int firstIndex = myNumber * length;

	for (int i = firstIndex + 1; i < firstIndex + length; i += 1)

	{

		data1[firstIndex] += data1[i];

	}

	return myNumber;

}

void StdinToStdout()

{

	//HANDLE fileOut = CreateFile("NewFile.txt", NULL, FILE_SHARE_WRITE, CREATE_NEW, FILE_ATTRIBUTE_NORMAL, FILE_FLAG_RANDOM_ACCESS, SECURITY_ANONYMOUS);

	CHAR chBuf[BUFSIZE];

	DWORD dwRead, dwWritten;

	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE), hStdout = GetStdHan - dle(STD_OUTPUT_HANDLE);

	BOOL bSuccess;

	for (;;)

	{

		bSuccess = ReadFile(hStdin, chBuf, BUFSIZE, &dwRead, NULL);

		if (!bSuccess || dwRead == 0)

			break;

		bSuccess = WriteFile(hStdout, chBuf, dwRead, &dwWritten, NULL);

		if (!bSuccess)

			break;

	}

	//DeleteFile("NewFile.txt");

	//if (!CopyFile2("NewFile.txt", "NewFile2.txt", true)) {

	// printf("Can't copy file, last error == %d\n", GetLastError());

	//}

}

void calc() {

	PROCESS_INFORMATION ProcessInfo; //This is what we get as an [out] parameter

	ZeroMemory(&ProcessInfo, sizeof(PROCESS_INFORMATION));

	STARTUPINFO StartupInfo; //This is an [in] parameter

	TCHAR lpszClientPath[] = L"calc";

	ZeroMemory(&StartupInfo, sizeof(StartupInfo));

	StartupInfo.cb = sizeof(STARTUPINFO); //Only compulsory field

	bool process = CreateProcess(L"C:\\Windows\\System32\\calc.exe", //NULL

		NULL, //lpszClientPath,

		NULL, NULL, true,

		CREATE_NEW_CONSOLE,// CREATE_NEW_CONSOLE|CREATE_SUSPENDED

		NULL, NULL,

		&StartupInfo,

		&ProcessInfo);

	CloseHandle(ProcessInfo.hThread);

	CloseHandle(ProcessInfo.hProcess);

	ExitProcess(1);

}

int main()

{

	printf("Do you want to use a calculator? (y/n)");

	char choice = getchar();

	Sleep(2000);

	if (choice == 'y') { //launch "Calculator" and exit

		calc();

	}

	else if (choice == 'n') { //print sum of numbers from 0 to 100

		Example3();

	}

	else {

		StdinToStdout(); //read Stdin and write Stdout

	}

	system("pause");

	return 0;
}