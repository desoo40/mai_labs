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
    
	int dots = 0;
	int distans = 0;
	int triple_dots = 0;

	cin >> dots >> distans;

	if (dots == 1)
	{
		cout << 0 << endl;
		return 0;
	}

	vector<int> dots_line(dots);

	for(size_t i = 0; i < dots_line.size(); i++)
	{
    	cin >> dots_line[i];
    }

    for (size_t i = 0; i < dots_line.size() - 2; ++i)
    {  
    	//cout << i << endl;

    	for (size_t k = i + 1; k < dots_line.size() - 1; ++k)
    	{
    		//cout << k << endl;

	    	for (size_t j = k + 1; j < dots_line.size(); ++j)
	    	{
	    		//cout << j << endl;

	    		if (dots_line[j] - dots_line[i] <= distans)
	    		{
	    			++triple_dots;
	    		}
	    	}
	    }
    }

    cout << triple_dots << endl;
   	
	return 0;
}