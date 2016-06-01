#include <string>
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <vector>
 
using namespace std;

vector <int> is_divider(int n)
{
	
	vector <int> d;
	int i = 0;

	for (int j = 1; j * j < n; ++j, ++i)
	{
		if (!(n % j)) {
			d[i] = j;
			if (j != n / j)
				d[++i] = n / j;
		}
	}
	cout << d[0] << endl;
	return d;
}
 
int main()
{
	int num_of_dig = 0;

	cin >> num_of_dig;

	vector<int> dividers = is_divider(num_of_dig);

	cout << dividers[0] << endl;

	return 0;
}