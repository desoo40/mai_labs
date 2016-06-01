#include <string>
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <vector>
#include <map>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
    cin.tie(NULL);

    int toys_have = 0;
    int cash = 0;
    int add = 0;

    cin >> toys_have >> cash;

    vector<bool> all_toys(1000000000 + 1, false);
    vector<int> added(1000000);

    for (int i = 0; i < toys_have; ++i)
    {
    	int dig = 0;

    	cin >> dig;

    	all_toys[dig] = true;
    }

    for (int i = 1; cash - i >= 0; ++i)
    {
    	if (!all_toys[i])
    	{
    		cash -= i;
    		added[add] = i;
    		++add;
    	}
    }

    cout << add << endl;

    for (int i = 0; i < add; ++i)
    {
    	cout << added[i] << " ";
    }

    return 0;
}