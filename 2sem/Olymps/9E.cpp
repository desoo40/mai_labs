#include <string>
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <vector>

using namespace std;

int main(void)
{
	string abcd = "abcd";
	int num = 0;

	cin >> num;

	for (int i = 0; i < num / 4; ++i)
	{
		cout << abcd;
	}
	for (int i = 0; i < num % 4; ++i)
	{
		cout << abcd[i];
	}

	return 0;
}