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

long long recur(long long n)
{
	return n == 0 ? 1 : recur(n / 3) + recur(n / 5);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long n = 0;

	cin >> n;

	cout << recur(n) << endl;

	return 0;
}