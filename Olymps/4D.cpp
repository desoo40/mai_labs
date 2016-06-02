#include <string>
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <limits.h>

using namespace std;

int right(string st, int dig)
{
	return st[0] == '>' ? (st.size() == 2 ? dig - 1 : dig) : (st.size() == 2 ? dig : dig - 1);
}

int left(string st, int dig)
{
	return st[0] == '>' ? (st.size() == 2 ? dig : dig + 1) : (st.size() == 2 ? dig + 1 : dig);
}

int main(void)
{
	int left_bord = INT_MIN;
	int right_bord = INT_MAX;
	int req_num = 0;

	cin >> req_num;

	for (int i = 0; i < req_num; ++i)
	{
		string eq;
		int dig = 0;
		char ans;
		getline(cin, eq, ' ');
		cin >>  dig >> ans;
		
		if (((eq == ">=" || eq == ">") && ans == 'N') || ((eq == "<=" || eq == "<") && ans == 'Y')) {
			right_bord = right(eq, dig);
			cout << eq << " " << ans << "R" << right_bord << endl; }
		else
		{	left_bord = left(eq, dig);
			cout << eq << " " << ans << "L" << left_bord << endl;}
	}

	if (left_bord > right_bord)
	{
		cout << "Impossible" << endl;
		return 0;
	} 

	srand (time(NULL));
	cout << rand() % (right_bord - left_bord) + right_bord << endl;

	return 0;
}
