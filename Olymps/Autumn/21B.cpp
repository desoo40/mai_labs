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

int main(void)
{
	ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n = 0;
    int p = 0;

    cin >> n;

    while (n >= 5 * pow(2, p))
   		++p;

    int i = n / pow(2, p);

    if (i == 1)
    	cout << "Sheldon" << endl;

    if (i == 2)
    	cout << "Leonard" << endl;

    if (i == 3)
    	cout << "Penny" << endl;

    if (i == 4)
    	cout << "Rajesh" << endl;

    if (i == 5)
    	cout << "Howard" << endl;


    return 0;
}