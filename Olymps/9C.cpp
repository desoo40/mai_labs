#include <string>
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <vector>

using namespace std;

int main(void)
{
	string first;
	string second;

	getline(cin, first, '\n');
	getline(cin, second, '\n');

	vector<bool> marks_1(first.size());
	vector<bool> marks_2(second.size());

	for (size_t i = 0; i < second.size(); ++i)
	{
		if (second[i] == ' ') 
				continue;
		for (size_t j = 0; j < first.size(); ++j)
		{
			if (first[j] == ' ') 
				continue;
			if (second[i] == first[j] && marks_1[j] == false) {
				marks_1[j] = true;
				marks_2[i] = true;
				break;
			}
		}
		if (marks_2[i] == false) {
			cout << "NO" << endl;
			return 0;
		}
	}

	cout << "YES" << endl;

	return 0;
}