#include <string>
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <vector>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
    cin.tie(NULL);

    int num_of_strings = 0;
    int num_of_dots = 0;
    string ipv6;

    cin >> num_of_strings;

    for (int i = 0; i < num_of_strings + 1; ++i)
    {
    	getline(cin, ipv6, '\n');

    	if (ipv6.size() == 2) {
    		cout << "0000:0000:0000:0000:0000:0000:0000:0000" << endl;
    		continue;
    	}

    	for (size_t j = 0; j < ipv6.size(); ++j)
    	{
    		if(ipv6[j] == ':')
    			++num_of_dots;
    		//cout << num_of_dots << endl;
    	}

    	for (int j = 0; j < 28; j += 4)
    	{
    		int k = 0;

    		while(ipv6[++k] != ':') {
    		}

    		if(k < 4) {
    			if (k == 0) {

    				int else_dots = 0;

    				for (int y = j + 2; ipv6[y] != '\0'; ++y)
    				{
    					if(ipv6[y] == ':')
    						++else_dots;
    				}

    				for (int o = 0; o < num_of_dots - j / 4 - else_dots; ++o) 
    				{
    					if (else_dots == 0 && ++o == num_of_dots - j / 4)
    					{
    						cout << "0000" << endl;
    						break;
    					}
    					cout << "0000:" << endl;
    				}
    			}
    			else {
    				for (int o = 0; o < 4; ++o)
	    			{
	    				if(o < k)
    						cout << 0;
    					else
    						cout << ipv6[j + o];
    				}
    			}
    		}
    		if (k == 4) {
    			for (int o = 0; o < k; ++o)
    			{
    				cout << ipv6[j + o];
    			}
    		}
    	}
    	num_of_dots = 0;
    	cout << endl;
    }
    return 0;
}