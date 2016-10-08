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

	int hours = 0;
	int minutes = 0;
	int a = 0;
	int b = 0;
	int ans = 0;
	int ans_m = 0;

	while (cin >> hours)
	{
		cin >>	minutes >> minutes;
		cin >> a >> b >> b;
		ans += a - hours;
		ans_m += b - minutes;
	}

	ans += ans_m / 60;
	ans_m %= 60;

	cout << ans << ":" << ans_m;

	return 0;
}
