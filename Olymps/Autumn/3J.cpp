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
#include <stack>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	short TVs = 0;
	short might_of_vasya = 0;
	int cash = 0;

	cin >> TVs >> might_of_vasya;

	vector<short> eldorado(TVs);

	for (int i = 0; i < TVs; ++i)
	{
		cin >> eldorado[i];
	}

	sort(eldorado.begin(), eldorado.end());

	for (int i = 0; i < might_of_vasya; ++i)
	{
		if (eldorado[i] >= 0)
			break;

		cash += eldorado[i];
	}

	cout << -cash << endl;

	return 0;
}