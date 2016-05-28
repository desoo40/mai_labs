#include <string>
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <vector>
#include <map>
#include <ctime>


using namespace std;

int main()
{
	ios::sync_with_stdio(false);
    cin.tie(NULL);

    srand( time( 0 ) );

    int size = 0;
    int diap = 0;

    cin >> size >> diap;

    cout << 1 << ' ';

    for (int i = 0; i < size; ++i)
    {
        int dig = rand() % diap;

        cout << 4 << ' ' << diap << ' ' << diap;
    }

    while(1)
    {
        cout << rand() % diap << endl;
    }

    cout << 0 << ' ' << 4;
    return 0;
}