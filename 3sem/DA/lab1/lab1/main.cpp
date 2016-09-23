#include <iostream>

using namespace std;
using Tloong = unsigned long long;

class TElement {
public:
    Tloong key = 0;
    Tloong value = 0;

    bool EnterPair() {
        if (cin >> key >> value)
            return 1;
        else
            return 0;
    }
};

int main(int argc, char const **argv) {
    TElement ololo;

    while (ololo.EnterPair())

        cout << ololo.key << ololo.value;

    return 0;
}