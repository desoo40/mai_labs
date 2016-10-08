#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <vector>
#include <map>
#include <cctype>
#include <cwctype>
#include <stdexcept>
#include <algorithm>
#include <string>
#include <cmath>
#include <queue>
#include <stack>

#define mod 1000000000000000

using namespace std;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long integ = 0;
	long long flo = 0;
	string digit;

	while(cin >> digit)
	{
		long long tmp_1 = 0;
		long long tmp_2 = 0;
		bool after_dot = false;

		for (size_t i = 0; i < digit.size(); ++i)
		{
			if (digit[i] == '.')
			{
				after_dot = true;
				continue;
			}

			if (!after_dot)
			{
				tmp_1 *= 10;
				tmp_1 += digit[i] - '0';
			}

			else 
			{
				tmp_2 *= 10;
				tmp_2 += digit[i] - '0';
			}
		}

		integ += tmp_1;
		flo += tmp_2;
	}

	integ += flo / mod;
	flo %= mod;

	cout << integ << '.';

	if (flo == 0)
	{
		for (int i = 0; i < 15; ++i)
		{
			cout << 0;
		}
	}

	else if (flo < mod / 10)
	{
		long long tmp = flo;

		while (tmp < mod / 10)
		{
			tmp *= 10;
			cout << 0;
		}

		cout << flo;
	}

	cout << endl;
	return 0;
}