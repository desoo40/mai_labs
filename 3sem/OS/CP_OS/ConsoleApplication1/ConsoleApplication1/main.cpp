#include <iostream>
#include <string>
#include <vector>
#include "mapping.h"
#include <conio.h>
#include <fstream>
#include <ctime>

int main()
{
	setlocale(LC_ALL, "Russian");
	/*FileMapping *map = new FileMapping();
	char *fname = (char*)malloc(SIZE_OF_FILE_NAME * sizeof(char*));
	WCHAR n[SIZE_OF_FILE_NAME];
	fname = "test.txt";
	MultiByteToWideChar(CP_ACP, 0, fname, strlen(fname) + 1, (LPWSTR)n, sizeof(n) / sizeof(n[0]));
	map->Open_File(n);

	map->ShowDiapasone(0, map->Size());

	for (size_t i = 0; i < map->Size(); ++i)
	{
		map->ShowDiapasone(i, i);
	}*/

	ifstream file;
	file.open("test.txt");
	string text;

	getline(file, text);
	cout << text << endl;
	char c;
	clock_t time;
	time = clock();
	int errors = 0;

	for (size_t i = 0; i < text.size(); ++i)
	{
		c = _getch();
		if (c != text[i]) {
			Beep(1000, 200);
			++errors;
			--i;
		}
		else 
			cout << c;
	}
	cout << endl;
	time = clock();

	double minute = 60.0;
	double tme = (double)time / CLOCKS_PER_SEC;
	cout << "Time: "<<  tme << " s"<< endl;
	cout << "Errors: " << errors << endl;
	cout << "Speed: " << text.size() * minute / tme << " sym/s" << endl;
	return 0;

	/*vector<string> arr;

	while (getline(file, text, ' '))
		arr.push_back(text);

	file.close();

	for (auto i = 0; i < arr.size(); ++i)
		cout << arr[i] << " ";

	cout << endl;
	clock_t time;
	time = clock();
	int errors = 0;
	int allSym = 0;

	for (auto i = 0; i < arr.size(); ++i)
	{

		char c;
		if (i != 0) {
			c = _getch();

			while (c != ' ') {
				c = _getch();
				Beep(1000, 200);
			}

			++allSym;
			cout << c;
		}
	
		for (auto j = 0; j < arr[i].size(); ++j)
		{




			c =_getch();

			if (c != arr[i][j]) {
				Beep(1000, 200);
				--j;
				++errors;
				
			}
			else {
				++allSym;
				cout << c;
			}

		}
		
	}*/

	
}
