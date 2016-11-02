#include <iostream>
#include <cstdio>
#include "str.h"

using namespace std;

int main()
{
	TString str;

	cin >> str;
	cout << str;

	return 0;
	/*char action;
	while (cin >> action)
	{
		if (action == '+')
		{
			cout << "Add" << endl;
		}
		else if (action == '-')
		{
			cout << "Delete" << endl;
		}
		else if (action == '!')
		{
			string type;
			cin >> type;
			if (type == "Save") {
				cout << "Save" << endl;
			}
			else if (type == "Load") {
				cout << "Load" << endl;
			}
		}
		else {
			unget(action, stdin);
			string key;
			cin >> key;
			cout << "Search for key [" << key << ']' << endl;
		}
	}*/
}