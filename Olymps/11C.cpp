#include <string>
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <vector>
#include <map>

using namespace std;

bool is_divided(int n)
{
	return n % 4 == 0 ? true : false;
}

int main(void)
{
	string digit;
	long long under_str = 0;

	cin >> digit;
	
	for (size_t i = 0; i < digit.size(); ++i)
	{
		if (is_divided(digit[i] - '0'))
			++under_str;

		if (i)
			if (is_divided(10 * (digit[i - 1] - '0') + (digit[i] - '0')))
				under_str += i;
	}

	cout << under_str << endl;

	return 0;
}