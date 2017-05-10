#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    /*double pi = 3.14;
    double g = 9.8;
    double ro = 7880.0 - 1260.0;
    double R = 0.0005;

    auto t = new double[3] 
    {
        7.15,
        6.73,
        6.66
    };

    double avg = 0;
    double avgS = 0;
    double avgT = 0;

    for (int i = 0; i < 3; ++i)
    {
        double speed = 0.15 / t[i];
        cout << "Speed " << i << ": " << speed << endl;
        double tmp = 4 * pi * pow(R, 3) * g * ro / (3 * speed);

        avg += tmp;
        avgT += t[i];
        avgS += speed;
        cout << "Resist" << i << ": " <<  tmp << endl;
    }


    cout << avgT / 3 << " " << avgS / 3 << " " << avg / 3 << endl;*/

    double m = 0.2;
    double a2 = 0.16;
    double a1 = 0.023;
    double p1 = 0.196;
    double p2 = 0.130;

    double r = 0.015;
    double h = 0.019;



    double ans = (2 * m * (a2 * a2 * p2 * p2 - a1 * a1 * p1 * p1)) / (p1 * p1 - p2 * p2) - 2 * m * ((r * r / 4) + (h * h) / 12);

    cout << ans << endl;

    return 0;
}