#include <string>
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <vector>
 
using namespace std;



int main(void)
{
	int n = 0;
	long long ans = 0;
	long long power = 1;

	cin >> n;

	for (int i = 1; i <= n; ++i)
	{
		power = 2 * power;
		ans += power;
	}

	cout << ans << endl;

	return 0;
}