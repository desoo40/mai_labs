Лабораторная №2

Словари!

+ key value
- key
key
! Save path
! Load path

#include <iostream>
#include <stdio>

using namespace std;

int main()
{
	char action;
	while (cin << action)
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
				} else if (type == "Load") {
					cout << "Load" << endl;
				}
			}
			else {
				unget(action, stdin);
				string key;
				cin >> key;
				cout << "Search for key [" << key << ']' << endl;
			}
	}
}