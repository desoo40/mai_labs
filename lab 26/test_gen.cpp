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

    int size = 0;
    int size2 = 0;
    int step = 0;

    cin >> size >> size2 >> step;

    for (int i = 0; i <= size; i += step)
    {
    	cout << 1 << " " << i << " " << i << endl;
    }

    cout << 0 << endl;

    for (int i = 0; i <= size2; i += step + 1)
    {
    	cout << 1 << " " << i << " " << i << endl;
    }

    cout << 0 << endl;

    return 0;
}