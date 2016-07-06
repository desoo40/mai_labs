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
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	short tests = 0;

	cin >> tests;

	for (short i = 0; i < tests; ++i)
	{
		short angle = 0;

		cin >> angle;

		if (360 % (180 - angle) == 0 && angle >= 60)
			cout << "YES" << endl;
		else 
			cout << "NO" << endl;
	}

	return 0;
}