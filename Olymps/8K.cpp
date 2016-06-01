#include <string>
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

void fill(int* first, int size)
{
	for (int i = 0; i < size; ++i)
	{
		char dig;
		cin >> dig;
		*(first + i) = dig - '0';
	}
}

void is_unlucky(int* first, int* second, int size)
{
	if (*first > *second)
	{
		for (int i = 1; i < size; ++i)
		{
			if (*(first + i) <= *(second + i))
			{
				cout << "NO" << endl;
				return;
			}
		}

		cout << "YES" << endl;
		return;
		
	} else if(*first < *second) {
		for (int i = 1; i < size; ++i)
		{
			if (*(first + i) >= *(second + i))
			{
				cout << "NO" << endl;
				return;
			}
		}

		cout << "YES" << endl;
		return;
	} 
	cout << "NO" << endl;
	return;
}

int main(void)
{
	int n = 0;

	cin >> n;

	vector<int> first_half(n);
	vector<int> second_half(n);

	fill(&first_half[0], n);
	fill(&second_half[0], n);
	sort(first_half.begin(), first_half.end());
	sort(second_half.begin(), second_half.end());

	is_unlucky(&first_half[0], &second_half[0], n);


	return 0;
}