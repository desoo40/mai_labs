#include <string>
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <vector>

using namespace std;

int main()
{
	long long num_of_zeros = 0;
	int countries = 0;
	long long not_beautiful = 0;
	bool beautiful = false;
	cin >> countries;

	vector<string> tanks(countries);

	for (int i = 0; i < countries; ++i)
	{
		cin >> tanks[i];

		if (tanks[i][0] == '0') {
			cout << 0 << endl;
			return 0;
		}

		if (tanks[i][0] == '1') {
			int local_zeros = 0;
 
			for (size_t j = 1; j < tanks[i].size(); ++j) {
				if (tanks[i][j] != '0') {
					local_zeros = 0;

					for (size_t k = 0; k < tanks[i].size(); ++k)
					{
						not_beautiful *= 10;
						not_beautiful += tanks[i][k] - '0'; 
					}
					beautiful = true;
					break;
				} 

				++local_zeros;
			}

			num_of_zeros += local_zeros;
		}

		else {
			beautiful = true;
			for (size_t k = 0; k < tanks[i].size(); ++k)
			{
				not_beautiful *= 10;
				not_beautiful += tanks[i][k] - '0'; 
			}
		}
	}

	if (beautiful) {
		cout << not_beautiful;
	} else {
		cout << 1;
	}

	for (int i = 0; i < num_of_zeros; ++i)
	{
		cout << 0;
	}

	cout << endl;

	return 0;

}