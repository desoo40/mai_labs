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

    long long n = 0;
    long long sym = 0;

    cin >> n;

    for (long long i = 0; i < n; ++i)
    {
    	long long tmp = 0;
    	cin >> tmp;

    	sym += tmp;
    }

    cout << sym << endl;
}
