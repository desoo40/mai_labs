#include <string>
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <vector>
#include <map>

using namespace std;

bool check (const string &s, const string &h, int i)
{
	for (size_t j = 0; j < s.size(); ++j)
	{
		if (s[j] != h[i + j])
			return false;
	}
	return true;
}

int main()
{
	string s;
	string h;
	int num_ins = 0;
	int base = 37;
	long long shash = 0;
	long long hhash = 0;

	cin >> h >> s;

	for (size_t i = 0; i < s.size(); ++i)
	{
		shash = shash * base + s[i] - 'a' + 1;
	}

	for (size_t i = 0; i < h.size() - s.size() + 1; ++i)
	{
		for (size_t j = 0; j < s.size(); ++j)
		{
			hhash = hhash * base + h[j + i] - 'a' + 1;
		}

		// cout << hhash << " " << shash << endl;
		// cout << h << " " << s << endl;

		if (hhash == shash)
			if (check(s, h, i))
				++num_ins;
		hhash = 0;
	}
	if (num_ins)
		cout << "TAK" << endl << num_ins << endl;
	else
		cout << "NIE" << endl;

	return 0;
}