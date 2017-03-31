#ifndef _MAPPING_H_
#define _MAPPING_H_

#include <windows.h>
#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

#define SIZE_OF_FILE_NAME 128

class FileMapping {
    HANDLE hFile;
    HANDLE hMapping;
    bool isOpened;
    size_t fSize;
    unsigned char* fPtr;
    WCHAR *fName;

public:
    FileMapping();
    void Open_File(WCHAR*);
    void Close_File();
    void Delete_File();
    void ShowDiapasone(size_t, size_t);
    void WriteToFile(size_t, string);
    void DeleteFromFile(size_t, size_t);
    unsigned long long ControlSum();
    void FindPatter(string);
    void currD();
	size_t Size();
};

#endif