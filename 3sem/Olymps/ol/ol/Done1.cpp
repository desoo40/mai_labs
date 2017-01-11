#include <iostream>

using namespace std;

int main() {
    int cases = 0;
    int time_to_go = 0;
    

    cin >> cases >> time_to_go;

    int time_for_solve = 4 * 60 - time_to_go;

    int i = 1;

    for(i; time_for_solve > 0 && i <= cases; ++i)
        time_for_solve -= i * 5;

    i--;

    if (time_for_solve < 0)
        i--;

    cout << i << endl;

    return 0;
}