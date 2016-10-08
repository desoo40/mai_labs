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

    int ans = 0;
    string dig = "";

    cin >> dig;

    for (size_t i = 0; i < dig.size(); ++i)
    {
    	if (dig[i] == '4' ||
    		dig[i] == '6' || 
    		dig[i] == '9' || 
    		dig[i] == '0')
    		++ans;

    	if (dig[i] == '8')
    		ans += 2;
    }

    cout << ans << endl;

    return 0;
}