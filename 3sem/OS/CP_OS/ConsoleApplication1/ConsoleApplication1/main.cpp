#include <iostream>
#include <string>
#include <vector>
#include "mapping.h"
#include <conio.h>
#include <fstream>
#include <ctime>

int numOfFilesInDir()
{
    bool x = true;
    int i = 0;
    WIN32_FIND_DATA FindFileData;

    HANDLE hFind;
    wchar_t* fold = L"Texts/*.txt";
    hFind = FindFirstFile(fold, &FindFileData);

    if (hFind != INVALID_HANDLE_VALUE) {

        i++;

        while ((x = FindNextFile(hFind, &FindFileData)) == TRUE) {
            
            i++;
        }
    }

    return i;
}

int main()
{
	setlocale(LC_ALL, "Russian");
    srand(time(NULL));

	ifstream file;

    int numOfFiles = numOfFilesInDir();
    int rdm = rand() % numOfFiles;
    char fileName[16];
    vector<string> text;

    sprintf_s(fileName, "Texts/text%i.txt", rdm);

	file.open(fileName);

    string tmp;

    while (getline(file, tmp))
    {
        cout << tmp << endl;
        text.push_back(tmp);
    }

	char c;
	clock_t time;
	time = clock();
    int allSyms = 0;
	int errors = 0;

	for (size_t i = 0; i < text.size(); ++i)
	{
        for (size_t j = 0; j <= text[i].size(); ++j, ++allSyms)
        {
            if (i == text.size() - 1 && j == text[i].size())
                continue;

            c = _getch();

            if (c == ' ' && text[i][j] == '\0') {
                 cout << endl;
                 continue;
            }

            if (c != text[i][j]) {
                Beep(1000, 200);
                ++errors;
                --allSyms;
                --j;
            }
            else
                cout << c;
        }
	}
	cout << endl;
	time = clock();

	double minute = 60.0;
	double tme = (double)time / CLOCKS_PER_SEC;
	cout << "Time: "<<  tme << " s"<< endl;
	cout << "Errors: " << errors << endl;
	cout << "Speed: " << allSyms * minute / tme << " sym/s" << endl;
	return 0;



	
}
