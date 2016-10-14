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

#define mod 1000000007

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long n = 0;

    cin >> n;

    if (n == 0)
    {
    	cout << 1 << endl;
    	return 0;
    }

    long long fac = n;
    long long tmp = n - 1;

    while (tmp != 0)
    {
    	fac %= mod;
    	fac *= tmp;
    	--tmp;
    }

    cout << fac << endl;
    
    return 0;
}