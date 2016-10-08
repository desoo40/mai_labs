#include <string>
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <vector>
 
using namespace std;

int main(void)
{
	long long n = 0;
	long long i = 1;

	cin >> n;

	for (i = 1; n > 0; i++)
	{
		n -= i;
	}

	cout << i - 1 + n << endl;

	return 0;
}