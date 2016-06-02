#include <string>
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <vector>

using namespace std;

int main(void)
{
	string line;
	getline(cin, line);

	int answer = line.size();

	for (size_t i = 0; i < line.size(); ++i)
	{
		for (size_t j = i + 1; j < line.size(); ++j)
		{
			if (line[i] == line[j])
			{
				++++answer;
			}
		}
	}

	cout << answer << endl;

	return 0;
}