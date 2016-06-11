#include <string>
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <vector>
#include <map>
#include <ctime>


using namespace std;

int main()
{
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    srand( time( 0 ) );

    int graduates = 0;

    cin >> graduates;

    for (int i = 0; i < graduates; ++i)
    {
    	int gender = rand() % 2;
    	int year = rand() % (2016 - 2010) + 2010;
    	char letter = rand() % (70 - 65) + 65;

    	if (gender)
    		cout << "Surname" << ' ' << "OL" << ' ' << 'M' << ' ' << year << ' ' << letter << ' ' << "Univer" << endl;
    	else
    		cout << "Surname" << ' ' << "OL" << ' ' << 'F' << ' ' << year << ' ' << letter << ' ' << "Univer" << endl;
    }
    return 0;
}
