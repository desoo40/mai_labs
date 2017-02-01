#include <iostream>

using namespace std;

int main() {
	unsigned long long n = 0;
	int k = 0;

	cin >> n >> k;

	int i = 0;
	unsigned long long j = 1;

	while (1)
	{
		if (n % j == 0)
			++i;
		
		if (i == k)
		{
			cout << j << endl;
			return 0;
		}

		++j;

		if (j > n)
		{
			cout << -1 << endl;
			return 0;
		}
	}

	return 0;
}