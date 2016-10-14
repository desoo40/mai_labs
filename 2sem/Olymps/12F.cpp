#include <string>
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <vector>

using namespace std;

long long progr(long long n)
{
	return ((6 + 6 * n) * n) / 2;
}

int main(void)
{
	ios::sync_with_stdio(false);
    cin.tie(NULL);

	long long n = 0;

	cin >> n;

	cout << 1 + progr(n) << endl;

	return 0;
}