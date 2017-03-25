//#define _CRT_SECURE_NO_WARNINGS
//
//#include <windows.h>
//#include <iostream>
//#include <cstdio>
//#include <cstring>
//#include <stddef.h>
//#include <stdint.h>
//
//#define SIZE_OF_FILE_NAME 1024
//
//
//struct FileMapping {
//	HANDLE hFile;
//	HANDLE hMapping;
//	size_t fsize;
//	unsigned char* dataPtr;
//	WCHAR *fName;
//};
//
//FileMapping* fileMappingCreate(const char *fname);
//bool findStingNumberX(FileMapping *fm, DWORD cbView, const unsigned long long fileSize, int stringNumber);
//bool findPattern(FileMapping *fm, DWORD cbView, const unsigned long long fileSize, char * pattern);
//bool findPatternNoRegister(FileMapping *fm, DWORD cbView, const unsigned long long fileSize, char * pattern);
//unsigned long  crc(const char *buf, size_t len);
//unsigned long findCRC(FileMapping *fm, DWORD cbView, const unsigned long long fileSize);
//bool record(FileMapping *fm, DWORD cbView, const unsigned long long fileSize, const unsigned long long position, char *text);
//bool remove(FileMapping *fm, DWORD cbView, const unsigned long long fileSize,  unsigned long long position,  unsigned long long qnty);
//
//
//int main() {
//	char *fileName = (char *)malloc(SIZE_OF_FILE_NAME * sizeof(char)), 
//		 *result = (char *)malloc(SIZE_OF_FILE_NAME * sizeof(char));
//	printf("Enter file name\n");
//	scanf("%s", fileName);
//	fileName = "tests.txt";
//	FileMapping *map = fileMappingCreate(fileName);
//	LARGE_INTEGER file_size = { 0 };
//	GetFileSizeEx(map->hFile, &file_size);
//	unsigned long long fileSize = static_cast<unsigned long long>(file_size.QuadPart);
//	SYSTEM_INFO sysinfo = { 0 };
//	GetSystemInfo(&sysinfo);
//	DWORD cbView = sysinfo.dwAllocationGranularity;
//	short int choice;
//	unsigned long long strNum, patSize, index;
//	char * pattern = (char *)malloc(1);
//	printf("******************************\n 1 to find string with your number\n 2 to find pattern\n 3 to find pattern not case sensitive\n 4 to find control sum\n 5 to record\n 6 to remove\n 7 to change file\n 8 to help - 1 to quit\n******************************\n");
//
//	while (true) {
//		printf("Enter your choice\n");
//		scanf("%d", &choice);
//		switch (choice) {
//		case 1:
//			printf("Enter sting number\n");
//			scanf("%llu", &strNum);
//			findStingNumberX(map, cbView, fileSize, strNum);
//			break;
//		case 2:
//			printf("Enter your pattern size\n");
//			scanf("%llu", &patSize);
//			pattern = (char *)realloc(pattern, patSize + 1);
//			printf("Enter your pattern\n");
//			scanf("%s", pattern);
//			if (!findPattern(map, cbView, fileSize, pattern)) {
//				printf("404 Not found :(\n");
//			}
//			break;
//		case 3:
//			printf("Enter pattern size\n");
//			scanf("%llu", &patSize);
//			pattern = (char *)realloc(pattern, patSize);
//			printf("Enter your pattern\n");
//			scanf("%s", pattern);
//			if (!findPatternNoRegister(map, cbView, fileSize, pattern)) {
//				printf("404 Not found :(((\n");
//			}
//			break;
//		case 4:
//			printf("%u\n", findCRC(map, cbView, fileSize));
//			break;
//		case 5:
//			printf("Enter inserted text size\n");
//			scanf("%llu", &patSize);
//			pattern = (char *)realloc(pattern, patSize);
//			printf("Enter your text\n");
//			scanf("%s", pattern);
//			printf("Enter the number of last element before the string\n");
//			scanf("%llu", &index);
//			record(map, cbView, fileSize, index, pattern);
//			break;
//		case 6:
//			printf("Enter the number of last element before the string\n");
//			scanf("%llu", &index);
//			printf("Enter size of deleted space\n");
//			scanf("%llu", &patSize);
//			remove(map, cbView, fileSize, index, patSize);
//			break;
//		case 7:
//			CloseHandle(map->hFile);
//			CloseHandle(map->hMapping);
//			printf("Enter file name\n");
//			scanf("%s", fileName);
//			map = fileMappingCreate(fileName);
//			file_size = { 0 };
//			::GetFileSizeEx(map->hFile, &file_size);
//			fileSize = static_cast<unsigned long long>(file_size.QuadPart);
//			break;
//		case 8 :
//			printf("1 to find string with your number\n 2 to find pattern\n 3 to find pattern not case sensitive\n 4 to find control sum\n 5 to record\n 6 to remove\n - 1 to quit\n");
//			break;
//		case -1:
//			return 0;
//			break;
//		default:
//			printf("Bad choice\n");
//			break;
//		}
//	}
//	
//	return 0;
//}
//
//
//bool remove(FileMapping *fm, DWORD cbView, const unsigned long long fileSize, unsigned long long position, unsigned long long qnty)
//{
//	HANDLE hFile = CreateFile(L"tmp.txt", GENERIC_WRITE, 0, nullptr, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, nullptr);
//	if (hFile == INVALID_HANDLE_VALUE) {
//		std::cerr << "fileRemove failed\n " << std::endl;
//		return nullptr;
//	}
//	bool find = false;
//
//	for (unsigned long long offset = 0; offset < fileSize; offset += cbView) {
//		DWORD high = static_cast<DWORD>((offset >> 32) & 0xFFFFFFFFul);
//		DWORD low = static_cast<DWORD>(offset & 0xFFFFFFFFul);
//		if (offset + cbView > fileSize) {
//			cbView = static_cast<int>(fileSize - offset);
//		}
//		const char *pView = static_cast<const char *>(::MapViewOfFile(fm->hMapping, FILE_MAP_READ, high, low, cbView));
//		if (pView != NULL) {
//			if (offset + cbView >= position && !find) {
//				WriteFile(hFile, pView, (position % cbView), nullptr, nullptr);
//				if (cbView - (position % cbView) > qnty) {
//					WriteFile(hFile, pView + (position % cbView) + qnty , (cbView - (position % cbView)) - qnty, nullptr, nullptr);
//					qnty = 0;
//				} else {
//					qnty -= cbView - (position % cbView) - qnty;
//				}
//				find = true;
//			} else if (find && qnty != 0) {
//				if (qnty <= cbView) {
//					WriteFile(hFile, pView + qnty, cbView - qnty, nullptr, nullptr);
//					qnty = 0;
//				}
//			} else {
//				WriteFile(hFile, pView, cbView, nullptr, nullptr);
//			}
//		}
//	}
//	CloseHandle(hFile);
//	CloseHandle(fm->hFile);
//	MoveFileEx(L"tmp.txt", fm->fName, MOVEFILE_REPLACE_EXISTING);
//	return true;
//}
//
//
//
//FileMapping* fileMappingCreate(const char *fname)
//{
//	WCHAR wcNname[SIZE_OF_FILE_NAME];
//	MultiByteToWideChar(CP_ACP, 0, fname, strlen(fname) + 1, (LPWSTR)wcNname, sizeof(wcNname) / sizeof(wcNname[0]));
//	
//	HANDLE hFile = CreateFile(wcNname, (GENERIC_READ | GENERIC_WRITE), 0, nullptr, OPEN_EXISTING,
//		FILE_ATTRIBUTE_NORMAL, nullptr);
//	if (hFile == INVALID_HANDLE_VALUE) {
//		std::cerr << "fileMappingCreate - CreateFile failed, fname =  "
//			<< fname << std::endl;
//		return nullptr;
//	}
//
//	DWORD dwFileSize = GetFileSize(hFile, nullptr);
//	if (dwFileSize == INVALID_FILE_SIZE) {
//		std::cerr << "fileMappingCreate - GetFileSize failed, fname =  "
//			<< fname << std::endl;
//		CloseHandle(hFile);
//		return nullptr;
//	}
//	HANDLE hMapping = CreateFileMappingW(hFile, nullptr, PAGE_READONLY, (DWORD)0, (DWORD)0,
//		nullptr);
//	if (hMapping == nullptr) {
//		std::cerr << "fileMappingCreate - CreateFileMapping failed, fname =  "
//			<< fname << std::endl;
//		CloseHandle(hFile);
//		return nullptr;
//	}
//
//	FileMapping* mapping = (FileMapping*)malloc(sizeof(FileMapping));
//	if (mapping == nullptr) {
//		std::cerr << "fileMappingCreate - malloc failed, fname = "
//			<< fname << std::endl;
//		CloseHandle(hMapping);
//		CloseHandle(hFile);
//		return nullptr;
//	}
//	mapping->fName = wcNname;
//	mapping->hFile = hFile;
//	mapping->hMapping = hMapping;
//	mapping->fsize = (size_t)dwFileSize;
//
//	return mapping;
//}
//
//
//
//bool findStingNumberX(FileMapping *fm, DWORD cbView, const unsigned long long fileSize, int stringNumber)
//{
//	unsigned long long curNumber = 0;
//	bool find = false;
//	unsigned long long sum = 0;
//
//	for (unsigned long long offset = 0; offset < fileSize; offset += cbView) {
//		DWORD high = static_cast<DWORD>((offset >> 32) & 0xFFFFFFFFul);
//		DWORD low = static_cast<DWORD>(offset & 0xFFFFFFFFul);
//		if (offset + cbView > fileSize) {
//			cbView = static_cast<int>(fileSize - offset);
//		}
//		const char *pView = static_cast<const char *>(
//			::MapViewOfFile(fm->hMapping, FILE_MAP_READ, high, low, cbView));
//		if (pView != NULL) {
//			unsigned long long j = 0;
//			for (; j < cbView && stringNumber > curNumber; ++j) {
//				if (pView[j] == '\n') {
//					curNumber++;
//				}
//			}
//			if (stringNumber == curNumber) {
//				for (; j < cbView; ++j) {
//					putchar(pView[j]);
//					if (pView[j] == '\n') {
//						return true;
//					}
//				}
//			}
//		}
//	}
//	return false;
//}
//
//
//
//bool findPattern(FileMapping *fm, DWORD cbView, const unsigned long long fileSize, char * pattern)
//{
//	unsigned long long counter = 0, stringCounter = 0, sum = 0;
//	bool find = false;
//	char *sumString = (char *)malloc(1);
//
//	for (unsigned long long offset = 0; offset < fileSize; offset += cbView) {
//
//		DWORD high = static_cast<DWORD>((offset >> 32) & 0xFFFFFFFFul);
//		DWORD low = static_cast<DWORD>(offset & 0xFFFFFFFFul);
//		if (offset + cbView > fileSize) {
//			cbView = static_cast<int>(fileSize - offset);
//		}
//		const char *pView = static_cast<const char *>(::MapViewOfFile(fm->hMapping, FILE_MAP_READ, high, low, cbView));
//		if (pView != NULL) {
//			sumString = (char *)realloc(sumString, cbView * sizeof(char) * (counter + 1));
//			unsigned long long j, offs = 0, k = 0;;
//			for (j = 0; j < cbView; ++j) {
//
//				sumString[counter  * cbView + k] = pView[j];
//				if (pView[j] == '\n') {
//					printf("CBView == %lu\n", cbView);
//					printf("Offs == %llu\n", offs);
//					printf("Sum Str == %s", sumString);
//					stringCounter++;
//					offs += k;
//					k = 0;
//					counter = 0;
//					char *res = strstr(sumString, pattern);
//					if (res != nullptr) {
//						printf("Pattern start on %u string ", stringCounter);
//						printf("on %u symbol\n", res - sumString + 1);
//						return true;
//					}
//				} else {
//					k++;
//				}
//			}
//		}
//		counter++;
//	}
//	return false;
//}
//
//
//
//bool findPatternNoRegister(FileMapping *fm, DWORD cbView, const unsigned long long fileSize, char * pattern)
//{
//	unsigned long long counter = 0, stringCounter = 0, patternSize = strlen(pattern);
//
//	bool find = false;
//	unsigned long long sum = 0;
//	char *sumString = (char *)malloc(1);
//	for (unsigned long long i = 0; i < patternSize; ++i) {
//		pattern[i] = tolower(pattern[i]);
//	}
//	for (unsigned long long offset = 0; offset < fileSize; offset += cbView) {
//
//		DWORD high = static_cast<DWORD>((offset >> 32) & 0xFFFFFFFFul);
//		DWORD low = static_cast<DWORD>(offset & 0xFFFFFFFFul);
//		if (offset + cbView > fileSize) {
//			cbView = static_cast<int>(fileSize - offset);
//		}
//		const char *pView = static_cast<const char *>(
//			::MapViewOfFile(fm->hMapping, FILE_MAP_READ, high, low, cbView));
//		if (pView != NULL) {
//			sumString = (char *)realloc(sumString, cbView * sizeof(char) * (counter + 1));
//			unsigned long long j, offs = 0, k = 0;;
//			for (j = 0; j < cbView; ++j) {
//
//				sumString[counter  * cbView + k] = tolower(pView[j]);
//				if (pView[j] == '\n') {
//					stringCounter++;
//					offs += k;
//					k = 0;
//					counter = 0;
//
//					char *res = strstr(sumString, pattern);
//					if (res != nullptr) {
//						printf("Pattern start on %u string ", stringCounter);
//						printf("on %u symbol\n", res - sumString + 1);
//
//						return true;
//					}
//				}
//				else {
//					k++;
//				}
//			}
//		}
//		counter++;
//	}
//	return false;
//}
//
//
//unsigned long findCRC(FileMapping *fm, DWORD cbView, const unsigned long long fileSize)
//{
//	unsigned long controlSum = 0;
//	for (unsigned long long offset = 0; offset < fileSize; offset += cbView) {
//
//		DWORD high = static_cast<DWORD>((offset >> 32) & 0xFFFFFFFFul);
//		DWORD low = static_cast<DWORD>(offset & 0xFFFFFFFFul);
//		if (offset + cbView > fileSize) {
//			cbView = static_cast<int>(fileSize - offset);
//		}
//		const char *pView = static_cast<const char *>(::MapViewOfFile(fm->hMapping, FILE_MAP_READ, high, low, cbView));
//		if (pView != NULL) {
//			controlSum += crc(pView, cbView);
//		}
//	}
//	return controlSum;
//}
//
//
//bool record(FileMapping *fm, DWORD cbView, const unsigned long long fileSize, const unsigned long long position, char *text)
//{
//	HANDLE hFile = CreateFile(L"tmp.txt", GENERIC_WRITE, 0, nullptr, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, nullptr);
//	if (hFile == INVALID_HANDLE_VALUE) {
//		std::cerr << "fileRecord failed\n " << std::endl;
//		return nullptr;
//	}
//	unsigned long long len = strlen(text), check;
//	bool find = false;
//	for (unsigned long long offset = 0; offset < fileSize; offset += cbView) {
//
//		DWORD high = static_cast<DWORD>((offset >> 32) & 0xFFFFFFFFul);
//		DWORD low = static_cast<DWORD>(offset & 0xFFFFFFFFul);
//		if (offset + cbView > fileSize) {
//			cbView = static_cast<int>(fileSize - offset);
//		}
//		const char *pView = static_cast<const char *>(::MapViewOfFile(fm->hMapping, FILE_MAP_READ, high, low, cbView));
//		if (pView != NULL) {
//			if (offset + cbView >= position && !find) {
//				WriteFile(hFile, pView, (position % cbView), nullptr, nullptr);
//				WriteFile(hFile, text, len, nullptr, nullptr);
//				WriteFile(hFile, pView + (position % cbView), cbView - (position % cbView), nullptr, nullptr);
//				find = true;
//			}
//			else {
//				WriteFile(hFile, pView, cbView, nullptr, nullptr);
//			}
//		}
//	}
//	CloseHandle(hFile);
//	CloseHandle(fm->hFile);
//	MoveFileEx(L"tmp.txt", fm->fName, MOVEFILE_REPLACE_EXISTING);
//	return true;
//}
//
//
//unsigned long  crc(const char *buf, size_t len)
//{
//	unsigned long  crc_table[256];
//	unsigned long  crc;
//	int i, j;
//
//	for (i = 0; i < 256; i++)
//	{
//		crc = i;
//		for (j = 0; j < 8; j++)
//			crc = crc & 1 ? (crc >> 1) ^ 0xEDB88320UL : crc >> 1;
//
//		crc_table[i] = crc;
//	};
//
//	crc = 0xFFFFFFFFUL;
//
//	while (len--)
//		crc = crc_table[(crc ^ *buf++) & 0xFF] ^ (crc >> 8);
//
//	return crc ^ 0xFFFFFFFFUL;
//}