#include <string>
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	string domino_line;
	size_t k = 0;
	int strong_domi = 0;
	int ind_of_prev = -1;
	int dominos_qty = 0;

	cin >> dominos_qty >> domino_line;

	for (int i = k; i < dominos_qty + 1; i++)
	{
		k = i;
		if (domino_line[i] == 'R' || domino_line[i] == 'L') break;

		if (domino_line[i] == '\0')
		{
			cout << "1" << dominos_qty << endl;
			return 0;
		}
	}

	for (int i = k; i < dominos_qty + 1; i++)
	{
		//cout << strong_domi << endl;
		k = i;
		if (domino_line[i] == '\0') break;

		if (domino_line[i] == 'R')
		{
			strong_domi += i - ind_of_prev - 1;
			ind_of_prev = i;
			while (domino_line[i] != 'L') {
				++i;
			}
			if ((i - ind_of_prev - 1) % 2) {
				++strong_domi;
			}
		}

		if (domino_line[i] == 'L')
		{
			ind_of_prev = i;
			while (domino_line[i] != 'R') {
				if (domino_line[i] == '\0') {
					cout << strong_domi + dominos_qty - ind_of_prev - 1 << endl;
					return 0;
				}
				++i;
			}
		}
	}

	if (domino_line[ind_of_prev] == 'L') {
		strong_domi += k - ind_of_prev - 1;
		cout << "2" << endl << strong_domi << endl;
		return 0;
	}

	cout << "3" << strong_domi << endl;
    return 0;
}

