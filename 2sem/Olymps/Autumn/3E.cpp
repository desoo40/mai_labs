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

	int eng_alph = 26;
	int qty = 0;

	cin >> qty;

	if (qty < eng_alph)
	{
		cout << "NO" << endl;
		return 0;
	}

	vector<bool> flag(eng_alph, false);
	string may_be_pangramma = "";

	cin >> may_be_pangramma;

	int marks = 0;

	for (size_t i = 0; i < may_be_pangramma.size(); ++i)
	{
		if (flag[tolower(may_be_pangramma[i]) - 'a'] == false) {
			flag[tolower(may_be_pangramma[i]) - 'a'] = true;
			++marks;
		}
	}

	if (marks < eng_alph)
		cout << "NO" << endl;
	else
		cout << "YES" << endl;

	return 0;
}