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

    unsigned long long size = 0;
    int diap = 0;

    cin >> size >> diap;

    for (unsigned long long i = 0; i < size; ++i)
    {
    	cout << rand() % diap << " " << rand() % diap << endl;
    }

    return 0;
}