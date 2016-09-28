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
#include <iomanip>

using namespace std;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector<short> branches(4);
	bool is_triangle = false;
	bool is_segment = false;

	for (size_t i = 0; i < branches.size(); ++i)
		cin >> branches[i];


	for (size_t i = 0; i < branches.size(); ++i)
	{
		for (size_t j = 0; j < branches.size(); ++j)
		{
			if (j == i)
				continue;

			for (size_t k = 0; k < branches.size(); ++k)
			{
				if (k == i || k == j)
					continue;

				if (abs(branches[i]) < abs(branches[j]) + abs(branches[k]) &&
					abs(branches[j]) < abs(branches[i]) + abs(branches[k]) &&
					abs(branches[k]) < abs(branches[i]) + abs(branches[j]))

					is_triangle = true;

				else if ( abs(branches[i]) == abs(branches[j]) + abs(branches[k]) ||
						  abs(branches[j]) == abs(branches[i]) + abs(branches[k]) ||
						  abs(branches[k]) == abs(branches[i]) + abs(branches[j]) )
					is_segment = true;
			}
		}
	}

	if (is_triangle)
		cout << "TRIANGLE" << endl;
	else if (is_segment)
		cout << "SEGMENT" << endl;
	else 
		cout << "IMPOSSIBLE" << endl;

	return 0;

}