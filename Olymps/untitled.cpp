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

	cin >> right_b >> left_b >> digit;

	if (left_b == 1)
	{
		cout << 1 << " ";
	}

	while(1)
	{
		if (digit <= right_b)
		{
			if (digit >= left_b && digit <= right_b) {
				cout << digit << " ";
				digit *= digit;
			}
		}

		else {
			return 0;
		}
	}
}