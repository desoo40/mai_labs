// Server.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>

int _tmain(int argc, _TCHAR* argv[])
{
	/*DWORD mode;
	bool re = GetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), &mode);
	bool res = SetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), 0);
	GetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), &mode);*/
	HANDLE inH = GetStdHandle(STD_INPUT_HANDLE);
	HANDLE outH = GetStdHandle(STD_OUTPUT_HANDLE);
	double x;
	DWORD readBytes, writeBytes;
	if (!ReadFile(inH, &x, sizeof(double), &readBytes, NULL))
		return -1;
	x *= 2;
	if (!WriteFile(outH, &x, sizeof(double), &writeBytes, NULL))
		return -2;
	return 0;
}

