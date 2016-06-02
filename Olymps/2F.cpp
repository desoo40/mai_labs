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

char inverse_reg(char c)
{
	return c > 95 ? c - 32 : c + 32;
}

int main(void)
{
	ios::sync_with_stdio(false);
    cin.tie(NULL);

    string congrat;
    string newspap;
    int yeah = 0;
    int opa = 0;

    map<char, int> letter;
    map<char, int> inv_letter;

    cin >> congrat >> newspap;

    for (size_t i = 0; i < newspap.size(); ++i)
    {
    	++letter[newspap[i]];
        ++inv_letter[newspap[i]];
    }

    for (size_t i = 0; i < congrat.size(); ++i)
    {
    	if (letter[congrat[i]])
    	{
    		++yeah;
    		--letter[congrat[i]];
    	}
    }

    for (size_t i = 0; i < congrat.size(); ++i)
    {
    	if (inv_letter[inverse_reg(congrat[i])])
    	{
    		++opa;
    		--inv_letter[inverse_reg(congrat[i])];
    	}
    }

    cout << yeah << " " << opa << endl;

    return 0;
}