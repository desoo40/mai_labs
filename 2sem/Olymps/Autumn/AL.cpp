#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <vector>
#include <map>
#include <cctype>
#include <cwctype>
#include <stdexcept>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>

using namespace std;

char revers_scope(char c)
{
	if (c == '(')
		return ')';

	if (c == '{')
		return '}';

	if (c == '[')
		return ']';
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	stack<int> st;
	int scopes = 0;

	cin >> scopes;

	if (scopes % 2) {
		cout << "Nein" << endl;
		return 0;
	}

	for (int i = 0; i < scopes; ++i)
	{
		char c = ' ';
		cin >> c;

		if (c == '(' || c == '{' || c == '[')
			st.push(c);

		if (c == ')' || c == '}' || c == ']') {

			if (st.empty()) {
				cout << "Nein" << endl;
				return 0;
			}
			
			if (revers_scope(st.top()) == c)
				st.pop();

			else {
				cout << "Nein" << endl;
				return 0;
			}
		}
	}

	if (!st.empty()) {
		cout << "Nein" << endl;
		return 0;
	}

	cout << "Ja" << endl;

	return 0;
}