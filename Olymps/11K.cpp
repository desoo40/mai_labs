#include <string>
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <vector>
#include <map>

using namespace std;

int main(void)
{
	long long right_b = 0;
	long long left_b = 0;
	long long digit = 0;
	bool mark = false;

	cin >> left_b >> right_b >> digit;

	if (left_b == 1)
	{
		cout << 1 << " ";
	}

	long long tmp = digit;

	while(1)
	{
		if (digit <= right_b)
		{
			if (digit >= left_b) {
				cout << digit << " ";
				digit *= tmp;

				if (digit < 0)
				{
					return 0;
				}

				mark = true;
			}
		}

		else {
			if (!mark)
				cout << -1 << endl;

			return 0;
		}
	}
}