#include <string>
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <vector>
 
using namespace std;
 
int main()
{

	ios::sync_with_stdio(false);
    cin.tie(NULL);
    
	int topics = 0;

	cin >> topics;

	vector<int> locations(topics);

	for (int i = 0; i < topics; ++i)
	{
		cin >> locations[i];	
    }   

    for (int i = topics - 1; i > 0; i--)
    {
    	if (locations[i] < locations[i - 1]) {
    		cout << i << endl;
    		return 0;
    	}
    }

    cout << 0 << endl;
    return 0;
}