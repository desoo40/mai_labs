#include <iostream>

using namespace std;

int main() {
    int n = 0;

    cin >> n;

    if (n == 0) {
        cout << 1;
        return 0;
    }
    
    int kek = n % 4;

    if (kek == 0)
        cout << 6;
    if (kek == 1)
        cout << 8;
    if (kek == 2)
        cout << 4;
    if (kek == 3)
        cout << 2;

    return 0;
}