

#include <string>
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <vector>

using namespace std;

long long calc(long long* first, size_t size)
{
	long long sum = 0;
	for (size_t i = 0; i < size; ++i)
	{
		sum += *first++;
	}
	return sum;
}
void invers_min(long long* first, size_t size)
{
	int min = *first;
	int ind_of_min = 0;
	for (size_t i = 1; i < size; ++i)
	{
		if (*(first + i) < min)
		{
			min = *(first + i);
			ind_of_min = i;
		}
	}

	*(first + ind_of_min) *= -1;
}

int main(void)
{
	ios::sync_with_stdio(false);
    cin.tie(NULL);

	long long dig_num = 0;
	long long rechange = 0;
	long long sum = 0;

	cin >> dig_num >> rechange;

	vector<long long> line(dig_num);
	
	for (size_t i = 0; i < line.size(); ++i)
	{
		long long dig = 0;
		cin >> dig;

		if (dig < 0 && rechange) {
			line[i] = -1 * dig;
			--rechange;
		} else
			line[i] = dig;
	}

	if(rechange % 2) {
		invers_min(&line[0], line.size());
		sum += calc(&line[0], line.size());
		cout << sum << endl;
		return 0;
	}

	cout << calc(&line[0], line.size()) << endl;
	return 0;
}