#include <string>
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <vector>

using namespace std;

int main(void)
{
	string line;
	long long answer = 0;

	getline(cin, line);

	vector<bool> marks(line.size());

	for (size_t i = 0; i < line.size(); ++i)
	{
		long long qty = 1;
		if(marks[i])
			continue;
		marks[i] = true;
		for (size_t j = i + 1; j < line.size(); ++j)
			{
				if(marks[j])
					continue;
				if (line[i] == line[j])
				{
					marks[j] = true;
					++qty;
				}
			}
		answer += qty * qty;	
	}

	cout << answer << endl;

	return 0;
}