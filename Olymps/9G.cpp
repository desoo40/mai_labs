#include <string>
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <vector>

using namespace std;

long long calc(int* first, size_t size)
{
	long long sum = 0;
	for (size_t i = 0; i < size; ++i)
	{
		sum += *first++;
	}
	return sum;
}

int main(void)
{
	int dig_num = 0;
	int rechange = 0;
	long long sum = 0;
	int ind_of_null = -1;

	cin >> dig_num >> rechange;

	vector<int> line(dig_num);
	
	for (size_t i = 0; i < line.size(); ++i)
	{
		int dig = 0;
		cin >> dig;

		if (dig < 0 && rechange) {
			line[i] = -1 * dig;
			--rechange;
		}
		else if (dig == 0) {
			line[i] = dig;
			ind_of_null = i;
		} else
			line[i] = dig;
	}

	if(rechange && ind_of_null != -1) {
		sum = calc(&line[0], line.size());
		cout << sum << endl;
		return 0;
	} else if(rechange % 2) {
		sum -= line[0];
		sum += calc(&line[1], line.size() - 1);
		cout << sum << endl;
		return 0;
	}

	cout << calc(&line[0], line.size()) << endl;
	return 0;
}