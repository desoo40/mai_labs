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

    cout << "A" << ' ' << size << endl;

    for (int i = size; i != 0; --i) {
        int dig = rand() % diap;

        cout << dig << endl;
    }

    cout << 'e';
    return 0;
}