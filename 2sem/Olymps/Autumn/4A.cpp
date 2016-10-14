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

using namespace std;

void greater_to_lower(long long dig, short base_1, short base_2)
{

}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	short base_1 = 0;
	short base_2 = 0;
	long long digit = 0;

	cin >> base_1 >> base_2 >> digit;

	if (base_1 == base_2) 
			cout << digit << endl;

	else if (base_1 > base_2)
		greater_to_lower(digit, base_1, base_2);

	else 
		lower_to_greater(digit, base_1, base_2);

	return 0;
}