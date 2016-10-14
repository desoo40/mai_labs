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

    string str = "";
    string example = "hello";

    cin >> str;

    int j = 0;
    int j_max = (int) example.size();

    for (size_t i = 0; i < str.size(); ++i)
    {
    	if (str[i] == example[j])
    		++j;

    	if (j == j_max)
    	{
    		cout << "YES" << endl;
    		return 0;
    	}
    }

    cout << "NO" << endl;

    return 0;
}