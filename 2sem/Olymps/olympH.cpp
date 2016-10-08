#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

long long power_3(int lvl)
{
	return lvl == 0 ? 1 : power_3(lvl - 1) * 3 % 1000000007;
}

long long sum (int lvl)
{
	if (!lvl)
		return 2;
	else 
		return 1 + power_3(lvl);
}

int main()
{
	int lvl = 0;

	cin >> lvl;
	cout << sum(lvl) << endl;

	return 0;
}