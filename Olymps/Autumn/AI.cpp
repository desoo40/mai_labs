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

	int tests = 0;

	cin >> tests;

	for (int i = 0; i < tests; ++i)
	{
		int qty = 0;

		cin >> qty;
		priority_queue<int> exams;

		for (int j = 0; j < qty; ++j)
		{
			int tmp = 0;
			cin >> tmp;
			exams.push(tmp);
		}
		
		int tmp = exams.top();
		exams.pop();
		cout << exams.top() << " " << tmp << endl;
	}

	return 0;
}