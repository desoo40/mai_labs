#include <string>
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <vector>
#include <map>
#include <cctype>
#include <cwctype>
#include <stdexcept>

using namespace std;
int main(void)
{
	ios::sync_with_stdio(false);
    cin.tie(NULL);

    long double x = 0.0;
    long double sym = 0.0;

    while (cin >> x)
    {
    	sym += x;
    }

   	printf("%.15Lf\n", sym);

   	return 0;
}