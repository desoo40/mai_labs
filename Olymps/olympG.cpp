#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

long long evkvid(long long a, long long b)
{
	while (a && b)
	{
		if (a > b)
			a = a % b;
		else
			b = b % a;
	}
	return a + b;
}

int main ()
{
	vector<long long> num(4);
	vector<long long> denom(4);

	for (int i = 0; i < 3; ++i)
		cin >> denom[i] >> num[i];

	num[2] = denom[2] - num[2];

	num[3] = 1;
	denom[3] = 1;

	for (int i = 0; i < 3; ++i) {
		num[3] *= num[i];
		denom[3] *= denom[i];
	}

	long long del = evkvid(num[3], denom[3]);

	num[3] /= del;
	denom[3] /= del;

	if (num[3] == 0) {
		cout  << 0 << endl;
		return 0;
	}
	if (num[3] == denom[3]) {
		cout << 1 << endl;
		return 0;
	}

	cout << num[3] << "/" << denom[3] << endl;

	return 0;
}