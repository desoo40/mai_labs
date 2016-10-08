#include <string>
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <vector>
#include <map>
#include <cctype>
#include <cwctype>
#include <stdexcept>
#include <cmath>

using namespace std;

int find_max(int a, int b, int c)
{
	int max = a;

	if (b > max)
		max = b;

	if (c > max)
		max = c;

	if ((a == max && b == max) ||
		(a == max && c == max) ||
		(b == max && c == max))
		return 0;

	return max;
}

int main(void)
{
	ios::sync_with_stdio(false);
    cin.tie(NULL);

    string her;
    map<string, int> names;

    while (cin >> her)
    	++names[her];

   	int a = names["Sebulba"];
   	int b = names["Tsebulba"];
   	int c = names["Chebulba"];

   	int max = find_max(a, b, c);

   	if (max == 0) {
   		cout << "May the Force be with you!" << endl;
   		return 0;
   	}

   	if (a == max)
   		cout << "Sebulba" << endl;
   	if (b == max)
   		cout << "Tsebulba" << endl;
   	if (c == max)
   		cout << "Chebulba" << endl;

   	return 0;
}
