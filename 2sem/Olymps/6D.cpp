#include <string>
#include <iostream>
#include <stdio.h>
#include <cstdlib>

using namespace std;

int main(void)
{
	int n = 0;
	int m = 0;
	int taps = 0;

	cin >> n >> m;

	if (n >= m) {

		cout << n - m << endl;
		return 0;

	} else {
		if (m % 2 == 0) {
			if (m / 2 < n) {
				cout << n - m / 2 + 1 << endl;
				return 0;
			} else if (m / 2 == n) {
				cout << 1 << endl;
				return 0;
			}
		}

			for (taps = 0; m > n; ++taps)
			{
				n *= 2;
				if (m % 2 == 0) {
			if (m / 2 < n) {
				cout << n - m / 2 + 2 << endl;
				return 0;
			} else if (m / 2 == n) {
				cout << taps + 1 << endl;
				return 0;
			}
		}
			}

			cout << abs(n - m) + taps << endl;	
			return 0;
	}
}