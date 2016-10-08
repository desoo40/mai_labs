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

using namespace std;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string str;
	struct boolochka {
		bool is_h = false;
		bool is_e = false;
		bool is_l = false;
		bool is_l2 = false;
		bool is_o = false;
	};

	getline(cin, str);

	if (str.size() < 5) {
		cout << "NO";
		return 0;
	}

	for (size_t i = 0; i < str.size(); ++i)
	{
		/* code */
	}


	return 0;
}