#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <vector>
#include <map>
#include <cctype>
#include <cwctype>
#include <stdexcept>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	short catet = 0;

	cin >> catet;

	for (int i = 0; i < catet; ++i)
	{
		for (int k = catet - i; k <= catet; ++k)
		{	
			if (k % 2)
				cout << i;
			else 
				cout << catet - k;
		}

		cout << endl;
	}

	return 0;
}