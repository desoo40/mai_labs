#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

int main ()
{
	int a = 0;
	int b = 0;

	cin >> a >> b;

	while (a && b)
	{
		if (a > b)
			a = a % b;
		else
			b = b % a;
	}
	cout << a + b << endl;
}