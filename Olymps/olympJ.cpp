#include <string>
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

int count(int l, int r)
{
	int ans = 0;

	for (int i = l; i <= r; i += 2) {
		bool mark = false;

		for (int j = 2; j <= sqrt(i); ++j) {
			if (i % j == 0 && j != 1) {
				mark = false;
				break;
			}
			mark = true;
		}

		if (mark)
			++ans;
	}

	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
    cin.tie(NULL);

	int l_bord = 0;
	int r_bord = 0;

	while (cin >> l_bord) {
		cin >> r_bord;

		int ans = 0;

		if (l_bord % 2 || l_bord == 2)
			ans = count(l_bord, r_bord);
		else 
			ans = count(l_bord + 1, r_bord);


		cout << ans << endl;
	}
	return 0;
}
