#include <string>
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <vector>
#include <map>

using namespace std;

char look_for_max(string s)
{
	char max = 0;

	for (size_t i = 0; i < s.size(); ++i)
	{
		if (s[i] > max)
		{
			max = s[i];
		}
	}
	return max;
}

int tm(char c, string s)
{
	int time_m = 0;

	for (size_t i = 0; i < s.size(); ++i)
	{
		if (s[i] == c)
			++time_m;
	}
	return time_m;
}

void print(int t, char c)
{
	for (int i = 0; i < t; ++i)
	{
		cout << c;
	}
	cout << endl;
}

int main()
{
	string str;

	cin >> str;

	char max_char = look_for_max(str);
	int times_meet = tm(max_char, str);
	print(times_meet, max_char);

	return 0;
}