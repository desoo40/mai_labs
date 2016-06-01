#include <string>
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int fact(int n, int l)
{
    return n == l ? 0 : n + fact(n - 1, l);
}

void fill(int* first, int size)
{
	for (int i = 0; i < size; ++i)
	{
		cin >> *(first + i);
	}
}
void max(int* first, int size, int p)
{
	int i = size - 1;
	int max = 0;

	while (p)
	{
		if (i == size - 1)
		{
			if (*(first + i) > *(first + i - 1))
			{
				max += *(first + i);
				--*(first + i);
				--p;
				// cout << 1 << " ";
			}
			else
			{
				--i;
				// cout << 2 << " ";
			}
		} else if (i == 0)
		{
			if (*(first + i) >= *(first + i + 1))
			{
				max += *(first + i);
				--*(first + i);
				--p;
				// cout << 3 << " ";
			}
			else
			{
				++i;
				// cout << 4 << " ";
			}
		} else {
			if (*(first + i) < *(first + i + 1))
			{
				max += *(first + ++i);
				--*(first + i);
				--p;
				// cout << 5 << " ";
			}
			else if (*(first + i) > *(first + i - 1))
			{
				max += *(first + i);
				--*(first + i);
				--p;
				// cout << 6 << " ";
			}
			else if (*(first + i) <= *(first + i - 1))
			{
				--i;
				// cout << 7 << " ";
			}
		}
	}
	cout << max << " ";
}

void min(int* first, int size, int p)
{
	int i = 0;
	int min = 0;

	while(p && i < size)
	{
		if (*(first + i) <= p) {
			min += fact(*(first + i), 0);
			p -= *(first + i);
			++i;
		}
		else {
			min += fact(*(first + i), *(first + i) - p);
			cout << min << endl;
			return;
		}
	}

	cout << min << endl;
	return;
}

int main()
{
	int pass = 0;
	int planes = 0;

	cin >> pass >> planes;

	vector<int> places(planes);
	vector<int> places2(planes);

	fill(&places[0], planes);
	sort(places.begin(), places.end());

	places2 = places;

	max(&places[0], planes, pass);
	min(&places2[0], planes, pass);

	return 0;
}