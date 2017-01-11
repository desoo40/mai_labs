// Новый год и северный полюс

#include <iostream>
#include <string>

using namespace std;

bool checkPosition(int meridian) {

    if (meridian > 20000 || meridian < 0) {
        cout << "NO" << endl;
        return true;
    }

    return false;
}

bool checkDots(int meridian) {
    return meridian == 0;
}

int main() {
    int meridian = 0;
    int parallel = 0;

    int steps = 0;

    cin >> steps;


    for (int i = 0; i < steps; ++i) {
        string direction = "";
        int delta = 0;

        cin >> delta >> direction;

        if (direction == "South")
            meridian += delta;

        if (direction == "North")
            meridian -= delta;

        if (direction == "West") {
            if (meridian == 0 || meridian == 20000) {
                cout << "NO" << endl;
                return 0;
            }
            parallel += delta;
        }

        if (direction == "East") {
            if (meridian == 0 || meridian == 20000) {
                cout << "NO" << endl;
                return 0;
            }
            parallel -= delta;
        }

        if (checkPosition(meridian))
            return 0;
        
    }

    if (checkDots(meridian))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}
