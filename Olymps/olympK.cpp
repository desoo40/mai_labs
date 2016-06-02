#include <string>
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <vector>
#include <map>

using namespace std;

int main()
{
	char letter = 123;
	int var = 1;

	vector <int> digits(10);

	for (int i = 0; letter != '\0'; ++i) {
		cin >> letter;
		digits[i] = letter - '0';
	}

	cout << digits[1];

	return 0;	
}
