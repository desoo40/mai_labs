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
};

FileMapping::FileMapping() {
    hFile = nullptr;
    hMapping = nullptr;
    isOpened = false;
    fSize = 0;
    fPtr = nullptr;
    fName = (WCHAR*)malloc(sizeof(WCHAR*) * SIZE_OF_FILE_NAME);
}

void FileMapping::Open_File(WCHAR * fileName) {
    if (isOpened) 
        Close_File();

    fName = fileName;

    SECURITY_ATTRIBUTES security_attributes;
    security_attributes.nLength = sizeof(security_attributes);
    security_attributes.lpSecurityDescriptor = NULL;
    security_attributes.bInheritHandle = TRUE;

    hFile = CreateFile(fName,
        GENERIC_WRITE | GENERIC_READ | GENERIC_EXECUTE,
        FILE_SHARE_WRITE | FILE_SHARE_READ,
        &security_attributes,
        OPEN_ALWAYS,
        FILE_ATTRIBUTE_NORMAL,
        NULL
    );

    if (hFile == INVALID_HANDLE_VALUE) {
        cerr << "Can't create file. Error: " << GetLastError() << endl;
        return;
    }

    SetFilePointer(hFile, 0, nullptr, FILE_BEGIN);
    fSize = GetFileSize(hFile, nullptr);

    if ((DWORD)fSize == INVALID_FILE_SIZE) {
        cerr << "Get size of file. Error: " << GetLastError() << endl;
        CloseHandle(hFile);
        return;
    }

    hMapping = CreateFileMapping(hFile,
        &security_attributes,
        PAGE_EXECUTE_READWRITE,
        0,
        0,
        L"map");

    if (hMapping == INVALID_HANDLE_VALUE) {
        cerr << "Can't create file mapping. Error: " << GetLastError() << endl;
        CloseHandle(hFile);
        return;
    }

    fPtr = (unsigned char *)MapViewOfFile(hMapping,
        FILE_MAP_ALL_ACCESS,
        0,
        0,
        this->fSize
    );

    isOpened = true;
   
    cout << "File opened and mapped" << endl;
}

void FileMapping::Close_File() {
    UnmapViewOfFile(fPtr);
    fPtr = nullptr;
    CloseHandle(hMapping);
    CloseHandle(hFile);
    isOpened = false;
    cout << "File closed" << endl;
}

void FileMapping::Delete_File() {
    CloseHandle(hMapping);
    CloseHandle(hFile);
    isOpened = false;
    if (!DeleteFile(fName)) {
        cerr << "Can't delete file. Error: " << GetLastError() << endl;
        return;
    }
    free(fName);
    cout << "File Deleted" << endl;
}

void FileMapping::ShowDiapasone(size_t from, size_t to) {
    if (!isOpened) {
        cerr << "File is not open." << endl;
        return;
    }
    for (size_t i = from - 1; i < to; i++)
        cout << fPtr[i];

    cout << endl;
}

void FileMapping::WriteToFile(size_t position, string input) {
    if (!isOpened) {
        cerr << "File is not open." << endl;
        return;
    }

    if (position > fSize || position < 0) {
        cerr << "Position is out of the file range" << endl;
        return;
    }

    SECURITY_ATTRIBUTES security_attributes;
    security_attributes.nLength = sizeof(security_attributes);
    security_attributes.lpSecurityDescriptor = NULL;
    security_attributes.bInheritHandle = TRUE;

    HANDLE tmpFile = CreateFile(L"tmp",
        GENERIC_WRITE | GENERIC_READ | GENERIC_EXECUTE,
        FILE_SHARE_WRITE | FILE_SHARE_READ,
        &security_attributes,
        OPEN_ALWAYS,
        FILE_ATTRIBUTE_NORMAL,
        NULL
    );

    DWORD WriteBytes;
    SetFilePointer(hFile, 0, NULL, FILE_BEGIN);

    for(size_t i = 0; i < position; ++i) 
        WriteFile(tmpFile, &(fPtr[i]), sizeof(char), &WriteBytes, nullptr);

    for(size_t k = 0; k < input.size(); ++k)
        WriteFile(tmpFile, &(input[k]), sizeof(char), &WriteBytes, nullptr);

    for(size_t j = position; j < fSize; ++j)
        WriteFile(tmpFile, &(fPtr[j]), sizeof(char), &WriteBytes, NULL);

    UnmapViewOfFile(fPtr);
    CloseHandle(hMapping);
    CloseHandle(hFile);
    CloseHandle(tmpFile);

    if (!DeleteFile(fName)) 
        cout << "Deleting failed. Error: " << GetLastError() << endl;
    
    if (!MoveFile(L"tmp", fName))
        cout << "Renaming failed. Error: " << GetLastError() << endl;
    
    hFile = CreateFile(fName,
        GENERIC_WRITE | GENERIC_READ | GENERIC_EXECUTE,
        FILE_SHARE_WRITE | FILE_SHARE_READ,
        &security_attributes,
        OPEN_ALWAYS,
        FILE_ATTRIBUTE_NORMAL,
        NULL
    );

    SetFilePointer(this->hFile, 0, NULL, FILE_BEGIN);

    hMapping = CreateFileMapping(this->hFile,
        &security_attributes,
        PAGE_EXECUTE_READWRITE,
        0,
        0,
        L"map"
    );

    if (hMapping == INVALID_HANDLE_VALUE) {
        cerr << "Can't create file mapping. Error: " << GetLastError() << endl;
        CloseHandle(this->hFile);
        return;
    }

    fPtr = (unsigned char *)MapViewOfFile(this->hMapping,
        FILE_MAP_ALL_ACCESS,
        0,
        0,
        fSize
    );
    
    cout << "Symbols written" << endl;
}


int main()
{
    FileMapping *map = new FileMapping();

    SYSTEM_INFO sysinfo = { 0 };
    GetSystemInfo(&sysinfo);
    DWORD cbView = sysinfo.dwAllocationGranularity;

    while(1) {
        int c = 0;

        cin >> c;

        if (c == 1) {
            WCHAR *name = (WCHAR*)malloc(sizeof(WCHAR*) * SIZE_OF_FILE_NAME);
            wcin >> name;
            map->Open_File(name);
        }

        if (c == 2) {
            map->Close_File();
        }

        if (c == 3)
            map->Delete_File();

        if (c == 4) {
            int a, b = 0;
            cout << "Enter diapasone:" << endl;
            cout << "From:" << endl;
            cin >> a;
            cout << "To:" << endl;
            cin >> b;

            if (a > b) 
                cerr << "\"to\" must be greater then \"from\"" << endl;
            
            if (a <= 0 || b <= 0)
                cerr << "This values must be positive!" << endl;
            
            map->ShowDiapasone(a, b);
        }

        if (c == 5) {
            int a = 0;
            string s;

            cin >> a;
            cin >> s;
            map->WriteToFile(a, s);
        }
    }

}