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

    long long dig = 0;
    int difficult = 0;

    cin >> dig;

    for (int i = 1; i * i <= dig; ++i)
    {
    	if (i * i == dig) {
    		++difficult;
    		break;
    	}

    	if (dig % i == 0)
    		difficult += 2;
    }

    cout << difficult << endl;

    return 0;
}