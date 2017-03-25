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
    Close_File();
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
    for (size_t i = from; i <= to; i++)
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
    {
        cout << "Deleting failed. Error: " << GetLastError() << endl;
        return;
    }
    
    if (!MoveFile(L"tmp", fName)) {
        cout << "Renaming failed. Error: " << GetLastError() << endl;
        return;
    }
    
    hFile = CreateFile(fName,
        GENERIC_WRITE | GENERIC_READ | GENERIC_EXECUTE,
        FILE_SHARE_WRITE | FILE_SHARE_READ,
        &security_attributes,
        OPEN_ALWAYS,
        FILE_ATTRIBUTE_NORMAL,
        NULL
    );

    SetFilePointer(hFile, 0, NULL, FILE_BEGIN);

    hMapping = CreateFileMapping(hFile,
        &security_attributes,
        PAGE_EXECUTE_READWRITE,
        0,
        0,
        L"map"
    );

    if (hMapping == INVALID_HANDLE_VALUE) {
        cerr << "Can't create file mapping. Error: " << GetLastError() << endl;
        CloseHandle(hFile);
        return;
    }

    fPtr = (unsigned char *)MapViewOfFile(hMapping,
        FILE_MAP_ALL_ACCESS,
        0,
        0,
        fSize
    );
    
    cout << "Symbols written" << endl;
}

void FileMapping::DeleteFromFile(size_t position, size_t qty) {
    if (!isOpened) {
        cerr << "File is not open" << endl;
        return;
    }

    if (position > fSize || position < 0) {
        cerr << "Position is out of the file range" << endl;
        return;
    }

    if (position + qty > fSize) {
        cerr << "qty of deleted symbol out of file range" << endl;
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

    for (size_t i = 0; i < position; ++i)
        WriteFile(tmpFile, &(fPtr[i]), sizeof(char), &WriteBytes, nullptr);

    for (size_t j = position + qty; j < fSize; ++j)
        WriteFile(tmpFile, &(fPtr[j]), sizeof(char), &WriteBytes, NULL);

    UnmapViewOfFile(fPtr);
    CloseHandle(hMapping);
    CloseHandle(hFile);
    CloseHandle(tmpFile);

    if (!DeleteFile(fName))
    {
        cout << "Deleting failed. Error: " << GetLastError() << endl;
        return;
    }

    if (!MoveFile(L"tmp", fName)) {
        cout << "Renaming failed. Error: " << GetLastError() << endl;
        return;
    }

    hFile = CreateFile(fName,
        GENERIC_WRITE | GENERIC_READ | GENERIC_EXECUTE,
        FILE_SHARE_WRITE | FILE_SHARE_READ,
        &security_attributes,
        OPEN_ALWAYS,
        FILE_ATTRIBUTE_NORMAL,
        NULL
    );

    SetFilePointer(hFile, 0, NULL, FILE_BEGIN);

    hMapping = CreateFileMapping(hFile,
        &security_attributes,
        PAGE_EXECUTE_READWRITE,
        0,
        0,
        L"map"
    );

    if (hMapping == INVALID_HANDLE_VALUE) {
        cerr << "Can't create file mapping. Error: " << GetLastError() << endl;
        CloseHandle(hFile);
        return;
    }

    fPtr = (unsigned char *)MapViewOfFile(hMapping,
        FILE_MAP_ALL_ACCESS,
        0,
        0,
        fSize
    );

    cout << "Symbols deleted" << endl;
}

unsigned long long FileMapping::ControlSum() {
    unsigned long long sum = 0;
    for(size_t i = 0; i < fSize; ++i)
        sum += (unsigned long long) fPtr[i];
    
    return sum;
}

void FileMapping::FindPatter(string pattern) {
    if (!isOpened) {
        cerr << "File is not open." << endl;
        return;
    }

    if (pattern.size() > fSize) {
        cerr << "Pattern can't be bigger then file" << endl;
        return;
    }

    size_t lines = 1;
    size_t sym = 1;

    for (size_t i = 0; i < fSize; ++i, ++sym) {
       if (fPtr[i] == '\n') {
           ++lines;
           sym = 1;
       }

        if (fPtr[i] == pattern[0]) {
            bool found = true;
            for(size_t j = 0; j < pattern.size(); ++j) {
                if (!(fPtr[i + j] == pattern[j]))
                {
                    found = false;
                    break;
                }
            }
            if (found)
                cout << "Pattern found in " << lines << " line " << sym << " symbol" << endl;
        }
    }
}

void hints() {
    cout << "-----------------------------" << endl;
    cout << "1 - Open file"                 << endl;
    cout << "2 - Close file"                << endl;
    cout << "3 - Delete file"               << endl;
    cout << "4 - Display range in file"     << endl;
    cout << "5 - Write symbols to file"     << endl;
    cout << "6 - Delete symbols from file"  << endl;
    cout << "7 - Control sum"               << endl;
    cout << "8 - Find pattern"              << endl;
    cout << "0 - End"                       << endl;
    cout << "-----------------------------" << endl;
}

int main()
{
    FileMapping *map = new FileMapping();

    SYSTEM_INFO sysinfo = { 0 };
    GetSystemInfo(&sysinfo);
    DWORD cbView = sysinfo.dwAllocationGranularity;

    while(1) {
        int c = 0;
        hints();

        cin >> c;


        if (c == 1) {
            cout << "Enter name of file: ";
            WCHAR *name = (WCHAR*)malloc(sizeof(WCHAR*) * SIZE_OF_FILE_NAME);
            wcin >> name;
            map->Open_File(name);
        }

        if (c == 2) 
            map->Close_File();
        

        if (c == 3)
            map->Delete_File();

        if (c == 4) {
            int a, b = 0;
            cout << "Enter range:" << endl;
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

            size_t a = 0;
            string s;
            cout << "Enter position:" << endl;

            cin >> a;
            cout << "Enter symbols to write:" << endl;

            cin >> s;
            map->WriteToFile(a, s);
        }

        if (c == 6) {
            int a, s = 0;
            
            cout << "Enter position:" << endl;
            cin >> a;
            cout << "Enter qty of symbols to Delete:" << endl;
            cin >> s;
            map->DeleteFromFile(a, s);
        }

        if (c == 7) {
            cout << map->ControlSum() << endl;
        }
        if (c == 8) {
            string s = "";
            cout << "Enter pattern:" << endl;
            cin >> s;

            map->FindPatter(s);
        }
        cout << "-----------------------------" << endl;

    }

}